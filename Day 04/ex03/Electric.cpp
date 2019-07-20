/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electric.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:08:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:12:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Electricity.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Electricity::Electricity( void ) :
	AMateria( "electricity" ) {
}

Electricity::Electricity( const Electricity & src ) {
	*this = src;
}

Electricity::~Electricity( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Electricity &			Electricity::operator = ( const Electricity & rhs ) {

	if (this != &rhs) {
		AMateria::setXP(rhs.getXP());
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

AMateria	*Electricity::clone() const {
	return ( (AMateria*) new Electricity() );
}

void		Electricity::use( ICharacter & target ) {

	std::cout << "* electrifies " << target.getName() << " *"
	          << std::endl;
	AMateria::use( target );
}
