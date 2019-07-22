/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 14:19:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "Bureaucrat.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nTEST #1:\n\n";

		try {

			Bureaucrat person_1( "Xavier", 1   );
			Bureaucrat person_2( "Kwame",  2   );
			Bureaucrat person_3( "Gaetan", 150 );

			std::cout << person_1 << "\n";
			std::cout << person_2 << "\n";
			std::cout << person_3 << "\n";

			try {

				person_3.decrementGrade();

			} catch ( std::exception & e ) {

				std::cout << "\n<Level 1.0> Standard Exception : " << e.what();

			}

			try {

				person_1.incrementGrade();

			} catch ( std::exception & e ) {

				std::cout << "\n<Level 1.1> Standard Exception : " << e.what() << std::endl;

			}

		} catch ( std::exception & e ) {

			std::cout << "<Level 0> Standard Exception : " << e.what() << std::endl;

		}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nTEST #2:\n\n";

		try {

			Bureaucrat person_4( "Emmanuel Macron", -1000 );
			std::cout << person_4 << "\n";

		} catch ( Bureaucrat::GradeTooHighException & e ) {

			std::cout << e.what() << std::endl;

		} catch ( Bureaucrat::GradeTooLowException & e ) {

			std::cout << e.what() << std::endl;
		}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nTEST #3:\n\n";

		try {

			Bureaucrat person_5( "Gaetan Again", 9001 );
			std::cout << person_5 << "\n";

		} catch ( Bureaucrat::GradeTooHighException & e ) {

			std::cout << e.what() << std::endl;

		} catch ( Bureaucrat::GradeTooLowException & e ) {

			std::cout << e.what() << std::endl;
		}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nTEST #3:\n\n";

		try {

			Bureaucrat person_6( "Gaetan 3rd time", 2147483647 );
			std::cout << person_6 << "\n";

		} catch ( std::exception & e ) {

			std::cout << "Standard Exception : " << e.what() << std::endl;

		} catch ( ... ) {

			std::cout << "* some other exception type *" << std::endl;
		}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	}

	return (0);
}
