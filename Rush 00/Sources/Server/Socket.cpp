/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/02 23:28:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	Socket(DFLT_IPADDR, DFLT_PORT, DFLT_FAMILY, DFLT_TYPE, DFLT_PROTOCOL) {}

Socket::Socket( int Port ) :
	Socket(DFLT_IPADDR, Port, DFLT_FAMILY, DFLT_TYPE, DFLT_PROTOCOL) {}

Socket::Socket( std::string IP_Address, int Port,
	int Domain = DFLT_FAMILY, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) :

	ip_address ( IP_Address ),
	port       ( Port       ),
	domain     ( Domain     ),
	type       ( Type       ),
	protocol   ( Protocol   )
{
	Socket::socket ( domain, type, protocol );
	Socket::bind   ( ip_address, port       );
}

Socket::Socket( int IP_Address, int Port,
	int Domain = DFLT_FAMILY, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) :

	port       ( Port       ),
	domain     ( Domain     ),
	type       ( Type       ),
	protocol   ( Protocol   )
{
	Socket::socket ( domain, type, protocol );
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
		domain       = rhs.domain;
		type         = rhs.type;
		protocol     = rhs.protocol;
		descriptor   = rhs.descriptor;
		IPv4_Address = rhs.IPv4_Address;
		IPv6_Address = rhs.IPv6_Address;
		address      = rhs.address;
		address_len  = rhs.address_len;
	}
	return (*this);
}

std::ostream &  operator << ( std::ostream& out, const Socket & in ) {

	out << "<descriptor=" << in.descriptor
	    << ", domain="    << in.domain
	    << ", type="      << in.type
	    << ", protocol="  << in.protocol
	    << ", laddr=('"   << in.ip_address << "', " << in.port << ")>\n";

	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

Socket &	Socket::socket( int Domain = DFLT_FAMILY,
				int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    int   socket(int domain, int type, int protocol);

	    Domain:
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

	    Protocol:
	        #define IP  (0)   // ip  ; 0  ; IP  ; # internet protocol, pseudo protocol number
	        #define TCP (6)   // tcp ; 6  ; TCP ; # transmission control protocol
	        #define UDP (17)  // udp ; 17 ; UDP ; # user datagram protocol

	    See : socket(2), protocols(5), /etc/protocols

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	descriptor = ::socket( Domain, Type, Protocol );
	if ( descriptor == -1 )
		throw SocketError();

	return (*this);
}

Socket &	Socket::bind( std::string IP_Address, int Port ) {

	struct addrinfo hints;
	struct addrinfo *head;
	int ret;

	bzero( &hints, sizeof(hints) );
	hints.ai_family   = domain;
	hints.ai_socktype = type;

	ret = getaddrinfo( IP_Address.c_str(), std::to_string(port).c_str(), &hints, &head );

	if ( ret != 0 ) {
		this->close();
		throw SocketError(gai_strerror(ret));
	}

	address     = hints.ai_addr;
	address_len = hints.ai_addrlen;

	freeaddrinfo(head);

	ret = ::bind( descriptor, address, address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError();
	}

/*

	/ Bind to an Address and Port (i.e to a highway) - - - - - - - - - - - - -

	    int  bind( int socket,
	               const struct sockaddr *address,
	               socklen_t address_len );

	    Socket Address Structure(s):

            // IPv4
            struct sockaddr_in
            {
                __uint8_t        sin_len;
                sa_family_t      sin_family;
                in_port_t        sin_port;
                struct in_addr   sin_addr;
                char             sin_zero[8];
            };

            // IPv6
            struct sockaddr_in6 {
                __uint8_t        sin6_len        // length of this struct(sa_family_t)
                sa_family_t      sin6_family     // AF_INET6 (sa_family_t)
                in_port_t        sin6_port       // Transport layer port # (in_port_t)
                __uint32_t       sin6_flowinfo   // IP6 flow information
                struct in6_addr  sin6_addr       // IP6 address
                __uint32_t       sin6_scope_id   // scope zone index
            };

	     See : bind(2) , /usr/include/netinet/in.h  @line 372 ,
		                 /usr/include/netinet/in6.h @line 164

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /

	switch(domain)
	{

		/ IPv4 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – /
		case AF_INET:

			bzero( & IPv4_Address, sizeof( IPv4_Address ) );

			ret = inet_pton ( AF_INET, IP_Address.c_str(), &(IPv4_Address.sin_addr) );

			if ( ret == -1 ) {

				this->close();
				throw SocketError();

			} else if ( ret == 0 ) {
				goto IPv6_Address;
			}

			IPv4_Address.sin_family = domain;
			IPv4_Address.sin_len    = sizeof(domain);
			IPv4_Address.sin_port   = htons( Port );

			address     = reinterpret_cast <struct sockaddr *> (&IPv4_Address);
			address_len = sizeof ( IPv4_Address );

			break;

		/ IPv6 – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – – /
		case AF_INET6:

IPv6_Address:
			bzero( & IPv6_Address, sizeof( IPv6_Address ) );

			ret = inet_pton ( AF_INET6, IP_Address.c_str(), &(IPv6_Address.sin6_addr) );

			if ( ret == -1 ) {

				this->close();
				throw SocketError();

			} else if ( ret == 0 ) {
				goto Invalid_IPAddress;
			}

			IPv6_Address.sin6_family = domain;
			IPv6_Address.sin6_len    = sizeof(domain);
			IPv6_Address.sin6_port   = htons( Port );
			/ IPv6_Address.sin6_flowinfo = ?  // IP6 flow information /
			/ IPv6_Address.sin6_scope_id = ?  // scope zone index     /

			address     = reinterpret_cast <struct sockaddr *> (&IPv6_Address);
			address_len = sizeof ( IPv6_Address );

			break;


		/ Invalid IP Address – – – – – – – – – – – – – – – – – – – – – – – – – /
		default:

Invalid_IPAddress:
			this->close();
			throw SocketError("Invalid Internet Protocol Address");

	}
*/

	return (*this);
}

Socket &	Socket::bind( unsigned int IP_Address, int Port) {

	switch( domain ) {

		case AF_INET:  /* IPv4 */

			char IPv4_addr[ INET_ADDRSTRLEN  ];
			struct sockaddr_in  sa_in;

			inet_ntop( AF_INET,  &(sa_in.sin_addr),   IPv4_addr, INET_ADDRSTRLEN  );
			ip_address = IPv4_addr;
			break;

		case AF_INET6: /* IPv6 */

			char IPv6_addr[ INET6_ADDRSTRLEN ];
			struct sockaddr_in6 sa_in6;

			inet_ntop( AF_INET6, &(sa_in6.sin6_addr), IPv6_addr, INET6_ADDRSTRLEN );
			ip_address = IPv6_addr;
			break;

		default:
			this->close();
			throw SocketError("Invalid Internet Protocol Address");

	}

	return ( this->bind( ip_address, Port ) );
}

Socket &	Socket::listen( unsigned int connections = MAXCONN ) {

	int ret = ::listen( descriptor, connections );

	if ( ret == -1 ) {
		this->close();
		throw SocketError();
	}
	return (*this);
}

Socket &	Socket::connect( Socket & peerSocket ) {

	int ret = ::connect( descriptor, peerSocket.address, peerSocket.address_len );

	if ( ret == -1 ) {
		this->close();
		throw SocketError();
	}
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
