/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 12:16:26 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Weapon::Weapon(std::string type)
	: _type(type) { }

Weapon::~Weapon() { }


/* ACCESSORS(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

const std::string&	Weapon::getType() const {
	return (_type);
}

void				Weapon::setType(std::string new_type) {
	_type = new_type;
}
