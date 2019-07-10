/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:05:34 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/09 23:40:42 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# include <unistd.h>

# include <iostream>
# include <iomanip>
# include <string>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# define ITALIC(str) ("\033[3m" str "\033[0m")
# define CLEAR "\033[2J"
# define HOME  "\033[H"
# define CLEANUP { std::cout << CLEAR << HOME << std::endl; }

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# define MAX_CONTACTS (8)

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

struct Phonebook {

	class Contact {

		public:

			std::string m_first;
			std::string m_last;
			std::string m_nickname;
			std::string m_login;
			std::string m_postal;
			std::string m_email;
			std::string m_phone;
			std::string m_birthday;
			std::string m_fav_meal;
			std::string m_color;
			std::string m_darkest_secret;

		public:

			/// Constructor
			Contact();

			/// Modify Contact Information
			Contact& modify();

			/// String Representation
			std::string toString();
	};

	/// Phonebook Program Functions
	void			welcome();
	void			prompt();
	Phonebook&		add();
	void			search();

	private:
		Contact		contacts[MAX_CONTACTS];
		int			contact_index;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#endif /* PHONEBOOK_HPP */
