/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:13:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 22:03:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Fixed::Fixed( void ) { }

Fixed::Fixed( /* regular */ )
	: /* attribs. */ { }

Fixed::Fixed( const Fixed& src ) {

	*this = src;
	return ;
}

Fixed::~Fixed( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Fixed&			Fixed::operator=(const Fixed &rhs) {

	if (this != &rhs) {
		/* implement */
	}

	return (*this);
}

std::ostream&	operator<<( std::ostream& out, const Fixed& in ) {

	out << /* implement */;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */




/* PRIVATE MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — */




/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */
