/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/04 17:04:13 by akharrou         ###   ########.fr       */
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
# include <cmath>
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
# define DFLT_PROTOCOL ( IPPROTO_IP  ) /* | IPPROTO_IP  | IPPROTO_TCP | IPPROTO_UDP | */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Socket {


	public:

		Socket( void );
		Socket( const Socket & src );
		~Socket( void );

		explicit Socket( int Family, int Type, int Protocol );
		Socket( const char * hostname,
		        const char * servname = NULL,
		        int Type              = DFLT_TYPE,
		        int Protocol          = DFLT_PROTOCOL
		);

		Socket & operator = ( const Socket & rhs );

		const char *	ip_address;
		const char *	port;
		int				family;
		int				type;
		int				protocol;
		int				descriptor;

		struct sockaddr address;
		socklen_t address_len;

		Socket &	socket   ( int Family   = DFLT_FAMILY,
		                       int Type     = DFLT_TYPE,
		                       int Protocol = DFLT_PROTOCOL );

		Socket &	bind     ( const char * hostname, const char * servname );

		Socket &	listen   ( int connections );

		Socket &	connect  ( Socket &  );
		Socket &	connect  ( Socket && );
		Socket &	connect  ( const char * hostname, const char * servname );

		Socket		accept   ( void ) const;

		ssize_t		send     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		sendto   ( Socket & receiver, const void * buffer, size_t length , int flags ) const;

		ssize_t		recv     ( const void * buffer, size_t length , int flags )                    const;
		ssize_t		recvfrom ( Socket & sender, const void * buffer, size_t length , int flags )   const;

		void		shutdown ( int how );
		void		close    ( void );

		Socket &	setsockopt( int level, int option, int value );
		int			getsockopt( int level, int option, int value );

		Socket &	settimeout( double timeout );
		double		gettimeout( void ) const;

    //  |  setblocking(...)
    //  |      setblocking(flag)
    //  |
    //  |      Set the socket to blocking (flag is true) or non-blocking (false).
    //  |      setblocking(True) is equivalent to settimeout(None);
    //  |      setblocking(False) is equivalent to settimeout(0.0).
    //  |
    //  |  setsockopt(...)
    //  |      setsockopt(level, option, value)
    //  |
    //  |      Set a socket option.  See the Unix manual for level and option.
    //  |      The value argument can either be an integer or a string.

		static Socket	getSocket( const char * hostname, const char * servname,
		    int Family   = AF_UNSPEC     ,
		    int Type     = DFLT_TYPE     ,
		    int Protocol = DFLT_PROTOCOL ,
		    int Flags    = AI_DEFAULT    );

		class SocketError : public std::exception {

			public:
				SocketError( void );
				SocketError( const char * File, size_t Line );
				SocketError( const char * File, size_t Line, const char * Error_Message );
				~SocketError(void);

				std::string file;
				std::string line;
				const char * err_msg;

				virtual const char* what() const throw();
		};
};

std::ostream & operator << ( std::ostream & out, const Socket & in );
