/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 12:10:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed {

	public:

		Fixed( void );
		Fixed( const int N );
		Fixed( const float N );
		Fixed( const Fixed & src );
		~Fixed( void );

		Fixed &		operator=(const Fixed &rhs);

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

		float		toFloat( void ) const;
		int			toInt( void ) const;

	private:

		int					_fixed_pt_value;
		static const int	_fractional_bits = 8;

};

std::ostream& operator<<( std::ostream& out, const Fixed& in );

#endif /* FIXED_HPP */



/* EXPLANATION

	GREAT SOURCE : https://en.wikipedia.org/wiki/Fixed-point_arithmetic


EXAMPLE 1:  int ——> fixed <32,8>

	Normal (integer) : 8

	Binary Representation: 0000 0000 | 0000 0000 | 0000 0000 | 0000 1000
	—————————————————————————————————————————————————————————————————————————————————
	Binary Representation: 0000 0000 | 0000 0000 | 0000 1000 . 0000 0000
															 ^
												imaginary decimal point

	32 bit Fix Point Number (w/ 8 fractional bits) : 2048



		Fixed   |   <32, |  8>                                          |  ( 8.0 )           |  = 2048
			^     |    ^   |  ^                                           |     ^              |     ^
	number type | 32 bit | of which 8 are reserved for fractional bits  |  our real number   |  its representation as a fied point number


	(i.e)  ———>  0000 0000 | 0000 0000 | 0000 1000 . 0000 0000



EXAMPLE 2:  float ——> fixed <32,8>

	Normal (float) : 8.5

		suffices to bring the number to the ratio ( R = 2^8 / 1 )
		to convert it to the fixed point value for Fixed <x, 8>.

	32 bit Fix Point Number (w/ 8 fractional bits) : 2176

	(i.e)  ———>  0000 0000 | 0000 0000 | 0000 1000 . 1000 0000

*/
