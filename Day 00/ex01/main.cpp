/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/01 02:01:41 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      .
**
** — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
*/

#include <iostream>
#include <unistd.h>

#include "Contact.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#define ITATLIC(str) ("\033[3m" str "\033[0m")
#define CLEAR "\033[2J"
#define HOME "\033[H"
#define CLEANUP { std::cout << CLEAR << HOME << std::endl; }

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

int	main(void)
{
	Contact::Contact	phonebook[8];
	std::string			command;

	std::cout << "\nWelcome to PhoneBook ! \n" << std::endl;
	sleep(2);
	CLEANUP;

	while (1)
	{
		CLEANUP;
		std::cout << "Available commands:" << std::endl << std::endl;
		std::cout << " >> ADD:     " << ITATLIC("(add a contact)\n");
		std::cout << " >> SEARCH:  " << ITATLIC("(search for a contact)\n");
		std::cout << " >> EXIT:    " << ITATLIC("(exit the program)\n");
		std::cout << "\nEnter a command: ";
		std::cin >> command;
		std::cout << std::endl;

		if (command == "ADD")
		{
			std::cout << "ADD was pressed" << std::endl;

		}
		else if (command == "SEARCH")
		{
			std::cout << "SEARCH was pressed" << std::endl;

		}
		else if (command == "EXIT")
		{
			std::exit(1);
		}
		else
		{
			continue ;
		}
	}
	return (0);
}
