/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/16 12:18:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      Rudementary phonebook application.
*/

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#include "Phonebook.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

int	main(void)
{
	Phonebook		phonebook;
	std::string		command;

	phonebook.bootup();
	phonebook.contact_index = 0;
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
