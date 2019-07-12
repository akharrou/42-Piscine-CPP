/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/11 18:40:21 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Contact::Contact()
{
	m_first           = "empty";
	m_last            = "empty";
	m_nickname        = "empty";
	m_login           = "empty";
	m_postal          = "empty";
	m_email           = "empty";
	m_phone           = "empty";
	m_birthday        = "empty";
	m_fav_meal        = "empty";
	m_color           = "empty";
	m_darkest_secret  = "empty";
}

Phonebook::Contact& Phonebook::Contact::modify()
{
	std::cout << "First Name: " << std::endl;
	std::getline(std::cin, m_first);

	std::cout << std::endl << "Last Name: " << std::endl;
	std::getline(std::cin, m_last);

	std::cout << std::endl << "Nickname: " << std::endl;
	std::getline(std::cin, m_nickname);

	std::cout << std::endl << "Login: " << std::endl;
	std::getline(std::cin, m_login);

	std::cout << std::endl << "Postal Code: " << std::endl;
	std::getline(std::cin, m_postal);

	std::cout << std::endl << "Email: " << std::endl;
	std::getline(std::cin, m_email);

	std::cout << std::endl << "Phone Number: " << std::endl;
	std::getline(std::cin, m_phone);

	std::cout << std::endl << "Birthday: " << std::endl;
	std::getline(std::cin, m_birthday);

	std::cout << std::endl << "Favorite Meal: " << std::endl;
	std::getline(std::cin, m_fav_meal);

	std::cout << std::endl << "Color: " << std::endl;
	std::getline(std::cin, m_color);

	std::cout << std::endl <<
	"Darkest Secret: " << ITALIC("(terminate with '$\\n')") \
	<< std::endl;

	std::string tmp;
	while (std::getline(std::cin, tmp) && tmp[tmp.length() - 1] != '$')
		m_darkest_secret += tmp + "\n";
	tmp[tmp.length() - 1] = '\0';
	m_darkest_secret += tmp;

	return (*this);
}

std::string Phonebook::Contact::toString()
{
	return (
		" ——————————————————————————————————————————\n"
		"| First Name     | " + m_first          + "\n"
		"———————————————————————————————————————————\n"
		"| Last Name      | " + m_last           + "\n"
		"———————————————————————————————————————————\n"
		"| Nickname       | " + m_nickname       + "\n"
		"———————————————————————————————————————————\n"
		"| Login          | " + m_login          + "\n"
		"———————————————————————————————————————————\n"
		"| Postal         | " + m_postal         + "\n"
		"———————————————————————————————————————————\n"
		"| Email          | " + m_email          + "\n"
		"———————————————————————————————————————————\n"
		"| Phone          | " + m_phone          + "\n"
		"———————————————————————————————————————————\n"
		"| Birthday       | " + m_birthday       + "\n"
		"———————————————————————————————————————————\n"
		"| Favorite Meal  | " + m_fav_meal       + "\n"
		"———————————————————————————————————————————\n"
		"| Color          | " + m_color          + "\n"
		"———————————————————————————————————————————\n\n"
		"PS -- Darkest Secret :\n\n"
		"\033[3m" + m_darkest_secret + "\033[0m" + "\n"
	);
}
