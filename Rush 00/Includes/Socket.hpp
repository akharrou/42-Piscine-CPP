/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/03 21:42:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    IPPROTO_IP   -->  ip  ; 0  ; IP  ; # internet protocol
    IPPROTO_TCP  -->  tcp ; 6  ; TCP ; # transmission control protocol
    IPPROTO_UDP  -->  udp ; 17 ; UDP ; # user datagram protocol
    ...

See : /etc/protocols

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	Ports:

		redstorm_join	2346/udp    # Game Connection Port
		redstorm_join	2346/tcp    # Game Connection Port

		n/a             4/tcp    Unassigned
		n/a             6/tcp    Unassigned
		...

See : /etc/services

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define MAXCONN (65535)   /* "For most socket interfaces, the maximum
                           number of sockets allowed per each connection
                           between an application and the TCP/IP sockets
                           interface is 65535."

See : https://www.ibm.com/support/knowledgecenter/en/
SSLTBW_2.1.0/com.ibm.zos.v2r1.hala001/maxsoc.htm

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

There are several special addresses:

	- IPv4 : INADDR_LOOPBACK : (127.0.0.1) or ("localhost")
	- IPv4 : INADDR_ANY      : (0.0.0.0)

    - IPv6 : IN6ADDR_LOOPBACK_INIT : (0000:0000:0000:0000:0000:0000:0000:0001) or (::1)
	- IPv6 : IN6ADDR_ANY_INIT      : (0000:0000:0000:0000:0000:0000:0000:0000) or (::0)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define DFLT_IPADDR   ( "0.0.0.0"   )
# define DFLT_PORT     ( 8080        )

# define DFLT_FAMILY   ( AF_INET     ) /* | AF_INET     | AF_INET6    | AF_UNSPEC   | */
# define DFLT_TYPE     ( SOCK_STREAM ) /* | SOCK_STREAM | SOCK_DGRAM  | SOCK_RAW    | */
# define DFLT_PROTOCOL ( IPPROTO_TCP ) /* | IPPROTO_IP  | IPPROTO_TCP | IPPROTO_UDP | */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Socket {

	union {
		struct sockaddr_in	v4;
		struct sockaddr_in6	v6;
	} _saddr_in;

	public:

		Socket( void );
		Socket( const Socket & src );
		Socket( int Port );

		Socket( int Family, int Type, int Protocol );

		Socket( std::string IP_Address, int Port,
			int Family, int Type, int Protocol );

		~Socket( void );

		Socket & operator = ( const Socket & rhs );

		std::string		ip_address;
		int				port;
		int				family;
		int				type;
		int				protocol;
		int				descriptor;

		struct sockaddr *address;
		socklen_t address_len;

		Socket &	socket   ( int Family, int Type, int Protocol );

		Socket &	bind     ( std::string     IP_Address , int Port );
		Socket &	bind     ( unsigned int    IP_Address , int Port );

		Socket &	listen   ( int connections );

		Socket &	connect  ( Socket &  );
		Socket &	connect  ( Socket && );
		Socket &	connect  ( std::string hostname , std::string servername );

		Socket		accept   ( void ) const;

		ssize_t		send     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		sendto   ( Socket & receiver, const void * buffer, size_t length , int flags ) const;

		ssize_t		recv     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		recvfrom ( Socket & sender, const void * buffer, size_t length , int flags )   const;

		void		shutdown ( int how ) const;
		void		close    ( void )    const;

		static Socket	getSocket( std::string hostname, std::string servername,
			int Domain, int Family, int Protocol );

		class SocketError : public std::exception {

			public:
				SocketError(void);
				SocketError( std::string Error_Message );
				~SocketError(void);

				std::string err_msg;
				const char * what() noexcept;
		};
};

std::ostream & operator << ( std::ostream & out, const Socket & in );
