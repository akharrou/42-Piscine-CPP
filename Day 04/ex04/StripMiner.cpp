/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:19:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 15:15:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

StripMiner::StripMiner( void ) :
	_type("StripMiner") {
}

StripMiner::StripMiner( const StripMiner & src ) {
	*this = src;
}

StripMiner::~StripMiner( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

StripMiner &			StripMiner::operator = ( const StripMiner & rhs ) {

	(void)rhs;
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const std::string &		StripMiner::getType() const {
	return (_type);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	StripMiner::mine( IAsteroid *target ) {
	std::cout << "* strip mining ... got " << target->beMined( this ) << " ! *" << std::endl;
}
