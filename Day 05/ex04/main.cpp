/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 00:39:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "OfficeBlock.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;

		ob.setIntern(&idiotOne);
		ob.setSigningBureaucrat(&bob);
		ob.setExecutingBureaucrat(&hermes);

		ob.doBureaucracy("mutant pig termination", "Pigley");
	}

	// {

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	Bureaucrat  person_1( "Kwame",       2 );
	// 	Bureaucrat  person_2( "Xavier Niel", 1 );
	// 	Intern      Gaetan;

	// 	OfficeBlock	bocal( &person_1, &person_2, &Gaetan );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	bocal.doBureaucracy( "shrubbery creation", "home" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	bocal.doBureaucracy( "robotomy request", "bixby" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	bocal.doBureaucracy( "presidential pardon", "* some president *" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nTEST #1 : UNKNOWN\n\n";

	// 	bocal.doBureaucracy( "42 dorm request", "pisciner" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	Bureaucrat	cadet_1    ( "Cadet #1", 20  );
	// 	Bureaucrat	cadet_2    ( "Cadet #2", 73  );
	// 	Intern		pisciner_1;

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
	// std::cout << "TEST #2: LOW EXECUTE GRADE : ( sign = 25 ; exec = 5 )\n\n";

	// 	std::cout << "bocal.setSigningBureaucrat   ( & cadet_1    );\n";
	// 	std::cout << "bocal.setExecutingBureaucrat ( & cadet_2    );\n";
	// 	std::cout << "bocal.setIntern              ( & pisciner_1 );\n\n";

	// 	bocal.setSigningBureaucrat   ( & cadet_1    );
	// 	bocal.setExecutingBureaucrat ( & cadet_2    );
	// 	bocal.setIntern              ( & pisciner_1 );

	// 	bocal.doBureaucracy( "presidential pardon", "* some president *" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
	// std::cout << "TEST #3: LOW SIGING GRADE : ( sign = 72 ; exec = 45 )\n\n";

	// 	std::cout << "bocal.setSigningBureaucrat   ( & cadet_2    );\n";
	// 	std::cout << "bocal.setExecutingBureaucrat ( & cadet_1    );\n";

	// 	bocal.setSigningBureaucrat   ( & cadet_2    );
	// 	bocal.setExecutingBureaucrat ( & cadet_1    );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// 	bocal.doBureaucracy( "robotomy request", "bixby" );

	// std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	// }

	return (0);
}
