/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BocalSteroid.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:54:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:47:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BocalSteroid.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

BocalSteroid::BocalSteroid( void )
	: _name("BocalSteroid") {
}

BocalSteroid::BocalSteroid( const BocalSteroid & src ) {
	*this = src;
}

BocalSteroid::~BocalSteroid( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

BocalSteroid &	BocalSteroid::operator = ( const BocalSteroid & rhs ) {
	(void)rhs;
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		BocalSteroid::getName() const {
	return (_name);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		BocalSteroid::beMined( StripMiner const * ) const {
	return ("Krpite");
}

std::string		BocalSteroid::beMined( DeepCoreMiner const * ) const {
	return ("Zazium");
}
