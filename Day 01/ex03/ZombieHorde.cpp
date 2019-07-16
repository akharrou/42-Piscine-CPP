/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:58:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 21:29:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

ZombieHorde::ZombieHorde( int N ) : _N(N), _horde(new Zombie[N]) {

	for (int i = 0; i < _N; ++i) {
		_horde[i].setName(zombieNames[rand() % nZombieNames]);
		_horde[i].setType(zombieTypes[rand() % nZombieTypes]);
	}

	std::cout << "A horde of " << _N << " zombies has spawned !" << std::endl;
}

ZombieHorde::~ZombieHorde() {

	delete [] (_horde);

	std::cout << "A horde of " << _N << " zombies has perished !" << std::endl;
}


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	ZombieHorde::announce()
{
	for (int i = 0; i < _N; ++i) {
		_horde[i].announce();
	}
}


/* STATIC VARIABLE(S)  — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string	ZombieHorde::zombieNames[10] = { "James", "John", "Steven", "Gilbert",
                                             "Marcus", "Stewy", "Herald", "Lenard",
                                             "Bob", "Pat" };

std::string	ZombieHorde::zombieTypes[3] = { "42 Staff", "42 Student", "42 Founder"};

int			ZombieHorde::nZombieNames = 10;
int			ZombieHorde::nZombieTypes = 3;
