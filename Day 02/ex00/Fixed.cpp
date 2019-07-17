/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 10:17:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Fixed::Fixed( void )
	: _fixed_pt_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) {
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
		_fixed_pt_value = rhs.getRawBits();
	}
	return (*this);
}

std::ostream &	operator<<( std::ostream & out, const Fixed & in ) {

	out << in.getRawBits();
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_pt_value);
}

void	Fixed::setRawBits( int const raw ) {
	_fixed_pt_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
