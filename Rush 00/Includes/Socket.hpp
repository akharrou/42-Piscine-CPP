/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/05 16:10:33 by akharrou         ###   ########.fr       */
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

	/* OPTIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		int	        getsockopt  ( int option, int level ) const;
		double		gettimeout  ( void ) const;

		Socket &	setsockopt  ( int level, int option, int value );
		Socket &	settimeout  ( double timeout );
		Socket &	setblocking ( bool value );

	/* OPERATIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		Socket &	socket   ( int Family, int Type, int Protocol );
		Socket &	socket   ( int Family );

		Socket &	bind     ( const char * Host, const char * Port, int flags );

		Socket &	listen   ( int connections );

		Socket &	connect  ( Socket & );
		Socket &	connect  ( const char * Host, const char * Port, int Family,
			                   int Flags );

		Socket		accept   ( void ) const;

		void		shutdown ( int sockfd, int how );

		void		close    ( int sockfd );
		void		close    ( void );

	/* I/O OPERATONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		/* SEND BYTES   */
		ssize_t		send     ( const void * data, size_t length, int flags );
		ssize_t		send     ( int sockfd, const void * data, size_t length, int flags );
		ssize_t		send     ( Socket receiver, const void * data, size_t length, int flags );

		ssize_t		sendto   ( const void * data, size_t length,
				               struct sockaddr_storage *dest_addr, int flags );
		ssize_t		sendto   ( Socket receiver, const void * data, size_t length, int flags );

		/* SEND STRINGS */
		ssize_t		send     ( std::string msg, size_t length, int flags );
		ssize_t		send     ( std::string msg, int flags );
		ssize_t		send     ( int sockfd, std::string msg, size_t length, int flags );
		ssize_t		send     ( int sockfd, std::string msg, int flags );
		ssize_t		send     ( Socket receiver, std::string msg, size_t length, int flags );
		ssize_t		send     ( Socket receiver, std::string msg, int flags );

		ssize_t		sendto   ( std::string msg, size_t length, struct sockaddr_storage *dest_addr,
				               int flags );
		ssize_t		sendto   ( std::string msg, struct sockaddr_storage *dest_addr,
				               int flags );
		ssize_t		sendto   ( Socket receiver, std::string msg, size_t length, int flags );
		ssize_t		sendto   ( Socket receiver, std::string msg, int flags );

		/* SEND <TYPE> */
		template <typename T>
		ssize_t		send     ( T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( int sockfd, T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( Socket receiver, T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( T data, struct sockaddr_storage *dest_addr, socklen_t dest_len,
				               size_t length = sizeof( T ), int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( Socket receiver, T data, size_t length = sizeof( T ),
				               int flags = 0 );


	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		// /* RECEIVE BYTES   */
		// ssize_t		recv     ( const void * data, size_t length, int flags );
		// ssize_t		recv     ( int sockfd, const void * data, size_t length, int flags );
		// ssize_t		recv     ( Socket receiver, const void * data, size_t length, int flags );

		// ssize_t		recvfrom ( const void * data, size_t length,
		// 		               struct sockaddr_storage *dest_addr, socklen_t dest_len, int flags );
		// ssize_t		recvfrom ( Socket receiver, const void * data, size_t length, int flags );

		// /* RECEIVE STRINGS */
		// ssize_t		recv     ( std::string msg, size_t length, int flags );
		// ssize_t		recv     ( std::string msg, int flags );
		// ssize_t		recv     ( int sockfd, std::string msg, size_t length, int flags );
		// ssize_t		recv     ( int sockfd, std::string msg, int flags );
		// ssize_t		recv     ( Socket receiver, std::string msg, size_t length, int flags );
		// ssize_t		recv     ( Socket receiver, std::string msg, int flags );

		// ssize_t		recvfrom ( std::string msg, size_t length, struct sockaddr_storage *dest_addr,
		// 		               socklen_t dest_len, int flags );
		// ssize_t		recvfrom ( std::string msg, struct sockaddr_storage *dest_addr,
		// 		               socklen_t dest_len, int flags );
		// ssize_t		recvfrom ( Socket receiver, std::string msg, size_t length, int flags );
		// ssize_t		recvfrom ( Socket receiver, std::string msg, int flags );

		// /* RECEIVE <TYPE> */
		// template <typename T>
		// ssize_t		recv     ( T data, size_t length = sizeof( T ),
		// 		               int flags = 0 );

		// template <typename T>
		// ssize_t		recv     ( int sockfd, T data, size_t length = sizeof( T ),
		// 		               int flags = 0 );

		// template <typename T>
		// ssize_t		recv     ( Socket receiver, T data, size_t length = sizeof( T ),
		// 		               int flags = 0 );

		// template <typename T>
		// ssize_t		recvfrom ( T data, struct sockaddr_storage *dest_addr, socklen_t dest_len,
		// 		               size_t length = sizeof( T ), int flags = 0 );

		// template <typename T>
		// ssize_t		recvfrom ( Socket receiver, T data, size_t length = sizeof( T ),
		// 		               int flags = 0 );


	/* EXCEPTION - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		class SocketError :
			public std::exception {

			private:
				std::string _file;
				std::string _line;
				std::string _err_msg;

			public:
				SocketError  ( void );
				SocketError  ( const char * File, size_t Line );
				SocketError  ( const char * File, size_t Line, const char * Error_Message );
				~SocketError ( void );

				std::string getError( void ) const;
				virtual const char* what( void ) const throw();
		};
};

std::ostream & operator << ( std::ostream & out, const Socket & in );


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                            TEMPLATE DEFINITIONS                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <typename T>
inline ssize_t	Socket::send( int sockfd, T data, size_t length, int flags )
{
	return ( Socket::send( sockfd, &data, length, flags ) );
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

template <typename T>
inline ssize_t	Socket::sendto( T data, struct sockaddr_storage *dest_addr, socklen_t dest_len,
	size_t length, int flags )
{
	return ( Socket::sendto( &data, length, dest_addr, dest_len, flags ) );
}

template <typename T>
inline ssize_t	Socket::sendto( Socket receiver, T data, size_t length, int flags )
{
	return ( Socket::sendto( &data, length, &receiver.address, receiver.address_len, flags ) );
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SOCKET_HPP */
