/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:53:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 09:53:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Ice::Ice( void ) :
	AMateria( "ice" ) {
}

Ice::Ice( const Ice & src ) {
	*this = src;
}

Ice::~Ice( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Ice &			Ice::operator = ( const Ice & rhs ) {

	if (this != &rhs) {
		AMateria::setXP(rhs.getXP());
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

AMateria	*Ice::clone() const {
	return ( (AMateria*) new Ice() );
}

void		Ice::use( ICharacter & target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
	          << std::endl;
	AMateria::use( target );
}
