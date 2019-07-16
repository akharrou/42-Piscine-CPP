/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 19:52:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
	std::cout << "A Zombie " << "<" << _name << " (" << _type << ")>" << " has spawned." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "<" << _name << " (" << _type << ")>" << " has died." << std::endl;
}


/* MEMBER FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Zombie::announce()
{
	std::cout << "<" << _name << " (" << _type << ")>"
			  << " Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setType(std::string new_type)
{
	_type = new_type;
}
