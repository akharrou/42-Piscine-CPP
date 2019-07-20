/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroBocal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:54:35 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 15:29:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AsteroBocal.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AsteroBocal::AsteroBocal( void )
	: _name("AsteroBocal") {
}

AsteroBocal::AsteroBocal( const AsteroBocal & src ) {
	*this = src;
}

AsteroBocal::~AsteroBocal( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AsteroBocal &	AsteroBocal::operator = ( const AsteroBocal & rhs ) {
	(void)rhs;
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AsteroBocal::getName() const {
	return (_name);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AsteroBocal::beMined( StripMiner const * ) const {
	return ("Flavium");
}

std::string		AsteroBocal::beMined( DeepCoreMiner const * ) const {
	return ("Thorite");
}
