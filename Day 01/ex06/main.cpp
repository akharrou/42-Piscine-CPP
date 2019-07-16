/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 12:16:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main() {

	{ /* it would be fine to store weapon as a reference,
		cuz in this class we can only instantiate a HumanA
		object with a weapon initialized; also the class
		does not allow the weapon to be set again */

		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("soft pillow ended club");
		bob.attack();
	}

	{ /* better to store weapon as a pointer, cuz here we
		have instantiate a HumanB with an uninitialized
		weapon, then set a weapon, and then weapon can
		potentially change latter down the road again,
		with another setWeapon() call */

		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("beautiful unicorn face club");
		jim.attack();
	}

	return (0);
}
