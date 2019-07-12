/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/10 00:49:24 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      .
**
** — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
*/

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook		phonebook;
	std::string		command;

	phonebook.welcome();
	while (1)
	{
		phonebook.prompt();
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			std::exit(1);
		else
			continue ;
	}
	return (0);
}
