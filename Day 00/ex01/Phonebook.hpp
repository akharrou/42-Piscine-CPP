/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:05:34 by aymenkh           #+#    #+#             */
/*   Updated: 2019/07/15 10:25:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# include <stdlib.h>
# include <unistd.h>

# include <iostream>
# include <iomanip>
# include <string>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# define ITALIC(str)     ("\033[3m" str "\033[0m")
# define CLEARLINE       "\033[2K\r"
# define CLEARINPUTLINE  "\033[A\033[2K\r"
# define HOME            "\033[H"
# define CLEAR           "\033[2J"
# define CLEANUP { std::cout << CLEAR << HOME << std::endl; }

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

# define MAX_CONTACTS (8)

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

struct Phonebook {

	/// Phonebook Contact (class)
	class Contact {

		private:

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

			/// Contact Constructor
			Contact();

			/// Contact Methods
			Contact&	modify();
			std::string	toString();

			/// Accessors
			std::string	getFirst();
			std::string	getLast();
			std::string	getNickname();
	};

	/// Phonebook Attributes
	int			contact_index;
	Contact		contacts[MAX_CONTACTS];

	/// Phonebook Program Functions
	void		bootup();
	void		prompt();
	Phonebook&	add();
	int			preview();
	void		search();

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#endif /* PHONEBOOK_HPP */
