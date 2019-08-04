/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/03 22:47:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	family     ( DFLT_FAMILY ),
	type       ( DFLT_TYPE   ),
	protocol   ( DFLT_PROTOCOL ) {}

Socket::Socket( int Family, int Type, int Protocol ) :
	family     ( Family     ),
	type       ( Type       ),
	protocol   ( Protocol   ) {}

Socket::Socket( std::string IP_Address, int Port,
	int Family = DFLT_FAMILY, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) :

	ip_address ( IP_Address ),
	port       ( Port       ),
	family     ( Family     ),
	type       ( Type       ),
	protocol   ( Protocol   )
{
	Socket::socket ( family, type, protocol );
	Socket::bind   ( ip_address, port       );
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

Socket &	Socket::socket( int Family = DFLT_FAMILY,
				int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    int   socket(int family, int type, int protocol);

	    Family:
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
	        IPPROTO_IP   --> ip  ; 0  ; IP  ; # internet protocol, pseudo protocol number
	        IPPROTO_TCP  --> tcp ; 6  ; TCP ; # transmission control protocol
	        IPPROTO_UDP  --> udp ; 17 ; UDP ; # user datagram protocol
	        ...

	    See : socket(2), protocols(5), /etc/protocols

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	descriptor = ::socket( Family, Type, Protocol );
	if ( descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( *this );
}

Socket &	Socket::bind( std::string IP_Address, int Port ) {

	/* Bind to an Address and Port - - - - - - - - - - - - - - - - - - - - - - - -

	    struct sockaddr_in  :
	    ----------------------

            struct sockaddr_in {
                __uint8_t        sin_len;
                sa_family_t      sin_family;
                in_port_t        sin_port;
                struct           in_addr sin_addr;
                char             sin_zero[8];
            };

	    struct sockaddr_in6 :
		----------------------

            struct sockaddr_in6 {
                __uint8_t        sin6_len;        -- length of this struct(sa_family_t)
                sa_family_t      sin6_family;     -- AF_INET6 (sa_family_t)
                in_port_t        sin6_port;       -- Transport layer port # (in_port_t)
                __uint32_t       sin6_flowinfo;   -- IP6 flow information
                struct in6_addr  sin6_addr;       -- IP6 address
                __uint32_t       sin6_scope_id;   -- scope zone index
            };

	    See : bind(2)
		See : /usr/include/netinet/in.h   @line 372
		See : /usr/include/netinet6/in6.h @line 164

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	int ret;

	memset( &_saddr_in, 0, sizeof(_saddr_in) );

	switch( family )
	{

		/* IPv4 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – */
		case AF_INET:

			_saddr_in.v4.sin_family = family;
			// _saddr_in.v4.sin_len    = sizeof(family);
			_saddr_in.v4.sin_port   = htons(Port);

			ret = inet_pton ( AF_INET  , IP_Address.c_str(), &_saddr_in.v4.sin_addr  );

			address     = reinterpret_cast <struct sockaddr *> (&_saddr_in.v4);
			address_len = sizeof(_saddr_in.v4);

			break;

		/* IPv6 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – */
		case AF_INET6:

			_saddr_in.v6.sin6_family = family;
			// _saddr_in.v6.sin6_len    = sizeof(family);
			_saddr_in.v6.sin6_port   = htons(Port);
			/* _saddr_in.v6.sin6_flowinfo = ? */
			/* _saddr_in.v6.sin6_scope_id = ? */

			ret = inet_pton ( AF_INET6 , IP_Address.c_str(), &_saddr_in.v6.sin6_addr );

			address     = reinterpret_cast <struct sockaddr *> (&_saddr_in.v6);
			address_len = sizeof(_saddr_in.v6);

			break;

		/* Unsupported Address Family – – – – – – – – – – – – – – – – – – – – */
		default:
			this->close();
			throw SocketError( __FILE__ , __LINE__, "Unsupported Address Family");

	}

	// (family == AF_INET) ?

	// if ( ret < 1 ) {

	// 	this->close();
	// 	(ret == 0) ?
	// 		throw SocketError( __FILE__ , __LINE__, "Address Not Parseable (in the specified address family)"):
	// 		throw SocketError( __FILE__ , __LINE__ );
	// }

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	address     = reinterpret_cast <struct sockaddr *> (&_saddr_in);
	address_len = sizeof(_saddr_in);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	ret = ::bind( descriptor, address, address_len );
	if ( ret == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( *this );
}

Socket &	Socket::bind( unsigned int IP_Address, int Port) {

	struct in_addr sin_addr;
	const char *ret;

	sin_addr.s_addr = IP_Address;

	switch( family )
	{

		/* IPv4 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		case AF_INET:

			char IPv4_addr[ INET_ADDRSTRLEN  ];

			ret = inet_ntop( AF_INET,  &(sin_addr), IPv4_addr, INET_ADDRSTRLEN  );

			if (ret == NULL) {
				this->close();
				throw SocketError( __FILE__ , __LINE__, "Address Not Parseable (in the specified address family)");
			}

			ip_address = IPv4_addr;
			break;


		/* IPv6 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		case AF_INET6:

			char IPv6_addr[ INET6_ADDRSTRLEN ];

			ret = inet_ntop( AF_INET6, &(sin_addr), IPv6_addr, INET6_ADDRSTRLEN );

			if (ret == NULL) {
				this->close();
				throw SocketError( __FILE__ , __LINE__, "Address Not Parseable (in the specified address family)");
			}

			ip_address = IPv6_addr;
			break;


		/* Unsupported Address Family – – – – – – – – – – – – – – – – – – – – */
		default:
			this->close();
			throw SocketError( __FILE__ , __LINE__, "Unsupported Address Family");

	}

	return ( this->bind( ip_address, Port ) );
}

Socket &	Socket::listen( int connections = MAXCONN ) {

	int ret = ::listen( descriptor, connections );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket		Socket::getSocket( std::string hostname, std::string servername,
	int Family = AF_UNSPEC, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) {

	/* addrinfo Structure:

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

	See : /usr/include/netdb.h @line 147 */

	Socket sock;

	struct addrinfo hints;
	struct addrinfo *head;
	struct addrinfo *cur;
	int sockdes;
	int ret;

	memset( &hints, 0, sizeof(hints) );
	hints.ai_family   = Family;
	hints.ai_socktype = Type;
	hints.ai_protocol = Protocol;

	ret = getaddrinfo( hostname.c_str(), servername.c_str(), &hints, &head );
	if ( ret != 0 )
		throw SocketError( __FILE__ , __LINE__, gai_strerror(ret));

	sockdes = -1;
	for (cur = head; cur; cur = cur->ai_next) {

		sockdes = ::socket(cur->ai_family, cur->ai_socktype, cur->ai_protocol);
		if ( sockdes < 0 )
			continue ;

		ret = ::connect( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret < 0 ) {
			::close(sockdes);
			sockdes = -1;
			continue ;
		}

		break ;
	}

	freeaddrinfo(head);

	if (sockdes < 0)
		throw SocketError( __FILE__ , __LINE__, "Failure to establish connection with specified hostname");

	sock.descriptor = sockdes;
	return ( sock );
}

Socket &	Socket::connect( std::string hostname, std::string servername ) {
	return ( connect ( Socket::getSocket ( hostname, servername ) ) );
}

Socket &	Socket::connect( Socket && peer ) {
	return ( connect ( peer ) );
}

Socket &	Socket::connect( Socket & peer ) {

	int ret = ::connect( descriptor, peer.address, peer.address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError( __FILE__ , __LINE__ );
	}
	return ( *this );
}

Socket		Socket::accept() const {

	Socket Client( *this );

	Client.descriptor = ::accept( descriptor, Client.address, &Client.address_len );
	if ( Client.descriptor == -1 )
		throw SocketError( __FILE__ , __LINE__ );

	return ( Client );
}

// ssize_t		Socket::send( const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

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

// 	size_t bytes;

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

void	Socket::close() const {

	if ( ::close( descriptor ) == -1 )
		throw SocketError( __FILE__ , __LINE__ );
}

void	Socket::shutdown ( int how = SHUT_RDWR ) const {

	/* Shut down part of a full-duplex connection - - - - - - - - - - - - - - -

	   int   shutdown(int socket, int how);

		'how' can be one of the following flags:

	      - SHUT_RD   (0)  --  further receives will be disallowed
	      - SHUT_WR   (1)  --  further sends will be disallowed
	      - SHUT_RDWR (2)  --  further sends and receives will be disallowed

		  ( 'SHUT_RDWR' is equivalent to a close() )

	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	if ( ::shutdown( descriptor , how ) == -1 )
		throw SocketError( __FILE__ , __LINE__ );

}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::SocketError( void ) {}

Socket::SocketError::SocketError( const char *File, size_t Line ) :
	file ( File ),
	line ( std::to_string( Line ) ) {
}

Socket::SocketError::SocketError( const char *File, size_t Line, std::string Error_Message ) :
	file ( File ),
	line ( std::to_string( Line ) ),
	err_msg ( Error_Message ) {
}

Socket::SocketError::~SocketError( void ) {}

const char *Socket::SocketError::what() const throw() {

	return (
		std::string("~ " + file + ":" + line + " -- Socket Error : " +
		(err_msg.empty() ? std::string(strerror(errno)) : err_msg) + " ~").c_str()
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <mutex>
#include <thread>

using namespace std;

int	main() {

	try {

		Socket Server("0.0.0.0", 5401);

		// Server.bind;

		// Server.listen();

		// Socket Client[10];

		// Client[0].connect(Server);

		// Client[1].connect("10.113.8.3", "3000");
		// Client[2].connect("10.113.8.3", "3000");
		// Client[3].connect("10.113.8.3", "3000");
		// Client[4].connect("10.113.8.3", "3000");

		// Client[5].connect("www.google.com", "https");
		cout << "Everything works.\n";

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}

	return (0);
}
