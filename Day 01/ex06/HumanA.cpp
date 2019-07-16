/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 12:07:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

HumanA::HumanA(std::string name, Weapon& weapon)
	: _name(name), _wep(weapon) { }

HumanA::~HumanA() { }


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	HumanA::attack() const {
	std::cout << _name << " attacks with his " << _wep.getType() << std::endl;
}
