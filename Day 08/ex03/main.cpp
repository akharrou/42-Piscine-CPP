/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 19:45:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	MindOpen	interpreter;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
		interpreter.load    ( "test1.mdp" );
		interpreter.execute ( "test1.mdp" );

		interpreter.load    ( "test2.mdp" );
		interpreter.execute ( "test2.mdp" );
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
		interpreter.load    ( "test1.mdp" );
		interpreter.load    ( "test2.mdp" );

		interpreter.executeAll();
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	return (0);
}
