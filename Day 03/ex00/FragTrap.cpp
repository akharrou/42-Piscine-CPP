/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 20:40:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

FragTrap::FragTrap( void ) { }

FragTrap::FragTrap( /* regular */ )
	: /* attribs. */ { }

FragTrap::FragTrap( const FragTrap & src ) {

	*this = src;
	return ;
}

FragTrap::~FragTrap( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

FragTrap &			FragTrap::operator=(const FragTrap & rhs) {

	if (this != &rhs) {
		/* implement */
	}

	return (*this);
}

std::ostream &	operator<<( std::ostream& out, const FragTrap & in ) {

	out << /* implement */;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */




/* PRIVATE MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — */




/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

