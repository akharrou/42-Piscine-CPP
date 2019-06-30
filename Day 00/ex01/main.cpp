/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/06/30 00:12:22 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      Displays to stdout command the command line arguments
**      passed in uppercase.
*/

#include <iostream>
#include <unistd.h>

#define ITATLIC  "\033[3m"
#define DEFAULT  "\033[0m"
#define CLEAR    "\033[2J"
#define HOME     "\033[H"
#define CLEANUP  { std::cout << CLEAR << HOME << std::endl; }

int	main(void)
{
	int command;

	std::cout << "\nWelcome to PhoneBook ! \n" << std::endl;
	sleep(2);
	CLEANUP;

	while (1)
	{
		std::cout << "Press a command:\n\n";
		std::cout << "   >> ADD     " << ITATLIC << "(press 1)\n" << DEFAULT;
		std::cout << "   >> SEARCH  " << ITATLIC << "(press 2)\n" << DEFAULT;
		std::cout << "   >> EXIT    " << ITATLIC << "(press 3)\n" << DEFAULT;
		std::cout << std::endl;
		cin >> command;
		if (command == ADD)
			/* add function */
		else if (command == SEARCH)
			/* search function */
		else
			break ;
		sleep(3);
		CLEANUP;
	}

	return (0);
}
