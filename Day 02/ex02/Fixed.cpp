/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 14:48:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Fixed::Fixed( void )
	: _fixed_pt_value(0) { }

Fixed::Fixed( const int N )
	: _fixed_pt_value( N << _fractional_bits ) { }

Fixed::Fixed( const float N )
	: _fixed_pt_value( (int) roundf( N * ( 1 << _fractional_bits ) ) ) { }

Fixed::Fixed( const Fixed & src ) {
	*this = src;
}

Fixed::~Fixed( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Fixed &			Fixed::operator = ( const Fixed & rhs ) {

	if (this != &rhs) {
		_fixed_pt_value = rhs._fixed_pt_value;
	}
	return (*this);
}

bool		Fixed::operator >  ( const Fixed & rhs ) {
	return ( _fixed_pt_value > rhs._fixed_pt_value );
}

bool		Fixed::operator <  ( const Fixed & rhs ) {
	return ( _fixed_pt_value < rhs._fixed_pt_value );
}

bool		Fixed::operator >= ( const Fixed & rhs ) {
	return ( _fixed_pt_value >= rhs._fixed_pt_value );
}

bool		Fixed::operator <= ( const Fixed & rhs ) {
	return ( _fixed_pt_value <= rhs._fixed_pt_value );
}

bool		Fixed::operator == ( const Fixed & rhs ) {
	return ( _fixed_pt_value == rhs._fixed_pt_value );
}

bool		Fixed::operator != ( const Fixed & rhs ) {
	return ( _fixed_pt_value != rhs._fixed_pt_value );
}

Fixed &		Fixed::operator ++ () {
	++_fixed_pt_value;
	return ( *this );
}

Fixed &		Fixed::operator -- () {
	--_fixed_pt_value;
	return ( *this );
}

Fixed		Fixed::operator ++ ( int ) {
	Fixed tmp = *this;
	++_fixed_pt_value;
	return ( tmp );
}

Fixed		Fixed::operator -- ( int ) {
	Fixed tmp = *this;
	--_fixed_pt_value;
	return ( tmp );
}

Fixed		Fixed::operator + ( const Fixed & rhs ) {
	return ( Fixed( _fixed_pt_value + rhs._fixed_pt_value ) );
}

Fixed		Fixed::operator - ( const Fixed & rhs ) {
	return ( Fixed( _fixed_pt_value - rhs._fixed_pt_value ) );
}

Fixed		Fixed::operator * ( const Fixed & rhs ) {
	return (
		Fixed(
			(int) roundf(
				_fixed_pt_value * rhs._fixed_pt_value / (double) ( 1 << _fractional_bits )
			)
		)
	);
}

Fixed		Fixed::operator / ( const Fixed & rhs ) {
	return (
		Fixed(
			(int) roundf(
				_fixed_pt_value / rhs._fixed_pt_value * (double) ( 1 << _fractional_bits )
			)
		)
	);
}

Fixed &			Fixed::min ( Fixed & lhs, Fixed & rhs ) {
	return (
		lhs._fixed_pt_value < rhs._fixed_pt_value ? lhs : rhs
	);
}

const Fixed &	Fixed::min ( const Fixed & lhs, const Fixed & rhs ) {
	return (
		lhs._fixed_pt_value < rhs._fixed_pt_value ? lhs : rhs
	);
}

Fixed &			Fixed::max ( Fixed & lhs, Fixed & rhs ) {
	return (
		lhs._fixed_pt_value > rhs._fixed_pt_value ? lhs : rhs
	);
}

const Fixed &	Fixed::max ( const Fixed & lhs, const Fixed & rhs ) {
	return (
		lhs._fixed_pt_value > rhs._fixed_pt_value ? lhs : rhs
	);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int		Fixed::getRawBits( void ) const {
	return (_fixed_pt_value);
}

void	Fixed::setRawBits( int const raw ) {
	_fixed_pt_value = raw;
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

float		Fixed::toFloat( void ) const {
	return ( (float) ( _fixed_pt_value / ( (double) (1 << _fractional_bits) ) ) );
}

int			Fixed::toInt( void ) const {
	return ( (int) ( _fixed_pt_value >> _fractional_bits ) );
}


/* STD::COUT OVERLOAD — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::ostream &	operator<<( std::ostream & out, const Fixed & in ) {

	if (in.getRawBits() & FRACTIONAL_BITMASK) {
		out << in.toFloat();
	} else {
		out << in.toInt();
	}

	return (out);
}
