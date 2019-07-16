/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 20:18:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
	std::cout << "A Zombie " << "<" << _name << " (" << _type << ")>" << " has spawned." << std::endl;
}

Zombie::Zombie() : _name("undefined"), _type("undefined") {
}

Zombie::~Zombie() {
	std::cout << "<" << _name << " (" << _type << ")>" << " has died." << std::endl;
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Zombie::setName(std::string new_name) {
	_name = new_name;
}

void	Zombie::setType(std::string new_type) {
	_type = new_type;
}

/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Zombie::announce()
{
	std::cout << "<" << _name << " (" << _type << ")>"
			  << " Braiiiiiiinnnssss..." << std::endl;
}
