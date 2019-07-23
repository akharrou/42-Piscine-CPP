/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:31:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

		AForm		form_1( "Dorm Reservation" , 2, 1 );

		std::cout << form_1 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		person_3.signForm(form_1);
		person_2.signForm(form_1);
		person_1.signForm(form_1);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << form_1 << "\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	}

	return (0);
}
