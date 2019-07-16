/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 19:53:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	main() {

	// Stack Allocations — — — — — — — — — — — — — — — — — //

	ZombieEvent	zEvent1("42 Student");
	ZombieEvent	zEvent2("42 Staff");
	ZombieEvent	zEvent3("Gorilla");

	Zombie		z1("Kevin", "42 Student");
	Zombie		z2("Louis", "42 Staff");

	// Heap Allocations — — — — — — — — — — — — — — — — — //

	Zombie		*z3 = new Zombie("Jackson", "42 Student");
	Zombie		*z4 = new Zombie("Ferris", "42 Staff");

	Zombie		*z5 = zEvent1.randomChump();
	Zombie		*z6 = zEvent2.randomChump();

	zEvent3.setZombieType("42 Founder");
	Zombie		*z7 = zEvent3.newZombie("Xavier");



	// Some action...

	z1.announce();
	z2.announce();
	(*z3).announce();
	(*z4).announce();
	(*z5).announce();
	(*z6).announce();
	(*z7).announce();



	// Deallocation — — — — — — — — — — — — — — — — — — //

	delete (z3);
	delete (z4);
	delete (z5);
	delete (z6);
	delete (z7);


	return (0);
}
