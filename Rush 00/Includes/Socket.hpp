/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/07 19:23:48 by akharrou         ###   ########.fr       */
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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <cmath>
# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define IP  ( IPPROTO_IP  ) /* ip  ; 0  ; IP  ; # internet protocol             */
# define TCP ( IPPROTO_TCP ) /* tcp ; 6  ; TCP ; # transmission control protocol */
# define UDP ( IPPROTO_UDP ) /* udp ; 17 ; UDP ; # user datagram protocol

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
# define DFLT_PROTOCOL ( IPPROTO_TCP ) /* | IPPROTO_IP  | IPPROTO_TCP | IPPROTO_UDP | */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Socket {

	public:

		Socket  ( void );
		Socket  ( const Socket & src );
		~Socket ( void );

		explicit Socket( int Family, int Type, int Protocol );
		Socket( const char * Host, const char * Port, int Type, int Protocol );

		Socket & operator = ( const Socket & rhs );

	/* MEMBERS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		const char * ip_address;
		const char * port;

		int family;
		int type;
		int protocol;
		int descriptor;

		struct sockaddr_storage address;
		socklen_t address_len;

	/* STATICS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		static
		struct addrinfo * getaddrinfo ( const char * Host , const char * Port ,
		                                int Family   = AF_UNSPEC   ,
		                                int Type     = DFLT_FAMILY ,
		                                int Protocol = DFLT_TYPE   ,
		                                int Flags    = AI_DEFAULT );
		static
		std::string     getip ( struct sockaddr_storage address );

		static
		std::string   getport ( struct sockaddr_storage address );

	/* OPTIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket &   setsockopt ( int level, int option, int value );
		Socket &   settimeout ( double timeout );
		Socket &  setblocking ( bool value );

		int        getsockopt ( int option, int level ) const;
		double     gettimeout ( void ) const;

	/* OPERATIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket &       socket ( int Family, int Type, int Protocol );
		Socket &       socket ( int Family );

		Socket &         bind ( const char * Host, const char * Port, int flags );

		Socket &       listen ( int connections );

		Socket &      connect ( Socket & );
		Socket &      connect ( const char * Host, const char * Port, int Family,
		                        int Flags );

		Socket         accept ( void ) const;

		void         shutdown ( int sockfd, int how );

		void            close ( int sockfd );
		void            close ( void );

	/* I/O OPERATONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t          send ( int sockfd, T * data, size_t length = sizeof( T * ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( int sockfd, T data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( T * data, size_t length = sizeof( T * ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( T data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( Socket receiver, T * data, size_t length = sizeof( T * ),
		                        int flags = 0 );
		template <typename T>
		ssize_t          send ( Socket receiver, T data, size_t length = sizeof( T ),
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t        sendto ( T * data, struct sockaddr_storage *dest_addr,
		                        socklen_t dest_len = sizeof ( sockaddr_storage ),
		                        size_t length = sizeof( T * ), int flags = 0 );
		template <typename T>
		ssize_t        sendto ( T data, struct sockaddr_storage *dest_addr,
		                        socklen_t dest_len = sizeof ( sockaddr_storage ),
		                        size_t length = sizeof( T ), int flags = 0 );
		template <typename T>
		ssize_t        sendto ( const char * Host, const char * Port,
		                        T * data, size_t length = sizeof( T * ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( const char * Host, const char * Port,
		                        T data, size_t length = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( Socket receiver, T * data, size_t length = sizeof( T * ),
		                        int flags = 0 );
		template <typename T>
		ssize_t        sendto ( Socket receiver, T data, size_t length = sizeof( T ),
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t     recv_into ( int sockfd, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );
		template <typename T>
		ssize_t     recv_into ( Socket sender, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t recvfrom_into ( T * buffer,
		                        struct sockaddr_storage *dest_addr = nullptr,
		                        socklen_t dest_len = sizeof ( sockaddr_storage ),
		                        size_t buflen = sizeof( T ), int flags = 0 );
		template <typename T>
		ssize_t recvfrom_into ( Socket sender, T * buffer,
		                        size_t buflen = sizeof( T ),
		                        int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		T *              recv ( int sockfd, size_t length = sizeof( T * ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );
		template <typename T>
		T                recv ( int sockfd, size_t length = sizeof( T ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );
		template <typename T>
		T *              recv ( size_t length = sizeof( T * ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );
		template <typename T>
		T                recv ( size_t length = sizeof( T ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );
		template <typename T>
		T *              recv ( Socket sender, size_t length = sizeof( T * ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );
		template <typename T>
		T                recv ( Socket sender, size_t length = sizeof( T ),
		                        bool * peerDisconnected = nullptr, int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		T *           recvfrom ( struct sockaddr_storage *dest_addr = nullptr,
		                         socklen_t dest_len = sizeof ( sockaddr_storage ),
		                         size_t length = sizeof( T * ),
		                         bool * peerDisconnected = nullptr,
		                         int flags = 0 );
		template <typename T>
		T             recvfrom ( struct sockaddr_storage *dest_addr = nullptr,
		                         socklen_t dest_len = sizeof ( sockaddr_storage ),
		                         size_t length = sizeof( T ),
		                         bool * peerDisconnected = nullptr,
		                         int flags = 0 );
		template <typename T>
		T *           recvfrom ( Socket sender,
		                         size_t length = sizeof( T * ),
		                         bool * peerDisconnected = nullptr,
		                         int flags = 0 );
		template <typename T>
		T             recvfrom ( Socket sender,
		                         size_t length = sizeof( T ),
		                         bool * peerDisconnected = nullptr,
		                         int flags = 0 );

	/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		class SocketError final :
			public std::exception {

			std::string _file;
			std::string _line;
			std::string _err_msg;

			public:
				SocketError  ( void ) noexcept;
				SocketError  ( const SocketError & );
				SocketError  ( const char * File, size_t Line );
				SocketError  ( const char * File, size_t Line,
				               const char * Error_Message );
				~SocketError ( void ) noexcept override;

				SocketError &	operator = ( const SocketError & );

				std::string getError ( void ) const;
				const char * what () const noexcept;
		};

		class SocketPeerDisconnect final :
			public std::exception {

			int _sockfd;

			public:
				SocketPeerDisconnect  ( void ) noexcept;
				SocketPeerDisconnect  ( int sockfd );
				SocketPeerDisconnect  ( const SocketPeerDisconnect & );
				~SocketPeerDisconnect ( void ) noexcept;

				SocketPeerDisconnect &	operator = ( const SocketPeerDisconnect & );

				int getSockfd ( void ) const;
				const char * what () const noexcept;
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

		data = reinterpret_cast <const char *> (data) + bytes_sent;
		bytes_sent +=
			Socket::sendto( sockfd , data ,
			                length - static_cast <size_t> (bytes_sent) ,
			                flags );
	}

	return ( bytes_sent );
}

template <typename T>
inline ssize_t	Socket::send( T * data, size_t length, int flags )
{
	return ( Socket::send( descriptor, data, length, flags ) );
}

template <typename T>
inline ssize_t	Socket::send( Socket receiver, T * data, size_t length, int flags )
{
	return ( Socket::send( receiver.descriptor, data, length, flags ) );
}

template <typename T>
inline ssize_t	Socket::send( int sockfd, T data, size_t length, int flags )
{
	return ( Socket::send ( sockfd, &data, length, flags ) );
}

template <typename T>
inline ssize_t	Socket::send( T data, size_t length, int flags )
{
	return ( Socket::send( descriptor, &data, length, flags ) );
}

template <typename T>
inline ssize_t	Socket::send( Socket receiver, T data, size_t length, int flags )
{
	return ( Socket::send( receiver.descriptor, &data, length, flags ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::sendto( T * data, struct sockaddr_storage *dest_addr,
	socklen_t dest_len, size_t length, int flags )
{
	ssize_t bytes_sent;

	bytes_sent = ::sendto( descriptor, reinterpret_cast <const void *> ( data ) ,
	                       length , flags,
	                       reinterpret_cast <struct sockaddr *> (dest_addr),
	                       dest_len );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		data = reinterpret_cast <const char *> (data) + bytes_sent;
		bytes_sent +=
			Socket::sendto( data , dest_addr , dest_len ,
			                length - static_cast <size_t> (bytes_sent) ,
			                flags );

	}

	return ( bytes_sent );
}

template <typename T>
inline ssize_t	Socket::sendto( T data, struct sockaddr_storage *dest_addr,
	socklen_t dest_len, size_t length, int flags )
{
	return ( Socket::sendto ( &data , dest_addr , dest_len , length , flags ) );
}

template <typename T>
inline ssize_t	Socket::sendto( const char * Host, const char * Port,
	T * data, size_t length, int flags )
{
	struct addrinfo * head;
	struct addrinfo * cur;
	ssize_t bytes_sent;
	int ret;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	try {

		head = Socket::getaddrinfo( Host , Port , family , type , protocol );

	} catch ( std::exception & e ) {
		freeaddrinfo( head );
		throw e;
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	for ( cur = head; cur; cur = cur->ai_next ) {

		try {

			bytes_sent = Socket::sendto( data , cur->ai_addr , cur->ai_addrlen ,
			                             length , flags );

		} catch ( std::exception & e ) {

			if ( errno == EHOSTUNREACH )
				continue ;

			freeaddrinfo( head );
			throw e;

		}
	}

	freeaddrinfo( head );

	return ( bytes_sent );
}

template <typename T>
inline ssize_t	Socket::sendto( const char * Host, const char * Port,
	T data, size_t length, int flags )
{
	return ( Socket::sendto ( Host , Port , &data , length , flags ) );
}

template <typename T>
inline ssize_t	Socket::sendto( Socket receiver, T * data, size_t length,
	int flags )
{
	return (
		Socket::sendto ( data , receiver.address , receiver.address_len ,
			length , flags )
	);
}

template <typename T>
inline ssize_t	Socket::sendto( Socket receiver, T data, size_t length,
	int flags )
{
	return (
		Socket::sendto ( &data , receiver.address , receiver.address_len ,
			length , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::recv_into( int sockfd, T * buffer, size_t buflen,
	int flags )
{
	int bytes_recvd;

	bytes_recvd = ::recv ( sockfd , reinterpret_cast <void *> ( buffer ) ,
	                       buflen , flags );

	if ( bytes_recvd == 0 || errno == ECONNRESET ) {

		/* "[ECONNRESET] -- The connection is closed by the peer during a
		receive attempt on a socket." ; See recv(2) */

		return ( 0 );

	} else if ( bytes_recvd < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	}

	return ( bytes_recvd );
}

template <typename T>
ssize_t			Socket::recv_into( T * buffer, size_t buflen, int flags )
{
	return ( Socket::recv_into ( descriptor , buffer , buflen , flags ) );
}

template <typename T>
ssize_t			Socket::recv_into( Socket sender, T * buffer, size_t buflen,
	int flags )
{
	return ( Socket::recv_into ( sender.descriptor , buffer , buflen , flags ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
ssize_t			Socket::recvfrom_into ( T * buffer,
	struct sockaddr_storage *dest_addr, socklen_t dest_len,
	size_t buflen, int flags )
{
	ssize_t bytes_recvd;

	bytes_recvd = ::recvfrom ( descriptor ,
	                           reinterpret_cast <void *> ( buffer ) ,
	                           buflen , flags ,
	                           reinterpret_cast <sockaddr *> ( dest_addr ) ,
	                           &dest_len );

	if  ( bytes_recvd < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	}

	return ( bytes_recvd );
}

template <typename T>
inline ssize_t	Socket::recvfrom_into ( Socket sender, T * buffer,
	size_t buflen, int flags )
{
	return (
		Socket::recvfrom_into( buffer , sender.address , sender.address_len ,
			buflen , flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
T *				Socket::recv( int sockfd, size_t length, bool * peerDisconnected,
	int flags )
{
	ssize_t bytes_recvd;
	T * data;

	data = new T [ length ];

	bytes_recvd = Socket::recv_into <T> ( sockfd ,
	                                      reinterpret_cast <void *> ( data ) ,
	                                      length , flags );
	if ( bytes_recvd == 0 ) {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = true;
		else
			throw SocketPeerDisconnect(
				/* the peer of this */ sockfd /* has disconnected */
			);

	} else {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = false;

	}

	return ( data );
}

template <typename T>
T				Socket::recv( int sockfd, size_t length, bool * peerDisconnected,
	int flags )
{
	ssize_t bytes_recvd;
	T data;

	bytes_recvd = Socket::recv_into <T> ( sockfd ,
	                                      reinterpret_cast <void *> ( &data ) ,
	                                      length , flags );
	if ( bytes_recvd == 0 ) {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = true;
		else
			throw SocketPeerDisconnect(
				/* the peer of this */ sockfd /* has disconnected */
			);

	} else {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = false;

	}

	return ( data );
}

template <typename T>
inline T *		Socket::recv( size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recv <T *> ( descriptor , length ,
			flags , peerDisconnected )
	);
}

template <typename T>
inline T		Socket::recv( size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recv <T> ( descriptor , length ,
			flags , peerDisconnected )
	);
}

template <typename T>
inline T *		Socket::recv( Socket sender, size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recv <T *> ( sender.descriptor , length ,
			flags , peerDisconnected )
	);
}

template <typename T>
inline T		Socket::recv( Socket sender, size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recv <T> ( sender.descriptor , length ,
			flags , peerDisconnected )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
T *				Socket::recvfrom ( struct sockaddr_storage *dest_addr,
	socklen_t dest_len, size_t length, bool * peerDisconnected, int flags )
{
	ssize_t bytes_recvd;
	T * data;

	data = new T [ length ];

	bytes_recvd =
		Socket::recvfrom_into <T> ( descriptor ,
		                            reinterpret_cast <void *> ( data ) ,
		                            length ,
		                            flags ,
		                            reinterpret_cast <sockaddr *> ( dest_addr ) ,
		                            &dest_len );
	if ( bytes_recvd == 0 ) {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = true;
		else
			throw SocketPeerDisconnect(
				/* the peer of this socket ( */ descriptor /* )
				has disconnected */
			);

	} else {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = false;

	}

	return ( data );
}

template <typename T>
T				Socket::recvfrom ( struct sockaddr_storage *dest_addr,
	socklen_t dest_len, size_t length, bool * peerDisconnected, int flags )
{
	ssize_t bytes_recvd;
	T data;

	bytes_recvd =
		Socket::recvfrom_into <T> ( descriptor ,
		                            reinterpret_cast <void *> ( &data ) ,
		                            length ,
		                            flags ,
		                            reinterpret_cast <sockaddr *> ( dest_addr ) ,
		                            &dest_len );
	if ( bytes_recvd == 0 ) {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = true;
		else
			throw SocketPeerDisconnect(
				/* the peer of this socket ( */ descriptor /* )
				has disconnected */
			);

	} else {

		if ( peerDisconnected != nullptr )
			( * peerDisconnected ) = false;

	}

	return ( data );
}

template <typename T>
inline T *		Socket::recvfrom ( Socket sender, size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recvfrom <T *> ( &sender.address, sender.address_len,
			length, peerDisconnected, flags )
	);
}

template <typename T>
inline T		Socket::recvfrom ( Socket sender, size_t length,
	bool * peerDisconnected, int flags )
{
	return (
		Socket::recvfrom <T> ( &sender.address, sender.address_len,
			length, peerDisconnected, flags )
	);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SOCKET_HPP */
