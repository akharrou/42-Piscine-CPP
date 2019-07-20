/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:56 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 21:30:50 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

#include "TacticalMarine.hpp"
#include "Squad.hpp"

#include "AssaultTerminator.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	main() {

	{
		ISpaceMarine	*bob = new TacticalMarine;
		ISpaceMarine	*jim = new AssaultTerminator;
		ISquad			*vlc = new Squad;

		vlc->push(bob);
		vlc->push(jim);
		for ( int i = 0; i < vlc->getCount(); ++i )
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{

		Squad	*army       = new Squad;
		Squad	*armyCopy_0 = new Squad;
		Squad	*armyCopy_1 = new Squad;
		Squad	*armyCopy_2 = new Squad;

		std::cout << "\nArmy Squand Count: " << army->getCount() << "\n";

		*armyCopy_0 = *army;

		std::cout << "\n*armyCopy_0 = *army;" << std::endl;
		std::cout << "armyCopy_0 Squad Count : " << armyCopy_0->getCount() << std::endl << std::endl;

		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);

		std::cout << "\n*armyCopy_1 = *army;\n" << std::endl;
		*armyCopy_1 = *army;

		std::cout << "\narmyCopy_1 Squad Count : " << armyCopy_1->getCount() << std::endl;
		std::cout << "Army Squand Count: " << army->getCount() << "\n\n";

		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);
		army->push(new TacticalMarine);
		army->push(new AssaultTerminator);

		std::cout << "\n*armyCopy_1 = *army;\n" << std::endl;

		*armyCopy_1 = *army;

		std::cout << "\n*armyCopy_2 = *army;\n" << std::endl;

		*armyCopy_2 = *army;

		std::cout << "\narmyCopy_0 Squad Count : " << armyCopy_0->getCount() << std::endl;
		std::cout << "armyCopy_1 Squad Count : " << armyCopy_1->getCount() << std::endl;
		std::cout << "armyCopy_2 Squad Count : " << armyCopy_2->getCount() << std::endl;
		std::cout << "Army Squand Count: " << army->getCount() << "\n\n";

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nArmy:\n\n";

		for ( int i = 0; i < army->getCount(); i += 5 ) {

			std::cout << "Unit #" << i << ":" << std::endl;

			army->getUnit(i)->battleCry();
			army->getUnit(i)->rangedAttack();
			army->getUnit(i)->meleeAttack();

			std::cout << std::endl;
		}

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nArmy #0:\n\n";

		for ( int i = 0; i < armyCopy_0->getCount(); i += 5 ) {

			std::cout << "Unit #" << i << ":" << std::endl;

			armyCopy_0->getUnit(i)->battleCry();
			armyCopy_0->getUnit(i)->rangedAttack();
			armyCopy_0->getUnit(i)->meleeAttack();

			std::cout << std::endl;
		}

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nArmy #1:\n\n";

		for ( int i = 0; i < armyCopy_1->getCount(); i += 5 ) {

			std::cout << "Unit #" << i << ":" << std::endl;

			armyCopy_1->getUnit(i)->battleCry();
			armyCopy_1->getUnit(i)->rangedAttack();
			armyCopy_1->getUnit(i)->meleeAttack();

			std::cout << std::endl;
		}

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nArmy #2:\n\n";

		for ( int i = 0; i < armyCopy_2->getCount(); i += 5 ) {

			std::cout << "Unit #" << i << ":" << std::endl;

			armyCopy_2->getUnit(i)->battleCry();
			armyCopy_2->getUnit(i)->rangedAttack();
			armyCopy_2->getUnit(i)->meleeAttack();

			std::cout << std::endl;
			std::cout << std::endl;
		}

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nDelete Army :\n\n";

		delete (army);

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nDelete Army 0:\n\n";

		delete (armyCopy_0);

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nDelete Army 1:\n\n";

		delete (armyCopy_1);

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nDelete Army 2:\n\n";

		delete (armyCopy_2);

	}

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}
