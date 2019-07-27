/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 20:28:58 by akharrou         ###   ########.fr       */
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
		interpreter.load    ( "test2.mdp" );
		interpreter.load    ( "test3.mdp" );

		std::cout << "\nProgram #1 Output :\n";
		interpreter.execute ( "test1.mdp" );

		std::cout << "\nProgram #2 Output :\n";
		interpreter.execute ( "test2.mdp" );

		std::cout << "\nProgram #3 Output :\n";
		interpreter.execute ( "test3.mdp" );

	std::cout << "\n\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		try {

			interpreter.execute ( "doesn't exist" );

		} catch ( std::exception & e ) {
			std::cout << e.what();
		}

	std::cout << "\n\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		try {

			interpreter.load    ( "some non existant file" );
			interpreter.execute ( "some non existant file" );

		} catch ( std::exception & e ) {
			std::cout << e.what();
		}

	}

	std::cout << "\n\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
		interpreter.load    ( "test1.mdp" );
		interpreter.load    ( "test2.mdp" );
		interpreter.load    ( "test3.mdp" );

		interpreter.executeAll();
	}

	std::cout << "\n\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	return (0);
}
