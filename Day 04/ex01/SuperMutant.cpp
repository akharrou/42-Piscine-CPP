/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:14:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:14:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

SuperMutant::SuperMutant( void )
	: Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant( const SuperMutant & src ) {
	*this = src;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ..." << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

SuperMutant &			SuperMutant::operator = ( const SuperMutant & rhs ) {

	if (this != &rhs) {
        _type           = rhs._type;
        _hit_points     = rhs._hit_points;
        _max_hit_points = rhs._max_hit_points;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void	SuperMutant::takeDamage( int amount ) {
	Enemy::takeDamage(amount - 3);
}
