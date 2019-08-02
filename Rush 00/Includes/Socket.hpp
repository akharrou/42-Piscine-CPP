/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:33:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/01 21:46:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define IP  (0)   /* ip  ; 0 ; IP  ; # internet protocol             */
# define TCP (6)   /* tcp ; 6 ; TCP ; # transmission control protocol */

/* See : /etc/protocols */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Socket {

	public:
		Socket( void );
		Socket( const Socket & src );
		~Socket( void );

		Socket( std::string IP_Address, int Port,
			unsigned char Domain, unsigned char Type, unsigned char Protocol );

		Socket & operator = ( const Socket & rhs );

		std::string		ip_address;
		int				port;
		unsigned char	domain;
		unsigned char	type;
		unsigned char	protocol;
		int				descriptor;

		struct sockaddr_in	address;
		socklen_t			address_len;

		void	socket  ( int Domain, int Type, int Protocol );
		void	bind    ( std::string IP_Address, int Port   );

		void	listen  ( int maxconn ) const;
		void	connect ( Socket & )    const;
		void	accept  ( Socket & )    const;

		void	close   ();

		class SocketError : public std::exception {

			private:
				SocketError(void);

			public:
				~SocketError(void);
				SocketError( std::string err_msg );

				std::string err_msg;
				const char * what() const noexcept;
		};
};

std::ostream & operator << ( std::ostream & out, const Socket & in );
