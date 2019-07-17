/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 13:57:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Fixed::Fixed( void )
	: _fixed_pt_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int N )
	: _fixed_pt_value( N << _fractional_bits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float N )
	: _fixed_pt_value( (int) roundf( N * ( 1 << _fractional_bits ) ) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Fixed&			Fixed::operator=(const Fixed & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		_fixed_pt_value = rhs._fixed_pt_value;
	}
	return (*this);
}

std::ostream &	operator<<( std::ostream & out, const Fixed & in ) {

	if (in.getRawBits() & FRACTIONAL_BITMASK) {
		out << in.toFloat();
	} else {
		out << in.toInt();
	}

	return (out);
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
