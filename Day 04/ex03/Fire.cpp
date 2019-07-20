/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:08:51 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:12:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Fire::Fire( void ) :
	AMateria( "fire" ) {
}

Fire::Fire( const Fire & src ) {
	*this = src;
}

Fire::~Fire( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Fire &			Fire::operator = ( const Fire & rhs ) {

	if (this != &rhs) {
		AMateria::setXP(rhs.getXP());
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

AMateria	*Fire::clone() const {
	return ( (AMateria*) new Fire() );
}

void		Fire::use( ICharacter & target ) {

	std::cout << "* shoots a fire ball at " << target.getName() << " *"
	          << std::endl;
	AMateria::use( target );
}
