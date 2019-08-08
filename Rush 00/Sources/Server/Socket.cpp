/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/07 19:04:35 by akharrou         ###   ########.fr       */
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

Socket::Socket( const Socket & src )
{
	*this = src;
}

Socket::~Socket( void )
{
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


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         PUBLIC MEMBER FUNCTION(S)                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/* STATICS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct addrinfo * Socket::getaddrinfo( const char * Host, const char * Port ,
	int Family, int Type, int Protocol, int Flags )
{

	/* Address Information Structures - - - - - - - - - - - - - - - - - - - - - -

	struct addrinfo          -- see : /usr/include/netdb.h         @line 147
	struct sockaddr          -- see : /usr/include/sys/socket.h    @line 401
	struct sockaddr_in       -- see : /usr/include/netinet/in.h    @line 372
	struct sockaddr_in6      -- see : /usr/include/netinet6/in6.h  @line 164
	struct sockaddr_storage  -- see : /usr/include/sys/socket.h    @line 434

	------------------------------------------------------------------------------

	struct addrinfo {
	    int        ai_flags;           // AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
	    int        ai_family;          // PF_xxx
	    int        ai_socktype;        // SOCK_xxx
	    int        ai_protocol;        // 0 or IPPROTO_xxx for IPv4 and IPv6
	    socklen_t  ai_addrlen;         // length of ai_addr
	    char       ai_canonname;       // canonical name for hostname
	    struct     sockaddr *ai_addr;  // binary address
	    struct     addrinfo *ai_next;  // next structure in linked list
	};

	struct sockaddr {
	   unsigned short    sa_family;    // address family, AF_xxx
	   char              sa_data[14];  // 14 bytes of protocol address
	};

	struct sockaddr_in {
	    short            sin_family;   // e.g. AF_INET, AF_INET6
	    unsigned short   sin_port;     // e.g. htons(3490)
	    struct in_addr   sin_addr;     // see struct in_addr, below
	    char             sin_zero[8];  // zero this if you want to
	};

	struct sockaddr_in6 {
	    u_int16_t       sin6_family;   // address family, AF_INET6
	    u_int16_t       sin6_port;     // port number, Network Byte Order
	    u_int32_t       sin6_flowinfo; // IPv6 flow information
	    struct in6_addr sin6_addr;     // IPv6 address
	    u_int32_t       sin6_scope_id; // Scope ID
	};

	struct sockaddr_storage {
	    sa_family_t  ss_family;        // address family

	    // all this is padding, implementation specific, ignore it:
	    char      __ss_pad1[_SS_PAD1SIZE];
	    int64_t   __ss_align;
	    char      __ss_pad2[_SS_PAD2SIZE];
	};

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo * head;
	struct addrinfo hints;
	int ret;

	memset( &hints, 0, sizeof(addrinfo) );

	hints.ai_family   = Family;     /* AF_UNSPEC indicates that the address
	                                family (is unspecified & ) will be
	                                determined by the machine automagically */
	hints.ai_socktype = Type;
	hints.ai_protocol = Protocol;
	hints.ai_flags    = Flags;

	ret = ::getaddrinfo( Host , Port , &hints , &head );

	if ( ret != 0 )
		throw Socket::SocketError( __FILE__ , __LINE__ , gai_strerror(ret) );

	return ( head );
}

std::string Socket::getip( struct sockaddr_storage address ) {

	union {
		struct sockaddr_in *v4;
		struct sockaddr_in6 *v6;
	} sockaddr;

	char dest [ INET6_ADDRSTRLEN ];

	switch ( address.ss_family ) {

		case AF_INET:

			sockaddr.v4 = reinterpret_cast <sockaddr_in *> ( &address );
			::inet_ntop( AF_INET , reinterpret_cast <void *> ( sockaddr.v4 ) ,
				dest , INET6_ADDRSTRLEN );

			break ;

		case AF_INET6:

			sockaddr.v6 = reinterpret_cast <sockaddr_in6 *> ( &address );
			::inet_ntop( AF_INET6 , reinterpret_cast <void *> ( sockaddr.v6 ) ,
				dest , INET6_ADDRSTRLEN );

			break ;

	}
	return ( dest );
}

std::string Socket::getport( struct sockaddr_storage address ) {

	unsigned short port;

	switch ( address.ss_family ) {

		case AF_INET:

			port = ntohs( (reinterpret_cast <struct sockaddr_in *> (
				&address))->sin_port );

			break ;

		case AF_INET6:

			port = ntohs( (reinterpret_cast <struct sockaddr_in6 *> (
				&address))->sin6_port );

			break ;

	}
	return ( std::to_string ( port ) );
}


/* OPTIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket &	Socket::setsockopt( int level, int option, int value ) {

	int ret = ::setsockopt( descriptor, level, option, &value, sizeof(value) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );
	return ( *this );
}

int			Socket::getsockopt( int option, int level = SOL_SOCKET ) const {

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

Socket &	Socket::setblocking( bool flag ) {

	if ( flag ) {
		if ( gettimeout() < 1 )
			settimeout(1);
	} else
		settimeout(0);

	return ( *this );
}

/* OPERATIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

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
	        IPPROTO_IP  -> ip  ; 0  ; IP  ; # internet protocol (auto-determined)
	        IPPROTO_TCP -> tcp ; 6  ; TCP ; # transmission control protocol
	        IPPROTO_UDP -> udp ; 17 ; UDP ; # user datagram protocol
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
	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	AI_PASSIVE [...] indicates that the returned socket address structure
	is intended for use in a call to bind(2). In this case, if the hostname argument
	is the null pointer, then the IP address portion of the socket address structure
	will be set to INADDR_ANY for an IPv4 address or IN6ADDR_ANY_INIT for an IPv6
	address.

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo * head;
	struct addrinfo * cur;
	int ret;

	try {

		head = Socket::getaddrinfo( Host , Port , AF_UNSPEC , type , protocol ,
		                            flags );

	} catch ( std::exception & e ) {
		freeaddrinfo(head);
		throw e;
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

	address_len = head->ai_addrlen;
	memmove( reinterpret_cast <struct sockaddr *> (&address),
	         head->ai_addr,
			 sizeof(address) );

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

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo * head;
	struct addrinfo * cur;
	int ret;

	try {

		head = Socket::getaddrinfo( Host , Port , Family , type , protocol ,
		                            Flags );

	} catch ( std::exception & e ) {
		freeaddrinfo(head);
		throw e;
	}

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
	ret = ::connect ( descriptor,
	                  reinterpret_cast <struct sockaddr *> (&peer.address),
	                  peer.address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket		Socket::accept( void ) const {

	Socket Client( this->family, this->type, this->protocol );

	Client.ip_address  = nullptr;
	Client.port        = nullptr;

	Client.address_len = sizeof( Client.address );

	Client.descriptor =
		::accept( descriptor,
		          reinterpret_cast <struct sockaddr *> ( &Client.address ),
		          &Client.address_len );

	if ( Client.descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( Client );
}

void		Socket::shutdown ( int sockfd, int how = SHUT_RDWR ) {

	/* Shut down part of a full-duplex connection - - - - - - - - - - - - - - -

	   int   shutdown(int socket, int how);

		'how' can be one of the following flags:

	      - SHUT_RD   (0)  --  further receives will be disallowed
	      - SHUT_WR   (1)  --  further sends will be disallowed
	      - SHUT_RDWR (2)  --  further sends and receives will be disallowed

		  ( 'SHUT_RDWR' is equivalent to a close() )

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( sockfd != -1 )
		if ( ::shutdown( sockfd , how ) == -1 )
			throw SocketError( __FILE__ , __LINE__ );
	sockfd = -1;
}

void		Socket::close( int sockfd )
{
	Socket::shutdown( sockfd );
}

void		Socket::close( void )
{
	Socket::close( descriptor );
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::SocketError( void ) noexcept {}

Socket::SocketError::SocketError( const char *File, size_t Line ) :
	_file ( File ),
	_line ( std::to_string( Line ) ),
	_err_msg ( strerror(errno) ) {
}

Socket::SocketError::SocketError( const char *File, size_t Line,
	const char * Error_Message ) :

	_file ( File ),
	_line ( std::to_string( Line ) ),
	_err_msg ( Error_Message ) {
}

Socket::SocketError::SocketError(
	const SocketError & src )
{
	*this = src;
}

Socket::SocketError::~SocketError( void ) noexcept {}

Socket::SocketError &	Socket::SocketError::operator = (
	const SocketError & rhs )
{
	if ( this != &rhs ) {

		_file    = rhs._file;
		_line    = rhs._line;
		_err_msg = rhs._err_msg;
	}
	return ( *this );
}

std::string	Socket::SocketError::getError( void ) const {
	return ( _err_msg );
}

const char * Socket::SocketError::what( void ) const noexcept {

	return (
		std::string("~ " + _file + ":" + _line + " -- Socket Error : "
		+ _err_msg + " ~").c_str()
	);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketPeerDisconnect::SocketPeerDisconnect() noexcept :
	_sockfd ( -1 ) {}

Socket::SocketPeerDisconnect::SocketPeerDisconnect( int fd ) :
	_sockfd ( fd ) {}

Socket::SocketPeerDisconnect::SocketPeerDisconnect(
	const SocketPeerDisconnect & src )
{
	*this = src;
}

Socket::SocketPeerDisconnect::~SocketPeerDisconnect( void ) noexcept {}

Socket::SocketPeerDisconnect &
	Socket::SocketPeerDisconnect::operator = (
		const SocketPeerDisconnect & rhs )
{
	if ( this != &rhs )
		_sockfd = rhs._sockfd;
	return ( *this );
}

int Socket::SocketPeerDisconnect::getSockfd( void ) const {
	return ( _sockfd );
}

const char * Socket::SocketPeerDisconnect::what( void ) const noexcept {

	return (
		std::string(
			"~ SocketDisconnect : Peer of socket # " +
			std::to_string(_sockfd) +
			"Disconnected ~"
		).c_str()
	);
}
