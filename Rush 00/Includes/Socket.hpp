/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/02 23:33:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/socket.h>
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

See : /etc/protocols, /usr/include/netinet/in.h

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

	- INADDR_LOOPBACK : IPv4 (127.0.0.1) or ("localhost")
	- INADDR_ANY : IPv4 (0.0.0.0)

    - IN6ADDR_LOOPBACK_INIT :IPv6 (0000:0000:0000:0000:0000:0000:0000:0001) or (::1)
	- IN6ADDR_ANY_INIT :IPv6 (0000:0000:0000:0000:0000:0000:0000:0000) or (::0)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define DFLT_IPADDR   ( "0.0.0.0"   )
# define DFLT_PORT     ( 8080        )

# define DFLT_FAMILY   ( AF_UNSPEC   ) /* AF_INET, AF_INET6, AF_UNSPEC         */
# define DFLT_TYPE     ( SOCK_STREAM ) /* SOCK_STREAM, SOCK_DGRAM, SOCK_RAW    */
# define DFLT_PROTOCOL ( IPPROTO_TCP ) /* IPPROTO_IP, IPPROTO_TCP, IPPROTO_UDP */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Socket {

	public:
		Socket( const Socket & src );
		~Socket( void );

		Socket( void );
		Socket( int Port );

		Socket( std::string IP_Address, int Port,
			int Domain, int Type, int Protocol );

		Socket( int IP_Address, int Port,
			int Domain, int Type, int Protocol );

		Socket & operator = ( const Socket & rhs );

		std::string		ip_address;
		int				port;
		int				domain;
		int				type;
		int				protocol;
		int				descriptor;

		struct sockaddr	*address;
		socklen_t		address_len;

		Socket &	socket   ( int Domain, int Type, int Protocol );

		Socket &	bind     ( std::string IP_Address,  int Port  );
		Socket &	bind     ( unsigned int IP_Address, int Port  );

		Socket &	listen   ( unsigned int connections );

		Socket &	connect  ( Socket & );
		Socket		accept   ( void ) const;

		ssize_t		send     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		sendto   ( Socket & receiver, const void * buffer, size_t length , int flags ) const;

		ssize_t		recv     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		recvfrom ( Socket & sender, const void * buffer, size_t length , int flags )   const;

		void		shutdown ( int how ) const;
		void		close    ( void )    const;

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
