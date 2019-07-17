/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 14:28:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

# define FRACTIONAL_BITS    (8)
# define FRACTIONAL_BITMASK (0b11111111)

class Fixed {

	public:

		Fixed( void );
		Fixed( const int N );
		Fixed( const float N );
		Fixed( const Fixed & src );
		~Fixed( void );

		Fixed &		operator =  ( const Fixed & rhs );

		bool		operator >  ( const Fixed & rhs );
		bool		operator <  ( const Fixed & rhs );
		bool		operator >= ( const Fixed & rhs );
		bool		operator <= ( const Fixed & rhs );
		bool		operator == ( const Fixed & rhs );
		bool		operator != ( const Fixed & rhs );

		Fixed &		operator ++ ();
		Fixed &		operator -- ();

		Fixed		operator ++ ( int );
		Fixed		operator -- ( int );

		Fixed		operator + ( const Fixed & rhs );
		Fixed		operator - ( const Fixed & rhs );
		Fixed		operator * ( const Fixed & rhs );
		Fixed		operator / ( const Fixed & rhs );

		static Fixed &			min ( Fixed & lhs, Fixed & rhs );
		static const Fixed &	min ( const Fixed & lhs, const Fixed & rhs );

		static Fixed &			max ( Fixed & lhs, Fixed & rhs );
		static const Fixed &	max ( const Fixed & lhs, const Fixed & rhs );

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

		float		toFloat( void ) const;
		int			toInt( void ) const;

	private:

		int					_fixed_pt_value;
		static const int	_fractional_bits = FRACTIONAL_BITS;

};

std::ostream& operator<<( std::ostream& out, const Fixed& in );

#endif /* FIXED_HPP */
