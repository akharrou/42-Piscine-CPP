/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:19:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 10:38:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main() {

	{
		Sorcerer	robert("Robert", "the Magnificent");
		Victim		jim("Jimmy");
		Peon		joe("Joe");

		std::cout << robert << jim << joe;

		robert.polymorph(jim);
		robert.polymorph(joe);
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
		Sorcerer	robert("Robert", "the Magnificent");

		Victim	*chosen_victims[23] =
		{
			new Victim("Jimmy 1.5"),
			new Peon("Joe 1"),
			new Victim("Jimmy 1.2"),
			new Peon("Joe 1.4"),
			new Victim("Jimmy 2.1"),
			new Peon("Joe 3"),
			new Victim("Jimmy 2.5"),
			new Peon("Joe 1."),
			new Victim("Jimmy 1.3"),
			new Peon("Joe 2"),
			new Victim("Jimmy 1.1"),
			new Peon("Joe 5"),
			new Victim("Jimmy 2.2"),
			new Peon("Joe 1.5"),
			new Peon("Joe 4"),
			new Victim("Jimmy 2.4"),
			new Victim("Jimmy 1.4"),
			new Peon("Joe 1.2"),
			new Victim("Jimmy Original"),
			new Peon("Joe 1.3"),
			new Peon("Joe"),
			new Victim("Jimmy 2.3"),
			new Peon("Joe 1.1"),
		};

		std::cout << std::endl;

		for ( int i = 0; i < 23; ++i ) {
			std::cout << *(chosen_victims[i]);
		}

		std::cout << std::endl;
		std::cout << std::endl;

		for ( int i = 0; i < 23; ++i ) {
			robert.polymorph(*chosen_victims[i]);
		}

		std::cout << std::endl;
		std::cout << std::endl;

		for ( int i = 0; i < 23; ++i ) {
			delete chosen_victims[i];
		}

		std::cout << std::endl;
	}

	return (0);
}
