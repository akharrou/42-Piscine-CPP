/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:46:13 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 12:46:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

PlasmaRifle::PlasmaRifle( void )
	: AWeapon("Plasma Rifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle( const PlasmaRifle & src ) {
	*this = src;
}

PlasmaRifle::~PlasmaRifle( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

PlasmaRifle &			PlasmaRifle::operator = ( const PlasmaRifle & rhs ) {

	if (this != &rhs) {
        _name          = rhs._name;
        _damage_points = rhs._damage_points;
        _action_points = rhs._action_points;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void	PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
