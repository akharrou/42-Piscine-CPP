/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/02 18:32:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	Socket("0.0.0.0", 8080, AF_INET, SOCK_STREAM, IP) {}

Socket::Socket( int Port ) :
	Socket("0.0.0.0", Port, AF_INET, SOCK_STREAM, IP) {}

Socket::Socket( std::string IP_Address, int Port,
	int Domain = AF_INET, int Type = SOCK_STREAM, int Protocol = IP ) :

	ip_address ( IP_Address ),
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
        address_IPv4 = rhs.address_IPv4;
        address_IPv6 = rhs.address_IPv6;
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

Socket &	Socket::socket( int Domain = AF_INET, int Type = SOCK_STREAM, int Protocol = IP ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    int   socket(int domain, int type, int protocol);

	    Domain:
	        AF_INET             Internet version 4 protocols,
	        AF_INET6            Internet version 6 protocols,

	    Type:
	        SOCK_STREAM         A SOCK_STREAM type provides sequenced,
	                            reliable, two-way connection based byte
	                            streams.

	    Protocol:
	        #define IP  (0)   // ip  ; 0 ; IP  ; # internet protocol, pseudo protocol number
	        #define TCP (6)   // tcp ; 6 ; TCP ; # transmission control protocol

	    See : socket(2), protocols(5), /etc/protocols

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	descriptor = ::socket( Domain, Type, Protocol );
	if ( descriptor == -1 )
		throw SocketError();

	return (*this);
}

Socket &	Socket::bind( std::string IP_Address, int Port ) {

	/* Bind to an Address and Port (i.e to a highway) - - - - - - - - - - - - -

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

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	int ret;

	if ( domain == AF_INET /* IPv4 */ ) {

		bzero( & address_IPv4, sizeof( address_IPv4 ) );

		ret = inet_pton ( AF_INET, IP_Address.c_str(), &(address_IPv4.sin_addr) );

		if ( ret == -1 ) {

			(*this).close();
			throw SocketError();

		} else if ( ret == 0 ) {
			goto IPv6_Address;
		}

        address_IPv4.sin_family = domain;
		address_IPv4.sin_len    = sizeof(domain);
        address_IPv4.sin_port   = htons( Port );

		address_len = sizeof ( address_IPv4 );

	} else if ( domain == AF_INET6 /* IPv6 */ ) {

IPv6_Address:
		bzero( & address_IPv6, sizeof( address_IPv6 ) );

		ret = inet_pton ( AF_INET6, IP_Address.c_str(), &(address_IPv6.sin6_addr) );

		if ( ret == -1 ) {

			(*this).close();
			throw SocketError();

		} else if ( ret == 0 ) {
			goto Unknown_Address;
		}

        address_IPv6.sin6_family = domain;
		address_IPv6.sin6_len    = sizeof(domain);
        address_IPv6.sin6_port   = htons( Port );
        /* address_IPv6.sin6_flowinfo = ?  // IP6 flow information */
        /* address_IPv6.sin6_scope_id = ?  // scope zone index     */

		address_len = sizeof ( address_IPv6 );

	} else {

Unknown_Address:
		(*this).close();
		throw SocketError("Unknown Internet Protocol");

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	ret = ::bind( descriptor,
	              reinterpret_cast <struct sockaddr *> ( &address_IPv6 ),
	              address_len );
	if ( ret == -1 ) {
		(*this).close();
		throw SocketError();
	}

	return (*this);
}

Socket &	Socket::listen( int connections = MAXCONN ) {

	if ( ::listen( descriptor, connections ) == -1 )
		throw SocketError();
	return (*this);
}

Socket &	Socket::connect( Socket & peerSocket ) {

	int ret = ::connect( this->descriptor,
	                     reinterpret_cast <struct sockaddr *> ( &peerSocket.address ),
			             peerSocket.address_len );
	if ( ret == -1 ) {
		(*this).close();
		throw SocketError();
	}
	return (*this);
}

Socket		Socket::accept() const {

	Socket Client( *this );

	Client.descriptor = ::accept( descriptor,
	                              reinterpret_cast <struct sockaddr *> ( &Client.address ),
	                              &Client.address_len );
	if ( Client.descriptor == -1 )
		throw SocketError();
	return ( Client );
}

ssize_t		Socket::send( const void * buffer, size_t length , int flags ) const {

	size_t bytes;

	bytes = send();

	if ( bytes == -1 )
		throw SocketError();
}

ssize_t		Socket::sendto( Socket & receiver, const void * buffer, size_t length , int flags ) const {

	size_t bytes;

	bytes = sendto();

	if ( bytes == -1 )
		throw SocketError();
}

ssize_t		Socket::recv( const void * buffer, size_t length , int flags ) const {

	size_t bytes;

	bytes = recv();

	if ( bytes == -1 )
		throw SocketError();
}

ssize_t		Socket::recvfrom( Socket & sender, const void * buffer, size_t length , int flags ) const {

	size_t bytes;

	bytes = recvfrom();

	if ( bytes == -1 )
		throw SocketError();
}


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




#include <mutex>
#include <thread>



int	main() {

	Socket Server("0.0.0.0", 3000);
	int Clients[10];

	Server.listen();

	for (int i = 0; i < 10; ++i) {

		Clients[i] = Server.accept().descriptor;
		std::thread([ &Server, &Clients, i ] (void) -> void {

			char tmp[4096];
			while (1) {
				::recv(Server.descriptor, tmp, 4096, 0);
			}
			Server.broadcast(tmp, Clients);

		}).detach();
	}

	return (0);
}
