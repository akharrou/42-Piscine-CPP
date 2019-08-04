/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/03 19:38:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	Socket( AF_INET, SOCK_STREAM, IPPROTO_TCP ) {
}

Socket::Socket( int Port ) :
	Socket(DFLT_IPADDR, Port, DFLT_FAMILY, DFLT_TYPE, DFLT_PROTOCOL) {
}

Socket::Socket( int Family, int Type, int Protocol ) :

	family     ( Family     ),
	type       ( Type       ),
	protocol   ( Protocol   )
{
	Socket::socket ( family, type, protocol );
}

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

	if (this != &rhs) {

		ip_address   = rhs.ip_address;
		port         = rhs.port;
		family       = rhs.family;
		type         = rhs.type;
		protocol     = rhs.protocol;
		descriptor   = rhs.descriptor;
		address      = rhs.address;
		address_len  = rhs.address_len;
	}
	return (*this);
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
		throw SocketError();

	return (*this);
}

Socket &	Socket::bind( std::string IP_Address, int Port ) {


	/* Bind to an Address and Port - - - - - - - - - - - - - - - - - - - - - - - -

	    struct sockaddr_in  : /usr/include/netinet/in.h   @line 372
	    struct sockaddr_in6 : /usr/include/netinet6/in6.h @line 164

	    See : bind(2)

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	int ret;

	memset(&_saddr_in, 0, sizeof(_saddr_in));

	switch( family )
	{

		/* IPv4 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – */
		case AF_INET:

			_saddr_in.v4.sin_family = family;
			_saddr_in.v4.sin_len    = sizeof(family);
			_saddr_in.v4.sin_port   = htons(port);

			break;

		/* IPv6 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – */
		case AF_INET6:

			_saddr_in.v6.sin6_family = family;
			_saddr_in.v6.sin6_len    = sizeof(family);
			_saddr_in.v6.sin6_port   = htons(port);
			/* _saddr_in.v6.sin6_flowinfo = ?  -- IP6 flow information */
			/* _saddr_in.v6.sin6_scope_id = ?  -- scope zone index     */

			break;

		/* Unsupported Address Family – – – – – – – – – – – – – – – – – – – – */
		default:
			this->close();
			throw SocketError("Unsupported Address Family");

	}

	(family == AF_INET) ?
		ret = inet_pton ( AF_INET  , IP_Address.c_str(), &_saddr_in.v4.sin_addr  ):
		ret = inet_pton ( AF_INET6 , IP_Address.c_str(), &_saddr_in.v6.sin6_addr );

	if ( ret < 1 ) {

		this->close();
		(ret == 0) ?
			throw SocketError("Address Not Parseable (in the specified address family)"):
			throw SocketError();
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	address     = reinterpret_cast <struct sockaddr *> (&_saddr_in);
	address_len = sizeof(_saddr_in);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	ret = ::bind( descriptor, address, address_len );
	if ( ret == -1 )
		throw SocketError();

	return (*this);
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
				throw SocketError("Address Not Parseable (in the specified address family)");
			}

			ip_address = IPv4_addr;
			break;


		/* IPv6 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		case AF_INET6:

			char IPv6_addr[ INET6_ADDRSTRLEN ];

			ret = inet_ntop( AF_INET6, &(sin_addr), IPv6_addr, INET6_ADDRSTRLEN );

			if (ret == NULL) {
				this->close();
				throw SocketError("Address Not Parseable (in the specified address family)");
			}

			ip_address = IPv6_addr;
			break;


		/* Unsupported Address Family – – – – – – – – – – – – – – – – – – – – */
		default:
			this->close();
			throw SocketError("Unsupported Address Family");

	}

	return ( this->bind( ip_address, Port ) );
}

Socket &	Socket::listen( int connections = MAXCONN ) {

	int ret = ::listen( descriptor, connections );

	if ( ret == -1 ) {
		this->close();
		throw SocketError();
	}
	return (*this);
}

Socket		Socket::getSocket( std::string hostname, std::string servername,
	int Domain = AF_UNSPEC, int Family = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) {

	/* addrinfo Structure:

       struct addrinfo {
           int        ai_flags;            // -- AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST
           int        ai_family;           // -- PF_xxx
           int        ai_socktype;         // -- SOCK_xxx
           int        ai_protocol;         // -- 0 or IPPROTO_xxx for IPv4 and IPv6
           socklen_t  ai_addrlen;          // -- length of ai_addr
           char       ai_canonname;        // -- canonical name for hostname
           struct     sockaddr *ai_addr;   // -- binary address
           struct     addrinfo *ai_next;   // -- next structure in linked list
       };

	See : /usr/include/netdb.h @line 147 */

	struct addrinfo hints;
	struct addrinfo *head;
	struct addrinfo *cur;
	int sockdes;
	int ret;

	memset( &hints, 0, sizeof(hints) );
	hints.ai_family   = Domain;
	hints.ai_socktype = Family;
	hints.ai_protocol = Protocol;

	ret = getaddrinfo( hostname.c_str(), servername.c_str(), &hints, &head );

	if ( ret != 0 )
		throw SocketError(gai_strerror(ret));

	for (cur = head; cur; cur = cur->ai_next) {

		sockdes = ::socket( cur->ai_family, cur->ai_socktype, cur->ai_protocol );
		if ( sockdes == x ) {

			continue ;
		}

		ret = ::connect( sockdes, cur->ai_addr, cur->ai_addrlen );
		if ( ret == x ) {

			::close(sockdes);
			continue ;
		}

		break ;
	}

	freeaddrinfo(head);

	return (Socket());
}

Socket &	Socket::connect( Socket & peer ) {

	int ret = ::connect( descriptor, peer.address, peer.address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError();
	}
	return (*this);
}

Socket &	Socket::connect( std::string hostname, std::string servername ) {

	Socket tmp;

	connect();

	return (*this);
}

Socket		Socket::accept() const {

	Socket Client( *this );

	Client.descriptor = ::accept( descriptor, Client.address, &Client.address_len );
	if ( Client.descriptor == -1 )
		throw SocketError();

	return ( Client );
}

// ssize_t		Socket::send( const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = send();

// 	if ( bytes == -1 )
// 		throw SocketError();
// }

// ssize_t		Socket::sendto( Socket & receiver, const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = sendto();

// 	if ( bytes == -1 )
// 		throw SocketError();
// }

// ssize_t		Socket::recv( const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = recv();

// 	if ( bytes == -1 )
// 		throw SocketError();
// }

// ssize_t		Socket::recvfrom( Socket & sender, const void * buffer, size_t length , int flags ) const {

// 	size_t bytes;

// 	bytes = recvfrom();

// 	if ( bytes == -1 )
// 		throw SocketError();
// }

void	Socket::close() const {

	if ( ::close( descriptor ) == -1 )
		throw SocketError();
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
		throw SocketError();

}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::SocketError( void ) {}

Socket::SocketError::SocketError( std::string Error_Message )
	: err_msg ( Error_Message ) {
}

Socket::SocketError::~SocketError( void ) {}

const char *Socket::SocketError::what() noexcept {

	if (err_msg.empty())
		err_msg = strerror(errno);

	return (std::string("~ Socket Error : " + err_msg + " ~").c_str());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <mutex>
#include <thread>

int	main() {

	Socket Server("10.113.8.3", 3000);

	Server.listen();

	Socket Client[10];

	Client[0].connect(Server);
	Client[1].connect("10.113.8.3", "3000");
	Client[2].connect("10.113.8.3", "3000");
	Client[3].connect("10.113.8.3", "3000");
	Client[4].connect("10.113.8.3", "3000");

	return (0);
}

// int	main() {

// 	Socket Server("0.0.0.0", 3000);
// 	int Clients[10];

// 	Server.listen();

// 	for (int i = 0; i < 10; ++i) {

// 		Clients[i] = Server.accept().descriptor;
// 		std::thread([ &Server, &Clients, i ] (void) -> void {

// 			char tmp[4096];
// 			while (1) {
// 				::recv(Server.descriptor, tmp, 4096, 0);
// 			}
// 			Server.broadcast(tmp, Clients);

// 		}).detach();
// 	}

// 	return (0);
// }
