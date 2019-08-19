/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/16 15:22:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <stdlib.h>
# include <unistd.h>

# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>

# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <float.h>
# include <dirent.h>
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <cmath>
# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# ifndef LINE_SIZE
#  define LINE_SIZE (256)
# endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define IP  ( IPPROTO_IP  ) /* ip  ; 0  ; IP  ; # internet _protocol             */
# define TCP ( IPPROTO_TCP ) /* tcp ; 6  ; TCP ; # transmission control _protocol */
# define UDP ( IPPROTO_UDP ) /* udp ; 17 ; UDP ; # user datagram _protocol

See : /etc/protocols

-  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	Ports:

		redstorm_join	2346/udp    # Game Connection Port
		redstorm_join	2346/tcp    # Game Connection Port

		n/a             4/tcp    Unassigned
		n/a             6/tcp    Unassigned
		...

See : /etc/services

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define MAX_BACKLOG (20)  /* "Most systems silently limit this number
                           to about 20; you can probably get away with
                           setting it to 5 or 10."

See : http://beej.us/guide/bgnet/pdf/bgnet_A4.pdf  @page 21, line 5

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

There are several special addresses:

	- IPv4 : INADDR_LOOPBACK <==> (127.0.0.1) or ("localhost")
	- IPv4 : INADDR_ANY      <==> (0.0.0.0)

	- IPv6 : IN6ADDR_LOOPBACK_INIT <==> (0000:0000:0000:0000:0000:0000:0000:0001) or (::1)
	- IPv6 : IN6ADDR_ANY_INIT      <==> (0000:0000:0000:0000:0000:0000:0000:0000) or (::0)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define DFLT_IPADDR   ( "0.0.0.0"   )
# define DFLT_PORT     ( 8080        )

# define DFLT_FAMILY   ( AF_INET     ) /* | AF_INET     | AF_INET6    | AF_UNSPEC   | */
# define DFLT_TYPE     ( SOCK_STREAM ) /* | SOCK_STREAM | SOCK_DGRAM  | SOCK_RAW    | */
# define DFLT_PROTOCOL ( IPPROTO_IP  ) /* | IPPROTO_IP  | IPPROTO_TCP | IPPROTO_UDP | */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define SOCKET_DISCONNECTED (  0 )
# define SOCKET_EMPTY        ( -1 )

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Socket
{

	protected:

		struct sockaddr_storage _address;
		socklen_t _address_len;

		std::string _ip_address;
		std::string _port;

		int _family;
		int _type;
		int _protocol;
		int _descriptor;

	public:

	/* DE/CONSTRUCTORS - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket ( void );
		Socket ( const Socket & src );
		Socket ( int Family, int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL) ;
		Socket ( const char * Host, const char * Port,
			int Type = DFLT_TYPE, int Protocol = DFLT_PROTOCOL );
		~Socket( void );

	/* OVERLOADS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket & operator = ( const Socket & rhs );

	/* STATICS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		static
		struct addrinfo * getaddrinfo ( const char * Host , const char * Port ,
		                                int Family   = AF_UNSPEC   ,
		                                int Type     = DFLT_FAMILY ,
		                                int Protocol = DFLT_TYPE   ,
		                                int Flags    = AI_DEFAULT );

		static
		std::string     getip ( struct sockaddr_storage _address );

		static
		std::string   getport ( struct sockaddr_storage _address );

	/* ACCESSORS  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket &   setsockopt ( int level, int option, int value );
		Socket &   settimeout ( double timeout );
		Socket &  setblocking ( bool value );

		int        getsockopt ( int option, int level ) const;
		double     gettimeout ( void ) const;

		int            fileno ( void ) const;

		int         getFamily ( void ) const;
		int           getType ( void ) const;
		int       getProtocol ( void ) const;

		std::string     getIp ( void ) const;
		std::string   getPort ( void ) const;

	/* OPERATIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket &       socket ( int Family, int Type, int Protocol );
		Socket &       socket ( int Family );

		Socket &         bind ( const char * Host, const char * Port,
		                        int flags = AI_PASSIVE );

		Socket &       listen ( int connections = MAX_BACKLOG );

		Socket &      connect ( Socket & );
		Socket &      connect ( const char * Host, const char * Port,
		                        int Family = AF_UNSPEC, int Flags = AI_DEFAULT );

		int            accept ( Socket & newClient ) const;
		Socket         accept ( bool && res = 1 ) const;

		void         shutdown ( int sockfd, int how = SHUT_RDWR );

		void            close ( int sockfd );
		void            close ( void );

	/* I/O OPERATONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t          send ( int sockfd, T * data,
		                        size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( int sockfd, T && data,
		                        size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( T * data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( T && data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( Socket & receiver,
		                        T * data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( Socket & receiver,
		                        T && data, size_t length = sizeof( T ),
		                        int flags = 0 );

		ssize_t          send ( int sockfd, std::string & data,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t          send ( std::string & data,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t          send ( Socket & receiver, std::string & data,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t        sendto ( T * data, struct sockaddr_storage *dest_addr,
		                        socklen_t && dest_len, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( T && data, struct sockaddr_storage *dest_addr,
		                        socklen_t && dest_len, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( const char * Host, const char * Port,
		                        T * data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( const char * Host, const char * Port,
		                        T && data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( Socket & receiver,
		                        T * data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( Socket & receiver,
		                        T && data, size_t length = sizeof( T ),
		                        int flags = 0 );

		ssize_t        sendto ( std::string & data,
		                        struct sockaddr_storage *dest_addr,
		                        socklen_t & dest_len, size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t        sendto ( const char * Host, const char * Port,
		                        std::string & data, size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t        sendto ( Socket & receiver, std::string & data,
		                        size_t nbytes = LINE_SIZE, int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t     recv_into ( int sockfd, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( int sockfd, T && buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( T && buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( Socket & sender, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( Socket & sender, T && buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );

		ssize_t     recv_into ( int sockfd, std::string & buffer,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t     recv_into ( std::string & buffer,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		ssize_t     recv_into ( Socket & sender, std::string & buffer,
		                        size_t nbytes = LINE_SIZE,
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t recvfrom_into ( T * buffer, size_t buflen = sizeof( T ),
		                        struct sockaddr_storage *dest_addr = nullptr,
		                        socklen_t && dest_len = sizeof ( sockaddr_storage ),
		                        int flags = 0 );
		template <typename T>
		ssize_t recvfrom_into ( T && buffer, size_t buflen = sizeof( T ),
		                        struct sockaddr_storage *dest_addr = nullptr,
		                        socklen_t && dest_len = sizeof ( sockaddr_storage ),
		                        int flags = 0 );
		template <typename T>
		ssize_t recvfrom_into ( Socket & sender, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t recvfrom_into ( Socket & sender, T && buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );

		ssize_t recvfrom_into ( std::string & buffer, size_t nbytes = LINE_SIZE,
		                        struct sockaddr_storage *dest_addr = nullptr,
		                        socklen_t && dest_len = sizeof( sockaddr_storage ),
								int flags = 0 );

		ssize_t recvfrom_into ( Socket & sender, std::string & buffer,
		                        size_t nbytes = LINE_SIZE, int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		T *              recv ( int sockfd, size_t length,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );
		template <typename T>
		T                recv ( int sockfd,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );
		template <typename T>
		T *              recv ( size_t length,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );
		template <typename T>
		T                recv ( ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );
		template <typename T>
		T *              recv ( Socket & sender, size_t length,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );
		template <typename T>
		T                recv ( Socket & sender,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );

		std::string      recv ( int sockfd, size_t nbytes = LINE_SIZE,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );

		std::string      recv ( size_t nbytes = LINE_SIZE,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );

		std::string      recv ( Socket & sender, size_t nbytes = LINE_SIZE,
		                        ssize_t *&& bytes_recvd = nullptr,
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		T *           recvfrom ( size_t length,
		                         struct sockaddr_storage *dest_addr = nullptr,
		                         socklen_t && dest_len = sizeof ( sockaddr_storage ),
		                         ssize_t *&& bytes_recvd = nullptr, int flags = 0 );
		template <typename T>
		T             recvfrom ( struct sockaddr_storage *dest_addr = nullptr,
		                         socklen_t && dest_len = sizeof ( sockaddr_storage ),
		                         ssize_t *&& bytes_recvd = nullptr, int flags = 0 );
		template <typename T>
		T *           recvfrom ( Socket & sender, size_t length,
		                         ssize_t *&& bytes_recvd = nullptr,
		                         int flags = 0 );
		template <typename T>
		T             recvfrom ( Socket & sender,
		                         ssize_t *&& bytes_recvd = nullptr,
		                         int flags = 0 );

		std::string   recvfrom ( size_t nbytes = LINE_SIZE,
		                         struct sockaddr_storage *dest_addr = nullptr,
		                         socklen_t && dest_len = sizeof ( sockaddr_storage ),
		                         ssize_t *&& bytes_recvd = nullptr, int flags = 0 );

		std::string   recvfrom ( Socket & sender, size_t nbytes = LINE_SIZE,
		                         ssize_t *&& bytes_recvd = nullptr,
		                         int flags = 0 );

	/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		class SocketError :
			public std::exception {

			std::string _file;
			std::string _line;
			std::string _err_msg;

			public:
				SocketError  ( void );
				SocketError  ( const SocketError & );
				SocketError  ( const char * File, size_t Line );
				SocketError  ( const char * File, size_t Line,
				               const char * Error_Message );
				~SocketError ( void );

				SocketError &	operator = ( const SocketError & );

				virtual const char * what () const noexcept;
		};

};

std::ostream & operator << ( std::ostream & out, const Socket & in );


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                            TEMPLATE DEFINITIONS                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::send( int sockfd, T * data, size_t length, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = ::send( sockfd , reinterpret_cast <const void *> ( data ) ,
	                     length , flags );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		data = reinterpret_cast <T *> ( data ) + bytes_sent;
		bytes_sent +=
			Socket::send( sockfd , data ,
			              length - static_cast <size_t> (bytes_sent) ,
			              flags );
	}

	/* FIXME : make it handle block & non-bocking sockets */

	return ( bytes_sent );
}

template <typename T>
ssize_t			Socket::send( T * data, size_t length, int flags )
{
	return ( Socket::send( _descriptor, data, length, flags ) );
}

template <typename T>
ssize_t			Socket::send( Socket & receiver, T * data, size_t length, int flags )
{
	return ( Socket::send( receiver._descriptor, data, length, flags ) );
}

template <typename T>
ssize_t			Socket::send( int sockfd, T && data, size_t length, int flags )
{
	return ( Socket::send ( sockfd, &data, length, flags ) );
}

template <typename T>
ssize_t			Socket::send( T && data, size_t length, int flags )
{
	return ( Socket::send( _descriptor, &data, length, flags ) );
}

template <typename T>
ssize_t			Socket::send( Socket & receiver, T && data, size_t length, int flags )
{
	return ( Socket::send( receiver._descriptor, &data, length, flags ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::sendto( T * data, struct sockaddr_storage *dest_addr,
	socklen_t && dest_len, size_t length, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = ::sendto( _descriptor, reinterpret_cast <const void *> ( data ) ,
	                       length , flags,
	                       reinterpret_cast <struct sockaddr *> ( dest_addr ),
	                       dest_len );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		data = reinterpret_cast <T *> (data) + bytes_sent;
		bytes_sent +=
			Socket::sendto( data , dest_addr ,
			                length - static_cast <size_t> (bytes_sent) ,
			                flags );

	}

	return ( bytes_sent );
}

template <typename T>
ssize_t			Socket::sendto( T && data, struct sockaddr_storage *dest_addr,
	socklen_t && dest_len, size_t length, int flags )
{
	return ( Socket::sendto( &data , dest_addr , dest_len , length , flags ) );
}

template <typename T>
ssize_t			Socket::sendto( const char * Host, const char * Port,
	T * data, size_t length, int flags )
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
					static_cast <socklen_t> ( cur->ai_addrlen ) ,
					length , flags );

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

template <typename T>
ssize_t			Socket::sendto( const char * Host, const char * Port,
	T && data, size_t length, int flags )
{
	return ( Socket::sendto( Host , Port , &data , length , flags ) );
}

template <typename T>
ssize_t			Socket::sendto( Socket & receiver, T * data, size_t length,
	int flags )
{
	return (
		Socket::sendto( data , &receiver._address , receiver._address_len ,
			length , flags )
	);
}

template <typename T>
ssize_t			Socket::sendto( Socket & receiver, T && data, size_t length,
	int flags )
{
	return (
		Socket::sendto( &data , &receiver._address , receiver._address_len ,
			length , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::recv_into( int sockfd, T * buffer, size_t buflen,
	int flags )
{
	ssize_t bytes_recvd;

	bytes_recvd = ::recv ( sockfd , reinterpret_cast <void *> ( buffer ) ,
	                       buflen , flags );

	/* FIXME : make it keep receiving until length are received from the
	           socket */

	if ( bytes_recvd < 0 ) {

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

	return ( bytes_recvd );
}

template <typename T>
ssize_t			Socket::recv_into( int sockfd, T && buffer, size_t buflen,
	int flags )
{
	return ( Socket::recv_into ( sockfd , &buffer, buflen , flags ) );
}

template <typename T>
ssize_t			Socket::recv_into( T * buffer, size_t buflen, int flags )
{
	return ( Socket::recv_into ( _descriptor , buffer , buflen , flags ) );
}

template <typename T>
ssize_t			Socket::recv_into( T && buffer, size_t buflen, int flags )
{
	return (
		Socket::recv_into ( _descriptor , &buffer , buflen , flags )
	);
}

template <typename T>
ssize_t			Socket::recv_into( Socket & sender, T * buffer, size_t buflen,
	int flags )
{
	return (
		Socket::recv_into ( sender._descriptor , buffer , buflen , flags )
	);
}

template <typename T>
ssize_t			Socket::recv_into( Socket & sender, T && buffer, size_t buflen,
	int flags )
{
	return (
		Socket::recv_into ( sender._descriptor , &buffer , buflen , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::recvfrom_into ( T * buffer, size_t buflen,
	struct sockaddr_storage *dest_addr, socklen_t && dest_len, int flags )
{
	ssize_t bytes_recvd;

	bytes_recvd = ::recvfrom ( _descriptor ,
	                           reinterpret_cast <void *> ( buffer ) ,
	                           buflen , flags ,
	                           reinterpret_cast <sockaddr *> ( dest_addr ) ,
	                           &dest_len );

	/* FIXME : make it keep receiving until length are received from the
	           socket */

	if ( bytes_recvd < 0 ) {

		if ( errno == EAGAIN || errno == EWOULDBLOCK ) {
			errno = 0;
			return ( -1 );
		} else
			throw SocketError( __FILE__ , __LINE__ );
	}

	return ( bytes_recvd );
}

template <typename T>
ssize_t			Socket::recvfrom_into ( T && buffer, size_t buflen,
	struct sockaddr_storage *dest_addr, socklen_t && dest_len, int flags )
{
	return (
		Socket::recvfrom_into ( &buffer , buflen , dest_addr ,
			sizeof ( dest_len ) , flags )
	);
}

template <typename T>
ssize_t			Socket::recvfrom_into ( Socket & sender, T * buffer,
	size_t buflen, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = Socket::recvfrom_into ( buffer , buflen , &sender._address ,
		static_cast <socklen_t> ( sender._address_len ) , flags );

	sender._ip_address = Socket::getip   ( sender._address );
	sender._port       = Socket::getport ( sender._address );

	return ( bytes_sent );
}

template <typename T>
ssize_t			Socket::recvfrom_into ( Socket & sender, T && buffer,
	size_t buflen, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = Socket::recvfrom_into ( &buffer , buflen , &sender._address ,
		static_cast <socklen_t> ( sender._address_len ) , flags );

	sender._ip_address = Socket::getip   ( sender._address );
	sender._port       = Socket::getport ( sender._address );

	return ( bytes_sent );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
T *				Socket::recv( int sockfd, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	T * data = new T [ length ];
	ssize_t res;

	res = Socket::recv_into ( sockfd , data , length , flags );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

template <typename T>
T				Socket::recv( int sockfd, ssize_t *&& bytes_recvd, int flags )
{
	T data;
	ssize_t res;

	res = Socket::recv_into ( sockfd , data , sizeof ( T ) , flags );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

template <typename T>
T *				Socket::recv( size_t length, ssize_t *&& bytes_recvd, int flags )
{
	return ( Socket::recv <T> ( _descriptor , length , static_cast <ssize_t*> ( bytes_recvd ) , flags ) );
}

template <typename T>
T				Socket::recv( ssize_t *&& bytes_recvd, int flags )
{
	return ( Socket::recv <T> ( _descriptor , static_cast <ssize_t*> ( bytes_recvd ) , flags ) );
}

template <typename T>
T *				Socket::recv( Socket & sender, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	return (
		Socket::recv <T> ( sender._descriptor , length , static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

template <typename T>
T				Socket::recv( Socket & sender, ssize_t *&& bytes_recvd,
	int flags )
{
	return (
		Socket::recv <T> ( sender._descriptor , static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
T *				Socket::recvfrom( size_t length,
	struct sockaddr_storage *dest_addr, socklen_t && dest_len,
	ssize_t *&& bytes_recvd, int flags )
{
	T * data  = new T [ length ];
	ssize_t res;

	 res = Socket::recvfrom_into ( _descriptor , data , length , flags ,
		                           reinterpret_cast <sockaddr *> ( dest_addr ) ,
		                           &dest_len );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

template <typename T>
T 				Socket::recvfrom( struct sockaddr_storage *dest_addr,
	socklen_t && dest_len, ssize_t *&& bytes_recvd, int flags )
{
	T data;
	ssize_t res;

	res = Socket::recvfrom_into ( _descriptor , data , sizeof ( T ) , flags ,
		                          reinterpret_cast <sockaddr *> ( dest_addr ) ,
		                          &dest_len );

	if ( bytes_recvd == nullptr ) {
		if ( res < 0 )
			throw SocketError( __FILE__ , __LINE__ );
	} else
		( *bytes_recvd ) = res;

	return ( data );
}

template <typename T>
T *				Socket::recvfrom( Socket & sender, size_t length,
	ssize_t *&& bytes_recvd, int flags )
{
	return (
		Socket::recvfrom <T> ( &sender._address , sender._address_len ,
			static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

template <typename T>
T 				Socket::recvfrom( Socket & sender, ssize_t *&& bytes_recvd,
	int flags )
{
	return (
		Socket::recvfrom <T> ( &sender._address , sender._address_len ,
			static_cast <ssize_t*> ( bytes_recvd ) , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SOCKET_HPP */
