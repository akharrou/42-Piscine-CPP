/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 12:16:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

HumanB::HumanB(std::string name)
	: _name(name) { }

HumanB::~HumanB() { }


/* ACCESSORS(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void			HumanB::setWeapon(Weapon& weapon) {
	_wep = &weapon;
}


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	HumanB::attack() const {
	std::cout << _name << " attacks with his " << _wep->getType() << std::endl;
}
