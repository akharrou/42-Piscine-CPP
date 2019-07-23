/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:59:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		Bureaucrat	person_1( "Xavier", 1   );
		Bureaucrat	person_2( "Kwame",  2   );
		Bureaucrat	person_3( "Gaetan", 150 );

		std::cout << person_1 << "\n";
		std::cout << person_2 << "\n";
		std::cout << person_3 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		ShrubberyCreationForm  	form_1( "home" );
		RobotomyRequestForm    	form_2( "bixby" );
		PresidentialPardonForm 	form_3( "Xavier Niel's Pardon Form" );

		std::cout << form_1 << "\n";
		std::cout << form_2 << "\n";
		std::cout << form_3 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		person_1.signForm(form_1);
		person_1.signForm(form_2);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << form_1 << "\n";
		std::cout << form_2 << "\n";
		std::cout << form_3 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		person_1.executeForm(form_1);
		person_2.executeForm(form_2);
		person_3.executeForm(form_3);
		person_2.executeForm(form_3);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		person_2.signForm(form_3);
		person_2.executeForm(form_3);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	}

	return (0);
}
