/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:59:47 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/10 00:13:38 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void			Phonebook::welcome()
{
	std::cout << "\nWelcome to the Phonebook App ! \n" << std::endl;
	sleep(2);
}

void			Phonebook::prompt()
{
	CLEANUP;
	std::cout	<< "Available commands:\n\n"                              \
				<< " >> ADD:     " << ITALIC("(add a contact)\n")         \
				<< " >> SEARCH:  " << ITALIC("(search for a contact)\n")  \
				<< " >> EXIT:    " << ITALIC("(exit the program)\n")      \
				<< "\nEnter a command: ";
}

Phonebook&		Phonebook::add()
{
	CLEANUP;
	if (contact_index < MAX_CONTACTS)
		contacts[contact_index++].modify();
	else
		std::cout << \
		"Failed to add contact. " << ITALIC("(maximum capacity reached)") \
		<< std::endl;
	return (*this);
}

void			Phonebook::search()
{
	int			chosen_index;

	CLEANUP;
	if (contact_index == 0)
	{
		std::cout << "No contacts currently held." << std::endl;
		sleep(2);
		return ;
	}
	for (int i = 0; i < contact_index; i++)
	{
		std::cout << "| " << i << " | "                                \
				  << std::setw(10) << contacts[i].m_first    << " | "  \
				  << std::setw(10) << contacts[i].m_last     << " | "  \
				  << std::setw(10) << contacts[i].m_nickname << " |"   \
				  << std::endl;
	}
	std::cout << "\nSelect Contact Index: ";
	std::cin >> chosen_index;
	CLEANUP;
	std::cout << contacts[chosen_index].toString() << std::endl;
	std::cout << ITALIC("(Press enter to exit)");
	std::cin >> chosen_index;
}
