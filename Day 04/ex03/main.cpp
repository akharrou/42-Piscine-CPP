/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:39:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 19:53:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

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

	}

	return (0);
}
