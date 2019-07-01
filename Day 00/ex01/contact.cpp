/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/01 02:01:17 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() { };
Contact::Contact(	std::string first,
					std::string last,
					std::string nickname,
					std::string login,
					std::string postal,
					std::string email,
					std::string phone,
					std::string birthday,
					std::string favMeal,
					std::string undiColor,
					std::string darkestSecret	)
{
	_first          = first;
	_last           = last;
	_nickname       = nickname;
	_login          = login;
	_postal         = postal;
	_email          = email;
	_phone          = phone;
	_birthday       = birthday;
	_favMeal        = favMeal;
	_undiColor      = undiColor;
	_darkestSecret  = darkestSecret;
}
