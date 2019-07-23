/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 20:36:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		Bureaucrat	person_1( "Xavier", 1   );
		Intern		Gaetan;

		std::cout << person_1 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		AForm	*form_1 = Gaetan.makeForm( "shrubbery creation" ,   "home"         );
		AForm	*form_2 = Gaetan.makeForm( "robotomy request" ,     "bixby"        );
		AForm	*form_3 = Gaetan.makeForm( "presidential pardon" ,  "Xaiver Niel"  );
		AForm	*form_4 = Gaetan.makeForm( "42 application" ,       "Gaetan's son" );

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << *form_1 << "\n";
		person_1.signForm(*form_1);
		std::cout << "\n" << *form_1 << "\n";

		std::cout << *form_2 << "\n";
		person_1.signForm(*form_2);
		std::cout << "\n" << *form_2 << "\n";

		std::cout << *form_3 << "\n";
		person_1.signForm(*form_3);
		std::cout << "\n" << *form_3 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		person_1.executeForm(*form_1);
		person_1.executeForm(*form_2);
		person_1.executeForm(*form_3);
		(void) form_4;

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	}

	return (0);
}
