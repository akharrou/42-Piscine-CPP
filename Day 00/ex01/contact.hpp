/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 23:05:36 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/01 02:04:38 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include "Contact.hpp"
#include <string>

class Contact {

	private:

		std::string _first;
		std::string _last;
		std::string _nickname;
		std::string _login;
		std::string _postal;
		std::string _email;
		std::string _phone;
		std::string _birthday;
		std::string _favMeal;
		std::string _undiColor;
		std::string _darkestSecret;

	public:

		/// Default Constructor
		Contact();

		/// Initialized Constructor
		Contact(std::string first,
				std::string last,
				std::string nickname,
				std::string login,
				std::string postal,
				std::string email,
				std::string phone,
				std::string birthday,
				std::string favMeal,
				std::string undiColor,
				std::string darkestSecret);

};

#endif /* CONTACT_H */
