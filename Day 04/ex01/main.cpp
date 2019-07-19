/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:18:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:33:55 by akharrou         ###   ########.fr       */
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

		delete (zaz)  ;
		delete (pr)  ;
		delete (pf)  ;
	}

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

	{
		Character		player1("Xavier");
		Character		player2("Kwame");

		PlasmaRifle 	Executioner;
		PowerFist 		Knuckles;

		Enemy			*Gaetan0 = new RadScorpion();
		Enemy			*Gaetan1 = new RadScorpion();
		Enemy			*Gaetan2 = new SuperMutant();

		std::cout << std::endl;

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		player1.equip(&Executioner);
		player2.equip(&Knuckles);

		std::cout << Executioner << std::endl;
		std::cout << Knuckles    << std::endl;

		std::cout << std::endl;

		std::cout << player1;
		std::cout << player2;

		std::cout << std::endl;

		std::cout << *Gaetan0 << std::endl;
		std::cout << *Gaetan1 << std::endl;
		std::cout << *Gaetan2 << std::endl;

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		std::cout << std::endl;

		player1.attack( Gaetan0 );
		std::cout << player1;
		std::cout << *Gaetan0 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan0 );
		std::cout << player1;
		std::cout << *Gaetan0 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan0 );
		std::cout << player1;
		std::cout << *Gaetan0 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan0 );
		std::cout << player1;
		std::cout << *Gaetan0 << std::endl;

		std::cout << std::endl;

		std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";

		std::cout << std::endl;

		player1.attack( Gaetan1 );
		std::cout << player1;
		std::cout << *Gaetan1 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan1 );
		std::cout << player1;
		std::cout << *Gaetan1 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan1 );
		std::cout << player1;
		std::cout << *Gaetan1 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan1 );
		std::cout << player1;
		std::cout << *Gaetan1 << std::endl;

		std::cout << std::endl;

		std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";

		player1.attack( Gaetan2 );
		std::cout << player1;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		player1.attack( Gaetan2 );
		std::cout << player1;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		std::cout << Knuckles << std::endl << std::endl;

		player2.attack( Gaetan2 );
		std::cout << player2;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		player2.attack( Gaetan2 );
		std::cout << player2;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		player2.attack( Gaetan2 );
		std::cout << player2;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		player2.attack( Gaetan2 );
		std::cout << player2;
		std::cout << *Gaetan2 << std::endl;

		std::cout << std::endl;

		std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		player1.recoverAP( );
		std::cout << player1;
		player1.recoverAP( );
		std::cout << player1;
		player1.recoverAP( );
		std::cout << player1;
		player1.recoverAP( );
		std::cout << player1;

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		player2.recoverAP( );
		std::cout << player2;
		player2.recoverAP( );
		std::cout << player2;
		player2.recoverAP( );
		std::cout << player2;
		player2.recoverAP( );
		std::cout << player2;

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

	}

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}
