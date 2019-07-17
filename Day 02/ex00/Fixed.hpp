/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 22:03:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed {

	public:

		Fixed( void );
		Fixed( /* regular */ );
		Fixed( const Fixed& src );
		~Fixed( void );

		std::string		toString();
		Fixed			&operator=(const Fixed &rhs);

	private:

		/* attribs. */

};

std::ostream& operator<<( std::ostream& out, const Fixed& in );

#endif /* FIXED_HPP */
