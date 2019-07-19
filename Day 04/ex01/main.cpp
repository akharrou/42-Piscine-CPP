/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:18:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:02:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	main() {

	{
		Character	*zaz = new Character("zaz");

		std::cout << *zaz;

		Enemy		*b = new RadScorpion();

		AWeapon		*pr = new PlasmaRifle();
		AWeapon		*pf = new PowerFist();

		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);

		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
	}

	return (0);
}
