/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:58:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 20:21:53 by akharrou         ###   ########.fr       */
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


/* MEMBER FUNCTIONS — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	ZombieHorde::announce()
{
	for (int i = 0; i < _N; ++i) {
		_horde[i].announce();
	}
}


std::string	zombieNames[] = { "", "", "", "", "" };
std::string	zombieTypes[] = { "", "", "", "", "" };
int			nZombieNames = ;
int			nZombieTypes = ;
