/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/05 07:26:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	type       ( DFLT_TYPE     ),
	protocol   ( DFLT_PROTOCOL ),
	descriptor ( -1            ) {}

Socket::Socket( int Family, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) :
	family     ( Family   ),
	type       ( Type     ),
	protocol   ( Protocol ),
	descriptor ( -1       ) {}

Socket::Socket( const char * Host, const char * Port = NULL,
	int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) :

	ip_address ( Host     ),
	port       ( Port     ),
	type       ( Type     ),
	protocol   ( Protocol ),
	descriptor ( -1       )
{
	Socket::bind ( ip_address, port , AI_PASSIVE );
}

Socket::Socket( const Socket & src ) {
	*this = src;
}

Socket::~Socket( void ) {
	Socket::close();
}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket &	Socket::operator = ( const Socket & rhs ) {

	if ( this != &rhs ) {

		ip_address   = rhs.ip_address;
		port         = rhs.port;
		family       = rhs.family;
		type         = rhs.type;
		protocol     = rhs.protocol;
		descriptor   = rhs.descriptor;
		address      = rhs.address;
		address_len  = rhs.address_len;
	}
	return ( *this );
}

std::ostream &  operator << ( std::ostream& out, const Socket & in ) {

	out << "<descriptor=" << in.descriptor
	    << ", family="    << in.family
	    << ", type="      << in.type
	    << ", protocol="  << in.protocol
	    << ", laddr=('"   << in.ip_address << "', " << in.port << ")>\n";

	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

Socket &	Socket::socket( int Family ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    #include <sys/types.h>
	    #include <sys/socket.h>

	    int
		socket( int domain, int type, int protocol );

	    (Address) Family:
	        AF_INET             Internet version 4 protocols,
	        AF_INET6            Internet version 6 protocols,

	    Type:
	        SOCK_STREAM         A SOCK_STREAM type provides sequenced,
	                            reliable, two-way connection based byte
	                            streams.

	        SOCK_DGRAM          A SOCK_DGRAM socket supports datagrams
	                            (connectionless, unreliable messages of
	                            a fixed (typically small) maximum length;
	                            (you would use this for UDP).

	        SOCK_RAW            [...] ; See socket(2)

	    Protocol:
	        IPPROTO_IP   --> ip  ; 0  ; IP  ; # internet protocol -- determines automatically
	        IPPROTO_TCP  --> tcp ; 6  ; TCP ; # transmission control protocol
	        IPPROTO_UDP  --> udp ; 17 ; UDP ; # user datagram protocol
	        ...

	    See : socket(2), protocols(5), /etc/protocols

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( descriptor != -1 )
		this->close();

	descriptor = ::socket( Family, type, protocol );
	if ( descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	this->family = Family;

	return ( *this );
}

Socket &	Socket::socket( int Family, int Type, int Protocol ) {

	this->type     = Type;
	this->protocol = Protocol;

	return ( Socket::socket( Family ) );
}

Socket &	Socket::bind( const char * Host, const char * Port,
	int flags = AI_PASSIVE ) {

	/* Bind to an Address and Port - - - - - - - - - - - - - - - - - - - - - - - -

	    #include <sys/types.h>
	    #include <sys/socket.h>

	    int
	    bind( int sockfd, struct sockaddr *my_addr, int addrlen );

	    See : bind(2)
	    ----------------------------------------------------------------

	    struct sockaddr_in   -- see : /usr/include/netinet/in.h    @line 372
	    struct sockaddr_in6  -- see : /usr/include/netinet6/in6.h  @line 164
	    struct addrinfo      -- see : /usr/include/netdb.h         @line 147

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo *head, *cur;
	struct addrinfo hints;
	int ret;

	memset( &hints, 0, sizeof(addrinfo) );

	hints.ai_family   = AF_UNSPEC;  /* Address Family (is unspecified & )
	                                will be determined by the machine
	                                automagically */
	hints.ai_socktype = type;
	hints.ai_protocol = protocol;
	hints.ai_flags    = flags;      /* AI_PASSIVE [...] indicates that
	                                the returned socket address structure
	                                is intended for use in a call to bind(2).
	                                In this case, if the hostname argument
	                                is the null pointer, then the IP address
	                                portion of the socket address structure
	                                will be set to INADDR_ANY for an IPv4
	                                address or IN6ADDR_ANY_INIT for an IPv6
	                                address. */

	ret = getaddrinfo( Host, Port, &hints, &head );

	if ( ret != 0 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ , gai_strerror(ret) );
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	const char *cause = "Nothing returned from getaddrinfo()";
	int sockdes = -1;

	for ( cur = head; cur; cur = cur->ai_next ) {

		sockdes = ::socket( cur->ai_family, cur->ai_socktype, cur->ai_protocol );
		if ( sockdes < 0 ) {
			cause = "Failed to create specified hostname socket";
			continue ;
		}

		ret = ::bind( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret < 0 ) {
			cause = "Failed to bind to specified address/server/port";
			::close(sockdes);
			sockdes = -1;
			continue ;
		}

		break ;
	}

	if ( sockdes < 0 ) {
		freeaddrinfo(head);
		throw SocketError( __FILE__ , __LINE__ , cause );
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	this->family     = cur->ai_family;
	this->type       = cur->ai_socktype;
	this->protocol   = cur->ai_protocol;

	if ( descriptor != -1 )
		this->close();

	this->descriptor = sockdes;

	memmove( &address, head->ai_addr, sizeof(struct sockaddr) );
	address_len = head->ai_addrlen;

	freeaddrinfo(head);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	return ( *this );
}

Socket &	Socket::listen( int connections = 0 ) {

	int ret = ::listen( descriptor , connections );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket &	Socket::connect( const char * Host, const char * Port,
	int Family = AF_UNSPEC, int Flags = AI_DEFAULT ) {

	/* Get information on some hostname/Port - - - - - - - - - - - - - - - - -

	    #include <sys/types.h>
	    #include <sys/socket.h>
	    #include <netdb.h>

	    int
	    getaddrinfo(const char *hostname, const char *servname,
	        const struct addrinfo *hints, struct addrinfo **res);

	    See : getaddrinfo(2)
        ------------------------------------------------------------------

	    struct addrinfo {
	        int        ai_flags;            -- AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
	        int        ai_family;           -- PF_xxx
	        int        ai_socktype;         -- SOCK_xxx
	        int        ai_protocol;         -- 0 or IPPROTO_xxx for IPv4 and IPv6
	        socklen_t  ai_addrlen;          -- length of ai_addr
	        char       ai_canonname;        -- canonical name for hostname
	        struct     sockaddr *ai_addr;   -- binary address
	        struct     addrinfo *ai_next;   -- next structure in linked list
	    };

	    See : /usr/include/netdb.h @line 147

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo hints;
	struct addrinfo *head;
	struct addrinfo *cur;
	int ret;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	memset( &hints, 0, sizeof(hints) );

	hints.ai_family   = Family;
	hints.ai_socktype = type;
	hints.ai_protocol = protocol;
	hints.ai_flags    = Flags;

	ret = getaddrinfo( Host, Port, &hints, &head );
	if ( ret != 0 )
		throw SocketError( __FILE__ , __LINE__, gai_strerror(ret) );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	const char *cause = "Nothing returned from getaddrinfo()";
	int sockdes = -1;

	for ( cur = head; cur; cur = cur->ai_next ) {

		sockdes = ::socket( cur->ai_family, cur->ai_socktype, cur->ai_protocol );
		if ( sockdes < 0 ) {
			cause = "Failed to create specified host socket";
			continue ;
		}

		ret = ::connect( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret < 0 ) {
			cause = "Failed to bind to specified host/port";
			::close(sockdes);
			sockdes = -1;
			continue ;
		}

		break ;
	}

	if ( sockdes < 0 ) {
		freeaddrinfo(head);
		throw SocketError( __FILE__ , __LINE__ , cause );
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	family     = cur->ai_family;
	type       = cur->ai_socktype;
	protocol   = cur->ai_protocol;
	descriptor = sockdes;

	freeaddrinfo(head);

	return ( *this );
}

Socket &	Socket::connect( Socket & peer ) {

	int ret;

	Socket::socket  ( peer.family, peer.type, peer.protocol       );
	ret = ::connect ( descriptor, &peer.address, peer.address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket &	Socket::setsockopt( int level, int option, int value ) {

	int ret = ::setsockopt( descriptor, level, option, &value, sizeof(value) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );
	return ( *this );
}

int			Socket::getsockopt( int option, int level = SOL_SOCKET ) {

	socklen_t len;
	int value;

	int ret = ::getsockopt( descriptor, level, option, &value, &len );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( value );
}

Socket &	Socket::settimeout( double timeout ) {

	/* Set SO_SNDTIMEO & SO_RCVTIMEO socket options : - - - - - - - - - - - -

	    SO_SNDTIMEO is an option to set a timeout value for output operations.
	    It accepts a struct timeval parameter with the number of seconds and
	    microseconds used to limit waits for output operations to complete. If
	    a send operation has blocked for this much time, it returns with a partial
	    count or with the error EWOULDBLOCK if no data were sent.  In the current
	    implementation, this timer is restarted each time additional data are
	    delivered to the protocol, implying that the limit applies to output por-
	    tions ranging in size from the low-water mark to the high-water mark for
	    output.

	    SO_RCVTIMEO is an option to set a timeout value for input operations.
	    It accepts a struct timeval parameter with the number of seconds and
	    microseconds used to limit waits for input operations to complete. In
	    the current implementation, this timer is restarted each time additional
	    data are received by the protocol, and thus the limit is in effect an
	    inactivity timer. If a receive operation has been blocked for this much
	    time without receiving additional data, it returns with a short count
	    or with the error EWOULDBLOCK if no data were received. The struct
	    timeval parameter must represent a positive time interval; otherwise,
	    setsockopt() returns with the error EDOM.

	    See : setsocketopt(2)
        ------------------------------------------------------------------

	    <sys/time.h>

	    struct timeval {
	        long   tv_sec;    -- seconds
	        int    tv_usec;   -- microseconds
	    };

	    See : /usr/include/sys/_types/_timeval.h  @line 34

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct timeval time;
	int ret;

	time.tv_sec  = timeout;
	time.tv_usec = ((timeout - time.tv_sec) * 1000000);

	ret = ::setsockopt( descriptor, SOL_SOCKET, SO_SNDTIMEO, &time, sizeof(time) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	ret = ::setsockopt( descriptor, SOL_SOCKET, SO_RCVTIMEO, &time, sizeof(time) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( *this );
}

double		Socket::gettimeout( void ) const {

	struct timeval time;
	socklen_t timelen;
	int ret;

	timelen = sizeof(time);
	ret = ::getsockopt( descriptor, SOL_SOCKET, SO_SNDTIMEO, &time, &timelen );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( (time.tv_sec + (time.tv_usec / 1000000)) );
}

void		Socket::setblocking( bool flag ) {

	if ( flag && gettimeout() < 1 )
		settimeout(1);
	settimeout(0);
}

Socket		Socket::accept() const {

	// struct sockaddr_storage {
	// 	__uint8_t	ss_len;		/* address length */
	// 	sa_family_t	ss_family;	/* [XSI] address family */
	// 	char			__ss_pad1[_SS_PAD1SIZE];
	// 	__int64_t	__ss_align;	/* force structure storage alignment */
	// 	char			__ss_pad2[_SS_PAD2SIZE];
	// };

	Socket Client( this->family, this->type, this->protocol );

	Client.ip_address  = nullptr;
	Client.port        = nullptr;

	Client.family      = family;
	Client.type        = type;
	Client.protocol    = protocol;

	Client.address_len = sizeof(Client.address);

	Client.descriptor = ::accept( descriptor, &Client.address, &Client.address_len );
	if ( Client.descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( Client );
}

// ssize_t		Socket::send( const void * buffer, size_t length , int flags ) const {

// template <typename T>
// ssize_t		Socket::send( T data , int flags ) const {

// 	size_t len;

// 	bytes = send();

// 	if ( bytes == -1 )
// 		throw SocketError( __FILE__ , __LINE__ );
// }

// ssize_t		Socket::sendto( Socket & receiver, const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = sendto();

// 	if ( bytes == -1 )
// 		throw SocketError( __FILE__ , __LINE__ );
// }

// ssize_t		Socket::recv( const void * buffer, size_t length , int flags ) const {

// template <typename T>
// ssize_t		Socket::recv( T data , int flags ) const {

// 	size_t len;

// 	bytes = recv();

// 	if ( bytes == -1 )
// 		throw SocketError( __FILE__ , __LINE__ );
// }

// ssize_t		Socket::recvfrom( Socket & sender, const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = recvfrom();

// 	if ( bytes == -1 )
// 		throw SocketError( __FILE__ , __LINE__ );
// }

void	Socket::close() {

	if ( descriptor != -1 )
		if ( ::close( descriptor ) == -1 )
			throw SocketError( __FILE__ , __LINE__ );
	descriptor = -1;
}

void	Socket::shutdown ( int how = SHUT_RDWR ) {

	/* Shut down part of a full-duplex connection - - - - - - - - - - - - - - -

	   int   shutdown(int socket, int how);

		'how' can be one of the following flags:

	      - SHUT_RD   (0)  --  further receives will be disallowed
	      - SHUT_WR   (1)  --  further sends will be disallowed
	      - SHUT_RDWR (2)  --  further sends and receives will be disallowed

		  ( 'SHUT_RDWR' is equivalent to a close() )

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	if ( descriptor != -1 )
		if ( ::shutdown( descriptor , how ) == -1 )
			throw SocketError( __FILE__ , __LINE__ );
	descriptor = -1;
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::SocketError( void ) {}

Socket::SocketError::SocketError( const char *File, size_t Line ) :
	file ( File ),
	line ( std::to_string( Line ) ),
	err_msg ( strerror(errno) ) {
}

Socket::SocketError::SocketError( const char *File, size_t Line,
	const char * Error_Message ) :

	file ( File ),
	line ( std::to_string( Line ) ),
	err_msg ( Error_Message ) {
}

Socket::SocketError::~SocketError( void ) {}

const char *Socket::SocketError::what() const throw() {

	return (
		std::string("~ " + file + ":" + line + " -- Socket Error : "
		+ err_msg + " ~").c_str()
	);
}
