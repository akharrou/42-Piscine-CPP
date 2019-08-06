/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/06 16:49:16 by akharrou         ###   ########.fr       */
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

		static struct addrinfo * getaddrinfo( const char * Host, const char * Port,
		                                      int Family, int Type, int Protocol,
		                                      int Flags );

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

		template <typename T>
		ssize_t		send     ( int sockfd, T * data, size_t length = sizeof( T * ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( int sockfd, T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( T * data, size_t length = sizeof( T * ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		send     ( Socket receiver, T * data, size_t length = sizeof( T * ),
		                       int flags = 0 );

		template <typename T>
		ssize_t		send     ( Socket receiver, T data, size_t length = sizeof( T ),
		                       int flags = 0 );

		/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		template <typename T>
		ssize_t		sendto   ( T * data, struct sockaddr_storage *dest_addr,
		                       socklen_t dest_len, size_t length = sizeof( T * ),
				               int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( T data, struct sockaddr_storage *dest_addr,
		                       socklen_t dest_len, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( const char * Host, const char * Port,
		                       T * data, size_t length = sizeof( T * ),
				               int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( const char * Host, const char * Port,
		                       T data, size_t length = sizeof( T ),
				               int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( Socket receiver, T * data, size_t length = sizeof( T * ),
		                       int flags = 0 );

		template <typename T>
		ssize_t		sendto   ( Socket receiver, T data, size_t length = sizeof( T ),
		                       int flags = 0 );

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
				SocketError  ( const char * File, size_t Line,
				               const char * Error_Message );
				~SocketError ( void );

				std::string getError( void ) const;
				virtual const char* what( void ) const throw();
		};

		class SocketDisconnect :
			public std::exception {

				int _sockfd;

			public:
				SocketDisconnect  ( void );
				SocketDisconnect  ( int sockfd );
				~SocketDisconnect ( void );

				int getSockfd(void) const;
				virtual const char *what(void) const throw();
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

	bytes_sent = ::send( sockfd , reinterpret_cast <void *> ( data ) ,
	                     length , flags );

	if ( bytes_sent < 0 ) {

		/* 'sockfd' won't be closed; it will be up to the caller to check
		the error corresponding to 'errno' and take action(s) accordingly. */

		throw SocketError( __FILE__ , __LINE__ );

	} else if ( static_cast <size_t> (bytes_sent) < length ) {

		data = reinterpret_cast <const char *> (data) + bytes_sent;
		bytes_sent +=
			Socket::send( sockfd , reinterpret_cast <void *> ( data ),
			              length - static_cast <size_t> (bytes_sent),
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

#endif /* SOCKET_HPP */
