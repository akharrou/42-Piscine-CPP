/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:39:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:49:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Electricity.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* zaz = new Character("zaz");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		zaz->equip(tmp);
		tmp = src->createMateria("cure");
		zaz->equip(tmp);

		ICharacter* bob = new Character("bob");

		zaz->use(0, *bob);
		zaz->use(1, *bob);

		delete bob;
		delete zaz;
		delete src;
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
        ICharacter		*mage   = new Character("Xavier");
        ICharacter		*healer = new Character("Kwame");
        ICharacter		*victim = new Character("Gaetan");

		IMateriaSource	*alchemist = new MateriaSource();

        AMateria	*healers_cure      = NULL;
        AMateria	*mages_ice         = NULL;
        AMateria	*mages_fire        = NULL;
        AMateria	*mages_sniper      = NULL;
        AMateria	*mages_electricity = NULL;

		alchemist->learnMateria(new Cure());
		alchemist->learnMateria(new Ice());
		alchemist->learnMateria(NULL);
		alchemist->learnMateria(new Fire());
		alchemist->learnMateria(new Electricity());

        healers_cure      = alchemist->createMateria("cure");
        mages_ice         = alchemist->createMateria("ice");
        mages_fire        = alchemist->createMateria("fire");
		mages_sniper      = alchemist->createMateria("sniper");
        mages_electricity = alchemist->createMateria("electricity");

		healer ->equip (healers_cure);
		mage   ->equip (mages_ice);
		mage   ->equip (mages_fire);
		mage   ->equip (mages_sniper);
		mage   ->equip (mages_electricity);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		std::cout << mage->getName() << " "; mage->use(0, *victim);
		std::cout << mage->getName() << " "; mage->use(1, *victim);
		std::cout << mage->getName() << " "; mage->use(2, *victim);
		std::cout << mage->getName() << " "; mage->use(3, *victim);
		std::cout << std::endl;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << mage->getName() << " "; mage->use(0, *victim);
		std::cout << mage->getName() << " "; mage->use(1, *victim);
		std::cout << mage->getName() << " "; mage->use(2, *victim);
		std::cout << mage->getName() << " "; mage->use(3, *victim);
		std::cout << std::endl;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << healer->getName() << " "; healer->use(0, *victim);
		std::cout << healer->getName() << " "; healer->use(0, *victim);
		std::cout << healer->getName() << " "; healer->use(0, *victim);

		std::cout << healer->getName() << " "; healer->use(1, *victim);
		std::cout << std::endl;
		std::cout << healer->getName() << " "; healer->use(2, *victim);
		std::cout << std::endl;
		std::cout << healer->getName() << " "; healer->use(3, *victim);
		std::cout << std::endl;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		AMateria	*GaetansElectricity = alchemist->createMateria("electricity");

		victim->equip(GaetansElectricity);

		std::cout << victim->getName() << " "; victim->use(0, *mage);
		victim->unequip(0);
		std::cout << victim->getName() << " "; victim->use(0, *mage);
		std::cout << "\n\nGaetansElectricity : " << *GaetansElectricity;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	std::cout << "<mage> " << mage->getName() << " : has the following matieras :\n" << std::endl;

	if (mages_ice)
		std::cout << *mages_ice;
	else
		std::cout << "(null)\n";

	if (mages_fire)
		std::cout << *mages_fire;
	else
		std::cout << "(null)\n";

	if (mages_sniper)
		std::cout << *mages_sniper;
	else
		std::cout << "(null)\n";

	if (mages_electricity)
		std::cout << *mages_electricity;
	else
		std::cout << "(null)\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << "<healer> " << healer->getName() << " : has the following matieras :\n" << std::endl;

		std::cout << *healers_cure;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		delete (mage);
		delete (healer);
		delete (victim);

		delete (GaetansElectricity);
	}

	return (0);
}
