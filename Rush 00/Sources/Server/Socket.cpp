/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:37:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/01 23:08:06 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../Includes/Socket.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Socket::Socket( void ) :
	Socket("0.0.0.0", 8080, AF_INET, SOCK_STREAM, IP) {}

Socket::Socket( std::string IP_Address, int Port,
	unsigned char Domain = AF_INET, unsigned char Type = SOCK_STREAM, unsigned char Protocol = IP ) :

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

Socket &  Socket::operator = ( const Socket & rhs ) {

	if (this != &rhs) {

        ip_address  = rhs.ip_address;
        port        = rhs.port;
        domain      = rhs.domain;
        type        = rhs.type;
        protocol    = rhs.protocol;
        descriptor  = rhs.descriptor;
        address     = rhs.address;
        address_len = rhs.address_len;
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

void	Socket::socket( int Domain, int Type, int Protocol ) {

	/* Create socket (connection endpoint) - - - - - - - - - - - - - - - - - - -

	    int   socket(int domain, int type, int protocol);

	    Domain:
	        PF_INET             Internet version 4 protocols,
	        PF_INET6            Internet version 6 protocols,

			(or AF instead of PF)

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

}

void	Socket::bind( std::string IP_Address, int Port )
{

	/* Bind to an Address and Port (i.e to a highway) - - - - - - - - - - - - -

	    int  bind( int socket,
	               const struct sockaddr *address,
	               socklen_t address_len );

	    Socket Address structure:

	       struct sockaddr_in
	       {
	           __uint8_t        sin_len;
	           sa_family_t      sin_family;
	           in_port_t        sin_port;
	           struct in_addr   sin_addr;
	           char             sin_zero[8];
	       };

	     See : bind(2), /usr/include/netinet/in.h @line 372

	 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	bzero( &address, sizeof(address) );

    address.sin_family      = domain;
    address.sin_port        = htons     ( Port               );
    address.sin_addr.s_addr = inet_addr ( IP_Address.c_str() );
    address_len             = sizeof    ( address            );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	int ret = ::bind( descriptor,
	                  reinterpret_cast <struct sockaddr *> ( &address ),
	                  address_len );
	if ( ret == -1 )
		throw SocketError();

}

void	Socket::close() {

	if ( ::close( descriptor ) == -1 )
		throw SocketError();
}

void	Socket::listen( int maxconn ) const {

	if ( ::listen( descriptor, maxconn ) == -1 )
		throw SocketError();
}

void	Socket::connect( Socket & peerSocket ) const {

	int ret = ::connect( this->descriptor,
	                     reinterpret_cast <struct sockaddr *> ( &peerSocket.address ),
			             peerSocket.address_len );
	if ( ret == -1 )
		throw SocketError();
}

void	Socket::accept( Socket & peerSocket ) const {

	Socket Client( *this );

	int ret = ::accept( descriptor,
	                    reinterpret_cast <struct sockaddr *> ( &Client.address ),
			            &Client.address_len );
	if ( ret == -1 )
		throw SocketError();
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Socket::SocketError::~SocketError( void ) {}
Socket::SocketError::SocketError( void ) {}

const char *Socket::SocketError::what() const noexcept {
	return (std::string("~ Socket Error : " + std::string(strerror(errno)) + " ~").c_str());
}
