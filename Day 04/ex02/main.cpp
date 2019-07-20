/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:56 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:53:39 by akharrou         ###   ########.fr       */
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
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	{




	}

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}

/*

Tactical Marine ready for battle$
* teleports from space *$
For the holy PLOT !$
* attacks with bolter *$
* attacks with chainsword *$
This code is unclean. PURIFY IT !$
* does nothing *$
* attacks with chainfists *$
Aaargh ...$
I'll be back ...$

*/
