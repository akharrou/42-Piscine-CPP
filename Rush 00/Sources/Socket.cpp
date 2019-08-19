/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/17 14:10:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	_ip_address ( "unknown"     ),
	_port       ( "unknown"     ),
	_family     ( -1            ),
	_type       ( DFLT_TYPE     ),
	_protocol   ( DFLT_PROTOCOL ),
	_descriptor ( -1            ) {}

Socket::Socket( int Family, int Type, int Protocol ) :
	_ip_address ( "unknown" ),
	_port       ( "unknown" ),
	_family     ( Family    ),
	_type       ( Type      ),
	_protocol   ( Protocol  ),
	_descriptor ( -1        )
{
	if ( _type == SOCK_DGRAM )
		Socket::socket( _family );
}

Socket::Socket( const char * Host, const char * Port,
	int Type, int Protocol ) :

	_ip_address ( Host     ),
	_port       ( Port     ),
	_type       ( Type     ),
	_protocol   ( Protocol ),
	_descriptor ( -1       )
{
	Socket::bind ( _ip_address.c_str(), _port.c_str() , AI_PASSIVE );
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

		_ip_address   = rhs._ip_address;
		_port         = rhs._port;
		_family       = rhs._family;
		_type         = rhs._type;
		_protocol     = rhs._protocol;
		_descriptor   = rhs._descriptor;
		_address      = rhs._address;
		_address_len  = rhs._address_len;
	}
	return ( *this );
}

struct { int id; char const *name; }
	g_sockinfo_map[] =
{
	{ AF_INET     , "AF_INET"     },
	{ AF_INET6    , "AF_INET6"    },
	{ AF_UNSPEC   , "AF_UNSPEC"   },
	\
	{ SOCK_STREAM , "SOCK_STREAM" },
	{ SOCK_DGRAM  , "SOCK_DGRAM"  },
	{ SOCK_RAW    , "SOCK_RAW"    },
	\
	{ IPPROTO_IP  , "IP"          },
	{ IPPROTO_TCP , "TCP"         },
	{ IPPROTO_UDP , "UDP"         }
};

std::ostream &  operator << ( std::ostream & out, const Socket & in ) {

	int i = 0;

	out << "<descriptor=" << in.fileno();

	out << ", family=";
	for ( ; i < 3 ; ++i ) {
		if ( g_sockinfo_map[i].id == in.getFamily() ) {
			out << g_sockinfo_map[i].name;
			break ;
		}
	} if ( i == 3 )
		out << "unknown";
	else
		i = 3;

	out << ", type=";
	for ( ; i < 6 ; ++i ) {
		if ( g_sockinfo_map[i].id == in.getType() ) {
			out << g_sockinfo_map[i].name;
			break ;
		}
	} if ( i == 6 )
		out << "unknown";
	else
		i = 6;

	out << ", protocol=";
	for ( ; i < 9 ; ++i ) {
		if ( g_sockinfo_map[i].id == in.getProtocol() ) {
			out << g_sockinfo_map[i].name;
			break ;
		}
	} if ( i == 9 )
		out << "unknown";

	out << ", laddr=('" << in.getIp() << "', " << in.getPort() << ")>\n";

	return ( out );
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         PUBLIC MEMBER FUNCTION(S)                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/* STATICS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int			Socket::fileno ( void ) const {
	return ( _descriptor );
}

int			Socket::getFamily ( void ) const {
	return ( _family );
}

int			Socket::getType ( void ) const {
	return ( _type );
}

int			Socket::getProtocol ( void ) const {
	return ( _protocol );
}

std::string	Socket::getIp ( void ) const {
	return ( _ip_address );
}

std::string	Socket::getPort ( void ) const {
	return ( _port );
}

Socket &	Socket::setsockopt( int level, int option, int value ) {

	int ret = ::setsockopt( _descriptor, level, option, &value, sizeof(value) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );
	return ( *this );
}

int			Socket::getsockopt( int option, int level = SOL_SOCKET ) const {

	socklen_t len;
	int value;

	int ret = ::getsockopt( _descriptor, level, option, &value, &len );
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
	    delivered to the _protocol, implying that the limit applies to output por-
	    tions ranging in size from the low-water mark to the high-water mark for
	    output.

	    SO_RCVTIMEO is an option to set a timeout value for input operations.
	    It accepts a struct timeval parameter with the number of seconds and
	    microseconds used to limit waits for input operations to complete. In
	    the current implementation, this timer is restarted each time additional
	    data are received by the _protocol, and thus the limit is in effect an
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

	ret = ::setsockopt( _descriptor, SOL_SOCKET, SO_SNDTIMEO, &time, sizeof(time) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	ret = ::setsockopt( _descriptor, SOL_SOCKET, SO_RCVTIMEO, &time, sizeof(time) );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( *this );
}

double		Socket::gettimeout( void ) const {

	struct timeval time;
	socklen_t timelen;
	int ret;

	timelen = sizeof(time);
	ret = ::getsockopt( _descriptor, SOL_SOCKET, SO_SNDTIMEO, &time, &timelen );
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
	    struct     sockaddr *ai_addr;  // binary _address
	    struct     addrinfo *ai_next;  // next structure in linked list
	};

	struct sockaddr {
	   unsigned short    sa_family;    // _address _family, AF_xxx
	   char              sa_data[14];  // 14 bytes of _protocol _address
	};

	struct sockaddr_in {
	    short            sin_family;   // e.g. AF_INET, AF_INET6
	    unsigned short   sin_port;     // e.g. htons(3490)
	    struct in_addr   sin_addr;     // see struct in_addr, below
	    char             sin_zero[8];  // zero this if you want to
	};

	struct sockaddr_in6 {
	    u_int16_t       sin6_family;   // _address _family, AF_INET6
	    u_int16_t       sin6_port;     // _port number, Network Byte Order
	    u_int32_t       sin6_flowinfo; // IPv6 flow information
	    struct in6_addr sin6_addr;     // IPv6 _address
	    u_int32_t       sin6_scope_id; // Scope ID
	};

	struct sockaddr_storage {
	    sa_family_t  ss_family;        // _address _family

	    // all this is padding, implementation specific, ignore it:
	    char      __ss_pad1[_SS_PAD1SIZE];
	    int64_t   __ss_align;
	    char      __ss_pad2[_SS_PAD2SIZE];
	};

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo hints;
	struct addrinfo * head;
	int ret;

	memset( &hints, 0, sizeof( hints ) );

	hints.ai_family   = Family;     /* AF_UNSPEC indicates that the _address
	                                _family (is unspecified & ) will be
	                                determined by the machine automagically */
	hints.ai_socktype = Type;
	hints.ai_protocol = Protocol;
	hints.ai_flags    = Flags;

	ret = ::getaddrinfo( Host , Port , &hints , &head );

	if ( ret != 0 )
		throw SocketError( __FILE__ , __LINE__ , gai_strerror(ret) );

	return ( head );
}

std::string	Socket::getip( struct sockaddr_storage _address ) {

	union {
		struct sockaddr_in *v4;
		struct sockaddr_in6 *v6;
	} sockaddr;

	char dest [ INET6_ADDRSTRLEN ];

	switch ( _address.ss_family ) {

		case AF_INET:

			sockaddr.v4 = reinterpret_cast <sockaddr_in *> ( &_address );
			::inet_ntop( AF_INET , reinterpret_cast <void *> ( sockaddr.v4 ) ,
				dest , INET6_ADDRSTRLEN );

			break ;

		case AF_INET6:

			sockaddr.v6 = reinterpret_cast <sockaddr_in6 *> ( &_address );
			::inet_ntop( AF_INET6 , reinterpret_cast <void *> ( sockaddr.v6 ) ,
				dest , INET6_ADDRSTRLEN );

			break ;

		default:

			strlcpy( dest, "unknown" , INET6_ADDRSTRLEN );
			break ;

	}
	return ( dest );
}

std::string Socket::getport( struct sockaddr_storage _address ) {

	std::string _port;

	switch ( _address.ss_family ) {

		case AF_INET:

			_port = std::to_string (
				ntohs( ( reinterpret_cast <struct sockaddr_in *> (
					&_address))->sin_port ) );

			break ;

		case AF_INET6:

			_port = std::to_string (
				ntohs( ( reinterpret_cast <struct sockaddr_in6 *> (
					&_address))->sin6_port ) );

			break ;

		default:

			_port = "unknown";
			break ;

	}
	return ( _port );
}


/* OPERATIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket &	Socket::socket( int Family ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    #include <sys/types.h>
	    #include <sys/socket.h>

	    int
		socket( int domain, int _type, int _protocol );

	    (Address) Family:
	        AF_INET             Internet version 4 protocols,
	        AF_INET6            Internet version 6 protocols,

	    Type:
	        SOCK_STREAM         A SOCK_STREAM _type provides sequenced,
	                            reliable, two-way connection based byte
	                            streams.

	        SOCK_DGRAM          A SOCK_DGRAM socket supports datagrams
	                            (connectionless, unreliable messages of
	                            a fixed (typically small) maximum length;
	                            (you would use this for UDP).

	        SOCK_RAW            [...] ; See socket(2)

	    Protocol:
	        IPPROTO_IP  -> ip  ; 0  ; IP  ; # internet _protocol (auto-determined)
	        IPPROTO_TCP -> tcp ; 6  ; TCP ; # transmission control _protocol
	        IPPROTO_UDP -> udp ; 17 ; UDP ; # user datagram _protocol
	        ...

	    See : socket(2), protocols(5), /etc/protocols

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( _descriptor != -1 )
		this->close();

	_descriptor = ::socket( Family, _type, _protocol );
	if ( _descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	this->_family = Family;

	return ( *this );
}

Socket &	Socket::socket( int Family, int Type, int Protocol ) {

	this->_type     = Type;
	this->_protocol = Protocol;

	return ( Socket::socket( Family ) );
}

Socket &	Socket::bind( const char * Host, const char * Port,
	int flags ) {

	/* Bind to an Address and Port - - - - - - - - - - - - - - - - - - - - - - - -

	#include <sys/types.h>
	#include <sys/socket.h>

	int
	bind( int sockfd, struct sockaddr *my_addr, int addrlen );

	See : bind(2)
	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	AI_PASSIVE [...] indicates that the returned socket _address structure
	is intended for use in a call to bind(2). In this case, if the hostname argument
	is the null pointer, then the IP _address portion of the socket _address structure
	will be set to INADDR_ANY for an IPv4 _address or IN6ADDR_ANY_INIT for an IPv6
	_address.

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	struct addrinfo * head;
	struct addrinfo * cur;
	int ret;

	try {

		head = Socket::getaddrinfo( Host , Port , AF_UNSPEC , _type , _protocol ,
		                            flags );

	} catch ( SocketError & e ) {

		freeaddrinfo(head);
		throw e;

	} catch ( std::exception & e ) {

		freeaddrinfo(head);
		throw e;

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::string cause = "Nothing returned from getaddrinfo()";
	int sockdes = -1;

	for ( cur = head; cur; cur = cur->ai_next ) {

		sockdes = ::socket( cur->ai_family, cur->ai_socktype, cur->ai_protocol );
		if ( sockdes < 0 ) {
			cause = "Socket : " + std::string( strerror( errno ) );
			continue ;
		}

		ret = ::bind( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret < 0 ) {
			cause = "Bind : " + std::string( strerror( errno ) );
			::close(sockdes);
			sockdes = -1;
			continue ;
		}

		break ;
	}

	if ( sockdes < 0 ) {
		freeaddrinfo(head);
		throw SocketError( __FILE__ , __LINE__ , cause.c_str() );
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( _ip_address == "unknown" )
		this->_ip_address = Host;

	if ( _port == "unknown" )
		this->_port = Port;

	this->_family     = cur->ai_family;
	this->_type       = cur->ai_socktype;
	this->_protocol   = cur->ai_protocol;

	if ( _descriptor != -1 )
		this->close();
	this->_descriptor = sockdes;

	_address_len = head->ai_addrlen;
	memmove( reinterpret_cast <struct sockaddr *> (&_address),
	         head->ai_addr,
			 sizeof(_address) );

	freeaddrinfo(head);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	return ( *this );
}

Socket &	Socket::listen( int connections ) {

	int ret = ::listen( _descriptor , connections );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket &	Socket::connect( const char * Host, const char * Port,
	int Family, int Flags ) {

	/* Get information on some hostname/Port - - - - - - - - - - - - - - - - -

	    #include <sys/types.h>
	    #include <sys/socket.h>
	    #include <netdb.h>

	    int
	    getaddrinfo(const char *hostname, const char *servname,
	        const struct addrinfo *hints, struct addrinfo **res);

	    See : getaddrinfo(2)

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* FIXME : make it handle blocking & non-blocking sockets correctly */

	struct addrinfo * head;
	struct addrinfo * cur;
	int ret;

	try {

		head = Socket::getaddrinfo( Host , Port , Family , _type , _protocol ,
		                            Flags );

	} catch ( SocketError & e ) {

		freeaddrinfo(head);
		throw e;

	} catch ( std::exception & e ) {

		freeaddrinfo(head);
		throw e;

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::string cause = "Nothing returned from getaddrinfo()";
	int sockdes = -1;

	for ( cur = head; cur; cur = cur->ai_next ) {

		sockdes = ::socket( cur->ai_family, cur->ai_socktype, cur->ai_protocol );
		if ( sockdes < 0 ) {
			cause = "Socket : " + std::string( strerror( errno ) );
			continue ;
		}

		ret = ::connect( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret < 0 ) {
			cause = "Connect : " + std::string( strerror( errno ) );
			::close(sockdes);
			sockdes = -1;
			continue ;
		}

		break ;
	}

	if ( sockdes < 0 ) {
		freeaddrinfo(head);
		throw SocketError( __FILE__ , __LINE__ , cause.c_str() );
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	_family     = cur->ai_family;
	_type       = cur->ai_socktype;
	_protocol   = cur->ai_protocol;

	if ( this->_descriptor != -1 )
		Socket::close( this->_descriptor );
	this->_descriptor = sockdes;

	freeaddrinfo(head);

	return ( *this );
}

Socket &	Socket::connect( Socket & peer ) {

	int ret;

	Socket::socket  ( peer._family, peer._type, peer._protocol );
	ret = ::connect ( _descriptor,
	                  reinterpret_cast <struct sockaddr *> ( &peer._address ),
	                  peer._address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}

	_ip_address  = Socket::getip   ( _address );
	_port        = Socket::getport ( _address );

	return ( *this );
}

int			Socket::accept( Socket & newClient ) const {

	int res;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	newClient._address_len = sizeof( newClient._address );

	newClient._descriptor = ::accept( _descriptor,
		reinterpret_cast <struct sockaddr *> ( &newClient._address ),
		&newClient._address_len );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( newClient._descriptor < 0 ) {

		if ( errno == EWOULDBLOCK || errno == EAGAIN ) {

			/* "[EWOULDBLOCK] -- socket is marked as non-blocking and no
			connections are present to be accepted." ; See accept(2)

			We also check 'EAGAIN' for portability but its the same as
			'EWOULDBLOCK'. */

			res = ( -1 );

		} else {

			/* 0 shall indicate that something went completely wrong with
			Socket::accept() */

			res = ( 0 );
		}

		errno = 0;

	} else {

		res = ( 1 );

		newClient._ip_address  = Socket::getip   ( newClient._address );
		newClient._port        = Socket::getport ( newClient._address );
	}

	return ( res );
}

Socket		Socket::accept( bool && res ) const {

	Socket Client ( this->_family, this->_type, this->_protocol );

	res = Socket::accept( Client );

	return ( Client );
}

void		Socket::shutdown ( int sockfd, int how ) {

	/* Shut down part of a full-duplex connection - - - - - - - - - - - - - - -

	   int   shutdown(int socket, int how);

		'how' can be one of the following flags:

	      - SHUT_RD   (0)  --  further receives will be disallowed
	      - SHUT_WR   (1)  --  further sends will be disallowed
	      - SHUT_RDWR (2)  --  further sends and receives will be disallowed

		  ( 'SHUT_RDWR' is equivalent to a close() )

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( sockfd != -1 ) {
		if ( ::shutdown( sockfd , how ) == -1 )
			throw SocketError( __FILE__ , __LINE__ );
		sockfd = -1;
	}
}

void		Socket::close( int sockfd )
{
	if ( sockfd != -1 ) {
		if ( ::close( sockfd ) == -1 )
			throw SocketError( __FILE__ , __LINE__ );
		sockfd = -1;
	}
}

void		Socket::close( void )
{
	Socket::close( _descriptor );
}

/* I/O OPERATONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ssize_t		Socket::send( int sockfd, std::string & data,
	size_t length , int flags )
{
	ssize_t bytes_sent;

	bytes_sent = ::send( sockfd,
		reinterpret_cast <const void *> ( data.substr( 0 , length ).c_str() ),
		length , flags );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		std::string remaining_data;

		length -= static_cast <size_t> ( bytes_sent );
		remaining_data = data.substr( bytes_sent , length );

		bytes_sent +=
			Socket::send ( sockfd , remaining_data, length, flags );

	}

	return ( bytes_sent );
}

ssize_t		Socket::send( std::string & data,
	size_t length , int flags )
{
	return ( Socket::send ( _descriptor , data , length , flags ) );
}

ssize_t		Socket::send( Socket & receiver, std::string & data,
	size_t length , int flags )
{
	return ( Socket::send ( receiver._descriptor , data , length , flags ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ssize_t		Socket::sendto ( std::string & data,
	struct sockaddr_storage *dest_addr, socklen_t & dest_len,
	size_t length, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = ::sendto( _descriptor,
		reinterpret_cast <const void *> ( data.substr( 0 , length ).c_str() ),
		length , flags, reinterpret_cast <struct sockaddr *> ( dest_addr ),
		dest_len );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		std::string remaining_data;

		length -= static_cast <size_t> ( bytes_sent );
		remaining_data = data.substr( bytes_sent , length );

		bytes_sent +=
			Socket::sendto ( remaining_data, dest_addr, dest_len,  length, flags );

	}

	return ( bytes_sent );
}

ssize_t		Socket::sendto( const char * Host, const char * Port,
	std::string & data, size_t length, int flags )
{
	struct addrinfo * head;
	struct addrinfo * cur;

	ssize_t bytes_sent = 0;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	try {

		head = Socket::getaddrinfo( Host , Port , _family , _type , _protocol );

	} catch ( SocketError & e ) {

		freeaddrinfo( head );
		throw e;

	} catch ( std::exception & e ) {

		freeaddrinfo( head );
		throw e;

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	for ( cur = head; cur; cur = cur->ai_next ) {

		try {

			bytes_sent = Socket::sendto( data ,
					reinterpret_cast <sockaddr_storage *> ( cur->ai_addr ) ,
					cur->ai_addrlen, length , flags );

		} catch ( SocketError & e ) {

			if ( errno == EHOSTUNREACH ) {

				errno = 0;
				continue ;
			}

			freeaddrinfo( head );
			throw e;

		} catch ( std::exception & e ) {

			freeaddrinfo( head );
			throw e;

		}
	}

	freeaddrinfo( head );

	return ( bytes_sent );
}

ssize_t		Socket::sendto( Socket & receiver, std::string & data, size_t length,
	int flags )
{
	return (
		Socket::sendto ( data , &receiver._address , receiver._address_len ,
			length , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ssize_t		Socket::recv_into( int sockfd, std::string & buffer,
	size_t length, int flags )
{
	ssize_t bytes_recvd;
	char * tmp = new char [ length ];

	bytes_recvd = ::recv ( sockfd , reinterpret_cast <void *> ( tmp ) ,
	                       length , flags );

	if ( bytes_recvd < 0 ) {

		delete [] tmp;

		if ( errno == ECONNRESET ) {

			/* "[ECONNRESET] -- The connection is closed by the peer during a
			receive attempt on a socket." ; See recv(2) */

			/* for TCP sockets; 0 shall be the signal to indicate that the
			peer socket disconnected ; this signal can also be returned
			if 'recv' returns 0 */

			errno = 0;
			return ( 0 );

		} else if ( errno == EAGAIN || errno == EWOULDBLOCK ) {

			/* "[EAGAIN] -- The socket is marked non-blocking, and the receive
			operation would block, or a receive timeout had been set, and the
			timeout expired before data were received." ; See recv(2) */

			/* for non-blocking / timeout bound sockets; -1 shall be the
			signal to indicate that the socket currently holds no data (but
			that the connection is still live and on-going ) */

			/* We also check 'EWOULDBLOCK' for portability but its the same
			as 'EAGAIN'. */

			errno = 0;
			return ( -1 );

		} else {

			/* 'sockfd' won't be closed; it will be up to the caller to check
			the error corresponding to 'errno' and take action(s) accordingly. */

			throw SocketError( __FILE__ , __LINE__ );
		}
	}

	buffer = tmp;
	delete [] tmp;

	return ( bytes_recvd );
}

ssize_t		Socket::recv_into( std::string & buffer, size_t length,
	int flags )
{
	return ( Socket::recv_into ( _descriptor , buffer , length , flags ) );
}

ssize_t     Socket::recv_into( Socket & sender, std::string & buffer,
	size_t length, int flags )
{
	return ( Socket::recv_into ( sender._descriptor , buffer , length , flags ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ssize_t		Socket::recvfrom_into( std::string & buffer, size_t length,
	struct sockaddr_storage *dest_addr, socklen_t && dest_len, int flags )
{
	ssize_t bytes_recvd;
	char * tmp = new char [ length ];

	bytes_recvd = ::recvfrom ( _descriptor ,
	                           reinterpret_cast <void *> ( tmp ) ,
	                           length , flags ,
	                           reinterpret_cast <sockaddr *> ( dest_addr ) ,
	                           &dest_len );

	/* FIXME : make it keep receiving until length are received from the
	           socket */

	if ( bytes_recvd < 0 ) {

		delete [] tmp;

		if ( errno == EAGAIN || errno == EWOULDBLOCK ) {

			/* "[EAGAIN] -- The socket is marked non-blocking, and the receive
			operation would block, or a receive timeout had been set, and the
			timeout expired before data were received." ; See recv(2) */

			/* for non-blocking / timeout bound sockets; -1 shall be the
			signal to indicate that the socket currently holds no data (but
			that the connection is still live and on-going ) */

			/* We also check 'EWOULDBLOCK' for portability but its the same
			as 'EAGAIN'. */

			errno = 0;
			return ( -1 );

		} else {

			/* 'sockfd' won't be closed; it will be up to the caller to check
			the error corresponding to 'errno' and take action(s) accordingly. */

			throw SocketError( __FILE__ , __LINE__ );
		}
	}

	buffer = tmp;
	delete [] tmp;

	return ( bytes_recvd );
}

ssize_t		Socket::recvfrom_into ( Socket & sender, std::string & buffer,
	size_t length, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = Socket::recvfrom_into ( buffer , length , &sender._address ,
		static_cast <socklen_t> ( sender._address_len ) , flags );

	sender._ip_address = Socket::getip   ( sender._address );
	sender._port       = Socket::getport ( sender._address );

	return ( bytes_sent );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string	Socket::recvfrom ( size_t length,
	struct sockaddr_storage *dest_addr, socklen_t && dest_len,
	ssize_t *&& bytes_recvd, int flags )
{
	std::string data;
	ssize_t res;

	res = Socket::recvfrom_into( data , length , dest_addr ,
		static_cast <socklen_t> ( dest_len ) , flags );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

std::string	Socket::recvfrom ( Socket & sender, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	return (
		Socket::recvfrom( length , &sender._address ,
			static_cast <socklen_t> ( sender._address_len ) ,
			static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string	Socket::recv ( int sockfd, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	std::string data;
	ssize_t res;

	res = Socket::recv_into( sockfd , data , length , flags );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

std::string	Socket::recv ( size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	return (
		Socket::recv ( _descriptor , length ,
			static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

std::string	Socket::recv ( Socket & sender, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	return (
		Socket::recv ( sender._descriptor , length ,
			static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::SocketError( void ) {}

Socket::SocketError::SocketError( const char *File, size_t Line ) :
	_file ( File ),
	_line ( std::to_string( Line ) ),
	_err_msg ( strerror( errno ) ) {
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

Socket::SocketError::~SocketError( void ) {}

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

const char * Socket::SocketError::what() const noexcept {

	return (
		std::string("~ " + _file + ":" + _line + " -- Socket Error : "
		+ _err_msg + " ~").c_str()
	);
}


