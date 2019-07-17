/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 09:56:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed {

	public:

		Fixed( void );
		Fixed( int integer );
		Fixed( const Fixed & src );
		~Fixed( void );

		Fixed &		operator=(const Fixed &rhs);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

	private:

		int					_fixed_pt_value;
		static const int	_fractional_bits = 8;

};

std::ostream& operator<<( std::ostream& out, const Fixed& in );

#endif /* FIXED_HPP */
