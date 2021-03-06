/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:19:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 15:15:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

DeepCoreMiner::DeepCoreMiner( void ) :
	_type("DeepCoreMiner") {
}

DeepCoreMiner::DeepCoreMiner( const DeepCoreMiner & src ) {
	*this = src;
}

DeepCoreMiner::~DeepCoreMiner( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

DeepCoreMiner &			DeepCoreMiner::operator = ( const DeepCoreMiner & rhs ) {

	(void)rhs;
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const std::string &		DeepCoreMiner::getType() const {
	return (_type);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	DeepCoreMiner::mine( IAsteroid *target ) {
	std::cout << "* mining deep ... got " << target->beMined( this ) << " ! *" << std::endl;
}
