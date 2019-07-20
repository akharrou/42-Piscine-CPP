/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:51:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 11:52:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Cure::Cure( void ) :
	AMateria( "cure" ) {
}

Cure::Cure( const Cure & src ) {
	*this = src;
}

Cure::~Cure( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Cure &			Cure::operator = ( const Cure & rhs ) {

	if (this != &rhs) {
		AMateria::setXP(rhs.getXP());
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

AMateria	*Cure::clone() const {
	return ( (AMateria*) new Cure() );
}

void		Cure::use( ICharacter & target ) {

	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use( target );
}
