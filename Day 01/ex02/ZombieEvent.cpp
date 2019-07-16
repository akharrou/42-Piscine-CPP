/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 19:50:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "ZombieEvent.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

ZombieEvent::ZombieEvent(std::string type) : _type(type) {
	std::cout << "A ZombieEvent has been created." << std::endl;
}

ZombieEvent::~ZombieEvent() {
	std::cout << "A ZombieEvent has died." << std::endl;
}


/* ACCESSORS — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	ZombieEvent::setZombieType(std::string type)
{
	_type = type;
}


/* MEMBER FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, _type));
}

Zombie	*ZombieEvent::randomChump()
{
	Zombie *instance;

	instance = newZombie(zombieNames[rand() % nZombieNames]);
	instance->announce();
	return (instance);
}


/* STATIC VARIABLES  — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string ZombieEvent::zombieNames[] = { "James", "John", "Steven", "Gilbert",
                                           "Marcus", "Stewy", "Herald", "Lenard",
                                           "Bob", "Pat" };

int ZombieEvent::nZombieNames = 10;
