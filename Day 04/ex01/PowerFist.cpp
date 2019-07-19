/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:45:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 12:45:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

PowerFist::PowerFist( void )
	: AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist( const PowerFist & src ) {
	*this = src;
}

PowerFist::~PowerFist( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

PowerFist &			PowerFist::operator = ( const PowerFist & rhs ) {

	if (this != &rhs) {
        _name          = rhs._name;
        _damage_points = rhs._damage_points;
        _action_points = rhs._action_points;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void	PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
