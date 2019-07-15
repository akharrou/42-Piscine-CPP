/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:59:47 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/15 10:28:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void			Phonebook::bootup()
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
	{
		contacts[contact_index++].modify();
		std::cout << "\n\n[√] Contact Successfully Added." << std::endl;
		sleep(1);
	}
	else
	{
		CLEANUP;
		std::cout << ITALIC("Maximum capacity reached.") << std::endl;
		sleep(2);
	}
	return (*this);
}

int			Phonebook::preview()
{
	std::string first;
	std::string last;
	std::string nickname;

	CLEANUP;
	if (contact_index == 0)
	{
		std::cout << "No contacts currently held." << std::endl;
		sleep(2);
		return (-1);
	}

	for (int i = 0; i < contact_index; i++)
	{

		first		= contacts[i].getFirst();
		last		= contacts[i].getLast();
		nickname	= contacts[i].getNickname();
		if (first.length() > 9)
		{
			first[9] = '.';
			first[10] = '\0';
		}
		if (last.length() > 9)
		{
			last[9] = '.';
			last[10] = '\0';
		}
		if (nickname.length() > 9)
		{
			nickname[9] = '.';
			nickname[10] = '\0';
		}

		std::cout << "| " << i << " | "                  \
				  << std::setw(10) << first.c_str()    << " | "  \
				  << std::setw(10) << last.c_str()     << " | "  \
				  << std::setw(10) << nickname.c_str() << " |"   \
				  << std::endl;
	}

	return (0);
}

void			Phonebook::search()
{
	std::string	input;
	int			idx;

	if (this->preview() == -1)
		return ;
	std::cout << std::endl << std::endl;
	do {
		std::cout << CLEARINPUTLINE << std::flush;
		std::cout << "Choose a contact (index): " << std::flush;
		std::cin >> input;
		idx = atoi(input.c_str());
	} while (input.length() > 1 || !std::isdigit(input[0]) ||
		idx < 0 || idx >= contact_index);

	CLEANUP;
	std::cout << contacts[idx].toString() << std::endl;
	std::cout << ITALIC("\n(enter '1' to go to menu)") << std::endl;
	std::cin >> input;
}
