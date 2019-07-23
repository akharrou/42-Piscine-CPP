/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 11:27:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "CentralBureaucracy.hpp"

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

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		CentralBureaucracy	_42Paris;

		std::cout << "CentralBureaucracy	_42Paris;\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		Bureaucrat	person_1  ( "Person #1",  1 );
		Bureaucrat	person_2  ( "Person #2",  10 );
		Bureaucrat	person_3  ( "Person #3",  20 );
		Bureaucrat	person_4  ( "Person #4",  30 );
		Bureaucrat	person_5  ( "Person #5",  40 );
		Bureaucrat	person_6  ( "Person #6",  50 );
		Bureaucrat	person_7  ( "Person #7",  60 );
		Bureaucrat	person_8  ( "Person #8",  70 );
		Bureaucrat	person_9  ( "Person #9",  80 );
		Bureaucrat	person_10 ( "Person #10", 90 );
		Bureaucrat	person_11 ( "Person #11", 2  );
		Bureaucrat	person_12 ( "Person #12", 13 );
		Bureaucrat	person_13 ( "Person #13", 23 );
		Bureaucrat	person_14 ( "Person #14", 33 );
		Bureaucrat	person_15 ( "Person #15", 43 );
		Bureaucrat	person_16 ( "Person #16", 53 );
		Bureaucrat	person_17 ( "Person #17", 63 );
		Bureaucrat	person_18 ( "Person #18", 73 );
		Bureaucrat	person_19 ( "Person #19", 83 );
		Bureaucrat	person_20 ( "Person #20", 93 );

		Bureaucrat	person_1_1  ( "Person #1.1",  1 );
		Bureaucrat	person_2_1  ( "Person #2.1",  10 );
		Bureaucrat	person_3_1  ( "Person #3.1",  20 );
		Bureaucrat	person_4_1  ( "Person #4.1",  30 );
		Bureaucrat	person_5_1  ( "Person #5.1",  40 );
		Bureaucrat	person_6_1  ( "Person #6.1",  50 );
		Bureaucrat	person_7_1  ( "Person #7.1",  60 );
		Bureaucrat	person_8_1  ( "Person #8.1",  70 );
		Bureaucrat	person_9_1  ( "Person #9.1",  80 );
		Bureaucrat	person_10_1 ( "Person #10.1", 90 );
		Bureaucrat	person_11_1 ( "Person #11.1", 2  );
		Bureaucrat	person_12_1 ( "Person #12.1", 13 );
		Bureaucrat	person_13_1 ( "Person #13.1", 23 );
		Bureaucrat	person_14_1 ( "Person #14.1", 33 );
		Bureaucrat	person_15_1 ( "Person #15.1", 43 );
		Bureaucrat	person_16_1 ( "Person #16.1", 53 );
		Bureaucrat	person_17_1 ( "Person #17.1", 63 );
		Bureaucrat	person_18_1 ( "Person #18.1", 73 );
		Bureaucrat	person_19_1 ( "Person #19.1", 83 );
		Bureaucrat	person_20_1 ( "Person #20.1", 93 );

		Bureaucrat	person_1_2  ( "Person #1.2",  1 );
		Bureaucrat	person_2_2  ( "Person #2.2",  10 );
		Bureaucrat	person_3_2  ( "Person #3.2",  20 );
		Bureaucrat	person_4_2  ( "Person #4.2",  30 );
		Bureaucrat	person_5_2  ( "Person #5.2",  40 );
		Bureaucrat	person_6_2  ( "Person #6.2",  50 );
		Bureaucrat	person_7_2  ( "Person #7.2",  60 );
		Bureaucrat	person_8_2  ( "Person #8.2",  70 );
		Bureaucrat	person_9_2  ( "Person #9.2",  80 );
		Bureaucrat	person_10_2 ( "Person #10.2", 90 );
		Bureaucrat	person_11_2 ( "Person #11.2", 2  );
		Bureaucrat	person_12_2 ( "Person #12.2", 13 );
		Bureaucrat	person_13_2 ( "Person #13.2", 23 );
		Bureaucrat	person_14_2 ( "Person #14.2", 33 );
		Bureaucrat	person_15_2 ( "Person #15.2", 43 );
		Bureaucrat	person_16_2 ( "Person #16.2", 53 );
		Bureaucrat	person_17_2 ( "Person #17.2", 63 );
		Bureaucrat	person_18_2 ( "Person #18.2", 73 );
		Bureaucrat	person_19_2 ( "Person #19.2", 83 );
		Bureaucrat	person_20_2 ( "Person #20.2", 93 );

		std::cout << "Bureaucrat	person_1  ( \"Person #1\",  1 );\n"
					 "Bureaucrat	person_2  ( \"Person #2\",  10 );\n"
					 "Bureaucrat	person_3  ( \"Person #3\",  20 );\n"
					 "Bureaucrat	person_4  ( \"Person #4\",  30 );\n"
					 "Bureaucrat	person_5  ( \"Person #5\",  40 );\n"
					 "Bureaucrat	person_6  ( \"Person #6\",  50 );\n"
					 "Bureaucrat	person_7  ( \"Person #7\",  60 );\n"
					 "Bureaucrat	person_8  ( \"Person #8\",  70 );\n"
					 "Bureaucrat	person_9  ( \"Person #9\",  80 );\n"
					 "Bureaucrat	person_10 ( \"Person #10\", 90 );\n"
					 "Bureaucrat	person_11 ( \"Person #11\", 2  );\n"
					 "Bureaucrat	person_12 ( \"Person #12\", 13 );\n"
					 "Bureaucrat	person_13 ( \"Person #13\", 23 );\n"
					 "Bureaucrat	person_14 ( \"Person #14\", 33 );\n"
					 "Bureaucrat	person_15 ( \"Person #15\", 43 );\n"
					 "Bureaucrat	person_16 ( \"Person #16\", 53 );\n"
					 "Bureaucrat	person_17 ( \"Person #17\", 63 );\n"
					 "Bureaucrat	person_18 ( \"Person #18\", 73 );\n"
					 "Bureaucrat	person_19 ( \"Person #19\", 83 );\n"
					 "Bureaucrat	person_20 ( \"Person #20\", 93 );\n"
					 "\n"
					 "Bureaucrat	person_1_1  ( \"Person #1.1\",  1 );\n"
					 "Bureaucrat	person_2_1  ( \"Person #2.1\",  10 );\n"
					 "Bureaucrat	person_3_1  ( \"Person #3.1\",  20 );\n"
					 "Bureaucrat	person_4_1  ( \"Person #4.1\",  30 );\n"
					 "Bureaucrat	person_5_1  ( \"Person #5.1\",  40 );\n"
					 "Bureaucrat	person_6_1  ( \"Person #6.1\",  50 );\n"
					 "Bureaucrat	person_7_1  ( \"Person #7.1\",  60 );\n"
					 "Bureaucrat	person_8_1  ( \"Person #8.1\",  70 );\n"
					 "Bureaucrat	person_9_1  ( \"Person #9.1\",  80 );\n"
					 "Bureaucrat	person_10_1 ( \"Person #10.1\", 90 );\n"
					 "Bureaucrat	person_11_1 ( \"Person #11.1\", 2  );\n"
					 "Bureaucrat	person_12_1 ( \"Person #12.1\", 13 );\n"
					 "Bureaucrat	person_13_1 ( \"Person #13.1\", 23 );\n"
					 "Bureaucrat	person_14_1 ( \"Person #14.1\", 33 );\n"
					 "Bureaucrat	person_15_1 ( \"Person #15.1\", 43 );\n"
					 "Bureaucrat	person_16_1 ( \"Person #16.1\", 53 );\n"
					 "Bureaucrat	person_17_1 ( \"Person #17.1\", 63 );\n"
					 "Bureaucrat	person_18_1 ( \"Person #18.1\", 73 );\n"
					 "Bureaucrat	person_19_1 ( \"Person #19.1\", 83 );\n"
					 "Bureaucrat	person_20_1 ( \"Person #20.1\", 93 );\n"
					 "\n"
					 "Bureaucrat	person_1_2  ( \"Person #1.2\",  1 );\n"
					 "Bureaucrat	person_2_2  ( \"Person #2.2\",  10 );\n"
					 "Bureaucrat	person_3_2  ( \"Person #3.2\",  20 );\n"
					 "Bureaucrat	person_4_2  ( \"Person #4.2\",  30 );\n"
					 "Bureaucrat	person_5_2  ( \"Person #5.2\",  40 );\n"
					 "Bureaucrat	person_6_2  ( \"Person #6.2\",  50 );\n"
					 "Bureaucrat	person_7_2  ( \"Person #7.2\",  60 );\n"
					 "Bureaucrat	person_8_2  ( \"Person #8.2\",  70 );\n"
					 "Bureaucrat	person_9_2  ( \"Person #9.2\",  80 );\n"
					 "Bureaucrat	person_10_2 ( \"Person #10.2\", 90 );\n"
					 "Bureaucrat	person_11_2 ( \"Person #11.2\", 2  );\n"
					 "Bureaucrat	person_12_2 ( \"Person #12.2\", 13 );\n"
					 "Bureaucrat	person_13_2 ( \"Person #13.2\", 23 );\n"
					 "Bureaucrat	person_14_2 ( \"Person #14.2\", 33 );\n"
					 "Bureaucrat	person_15_2 ( \"Person #15.2\", 43 );\n"
					 "Bureaucrat	person_16_2 ( \"Person #16.2\", 53 );\n"
					 "Bureaucrat	person_17_2 ( \"Person #17.2\", 63 );\n"
					 "Bureaucrat	person_18_2 ( \"Person #18.2\", 73 );\n"
					 "Bureaucrat	person_19_2 ( \"Person #19.2\", 83 );\n"
					 "Bureaucrat	person_20_2 ( \"Person #20.2\", 93 );\n"
				  << std::endl;

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		_42Paris.recruitBureaucrat( & person_1  );
		_42Paris.recruitBureaucrat( & person_2  );
		_42Paris.recruitBureaucrat( & person_3  );
		_42Paris.recruitBureaucrat( & person_4  );
		_42Paris.recruitBureaucrat( & person_5  );
		_42Paris.recruitBureaucrat( & person_6  );
		_42Paris.recruitBureaucrat( & person_7  );
		_42Paris.recruitBureaucrat( & person_8  );
		_42Paris.recruitBureaucrat( & person_9  );
		_42Paris.recruitBureaucrat( & person_10 );
		_42Paris.recruitBureaucrat( & person_11 );
		_42Paris.recruitBureaucrat( & person_12 );
		_42Paris.recruitBureaucrat( & person_13 );
		_42Paris.recruitBureaucrat( & person_14 );
		_42Paris.recruitBureaucrat( & person_15 );
		_42Paris.recruitBureaucrat( & person_16 );
		_42Paris.recruitBureaucrat( & person_17 );
		_42Paris.recruitBureaucrat( & person_18 );
		_42Paris.recruitBureaucrat( & person_19 );
		_42Paris.recruitBureaucrat( & person_20 );

		std::cout << "_42Paris.recruitBureaucrat( & person_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_3  );\n"
					 "_42Paris.recruitBureaucrat( & person_4  );\n"
					 "_42Paris.recruitBureaucrat( & person_5  );\n"
					 "_42Paris.recruitBureaucrat( & person_6  );\n"
					 "_42Paris.recruitBureaucrat( & person_7  );\n"
					 "_42Paris.recruitBureaucrat( & person_8  );\n"
					 "_42Paris.recruitBureaucrat( & person_9  );\n"
					 "_42Paris.recruitBureaucrat( & person_10 );\n"
					 "_42Paris.recruitBureaucrat( & person_11 );\n"
					 "_42Paris.recruitBureaucrat( & person_12 );\n"
					 "_42Paris.recruitBureaucrat( & person_13 );\n"
					 "_42Paris.recruitBureaucrat( & person_14 );\n"
					 "_42Paris.recruitBureaucrat( & person_15 );\n"
					 "_42Paris.recruitBureaucrat( & person_16 );\n"
					 "_42Paris.recruitBureaucrat( & person_17 );\n"
					 "_42Paris.recruitBureaucrat( & person_18 );\n"
					 "_42Paris.recruitBureaucrat( & person_19 );\n"
					 "_42Paris.recruitBureaucrat( & person_20 );\n"
				  << std::endl;

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		_42Paris.recruitBureaucrat( & person_1_1  );
		_42Paris.recruitBureaucrat( & person_2_1  );
		_42Paris.recruitBureaucrat( & person_3_1  );
		_42Paris.recruitBureaucrat( & person_4_1  );
		_42Paris.recruitBureaucrat( & person_5_1  );
		_42Paris.recruitBureaucrat( & person_6_1  );
		_42Paris.recruitBureaucrat( & person_7_1  );
		_42Paris.recruitBureaucrat( & person_8_1  );
		_42Paris.recruitBureaucrat( & person_9_1  );
		_42Paris.recruitBureaucrat( & person_10_1 );
		_42Paris.recruitBureaucrat( & person_11_1 );
		_42Paris.recruitBureaucrat( & person_12_1 );
		_42Paris.recruitBureaucrat( & person_13_1 );
		_42Paris.recruitBureaucrat( & person_14_1 );
		_42Paris.recruitBureaucrat( & person_15_1 );
		_42Paris.recruitBureaucrat( & person_16_1 );
		_42Paris.recruitBureaucrat( & person_17_1 );
		_42Paris.recruitBureaucrat( & person_18_1 );
		_42Paris.recruitBureaucrat( & person_19_1 );
		_42Paris.recruitBureaucrat( & person_20_1 );

		std::cout << "_42Paris.recruitBureaucrat( & person_1_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_2_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_3_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_4_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_5_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_6_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_7_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_8_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_9_1  );\n"
					 "_42Paris.recruitBureaucrat( & person_10_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_11_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_12_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_13_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_14_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_15_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_16_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_17_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_18_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_19_1 );\n"
					 "_42Paris.recruitBureaucrat( & person_20_1 );\n"
				  << std::endl;

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		_42Paris.recruitBureaucrat( & person_1_2  );
		_42Paris.recruitBureaucrat( & person_2_2  );
		_42Paris.recruitBureaucrat( & person_3_2  );
		_42Paris.recruitBureaucrat( & person_4_2  );
		_42Paris.recruitBureaucrat( & person_5_2  );
		_42Paris.recruitBureaucrat( & person_6_2  );
		_42Paris.recruitBureaucrat( & person_7_2  );
		_42Paris.recruitBureaucrat( & person_8_2  );
		_42Paris.recruitBureaucrat( & person_9_2  );
		_42Paris.recruitBureaucrat( & person_10_2 );
		_42Paris.recruitBureaucrat( & person_11_2 );
		_42Paris.recruitBureaucrat( & person_12_2 );
		_42Paris.recruitBureaucrat( & person_13_2 );
		_42Paris.recruitBureaucrat( & person_14_2 );
		_42Paris.recruitBureaucrat( & person_15_2 );
		_42Paris.recruitBureaucrat( & person_16_2 );
		_42Paris.recruitBureaucrat( & person_17_2 );
		_42Paris.recruitBureaucrat( & person_18_2 );
		_42Paris.recruitBureaucrat( & person_19_2 );
		_42Paris.recruitBureaucrat( & person_20_2 );

		std::cout << "_42Paris.recruitBureaucrat( & person_1_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_2_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_3_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_4_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_5_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_6_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_7_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_8_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_9_2  );\n"
					 "_42Paris.recruitBureaucrat( & person_10_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_11_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_12_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_13_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_14_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_15_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_16_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_17_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_18_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_19_2 );\n"
					 "_42Paris.recruitBureaucrat( & person_20_2 );\n"
				  << std::endl;

		std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		_42Paris.queueUp( "shrubbery creation", "home #4" );
		_42Paris.queueUp( "robotomy request", "bixby #3" );
		_42Paris.queueUp( "shrubbery creation", "home #2" );
		_42Paris.queueUp( "mutant pig termination", "pig #4" );
		_42Paris.queueUp( "presidential pardon", "* some president #3 *" );
		_42Paris.queueUp( "mutant pig termination", "pig #5" );
		_42Paris.queueUp( "robotomy request", "bixby #4" );
		_42Paris.queueUp( "presidential pardon", "* some president #1 *" );
		_42Paris.queueUp( "shrubbery creation", "home #5" );
		_42Paris.queueUp( "robotomy request", "bixby #5" );
		_42Paris.queueUp( "presidential pardon", "* some president #2 *" );
		_42Paris.queueUp( "mutant pig termination", "pig #2" );
		_42Paris.queueUp( "presidential pardon", "* some president #4 *" );
		_42Paris.queueUp( "mutant pig termination", "pig #3" );
		_42Paris.queueUp( "robotomy request", "bixby #2" );
		_42Paris.queueUp( "shrubbery creation", "home #3" );
		_42Paris.queueUp( "mutant pig termination", "pig #1" );
		_42Paris.queueUp( "shrubbery creation", "home #1" );
		_42Paris.queueUp( "presidential pardon", "* some president #5 *" );
		_42Paris.queueUp( "robotomy request", "bixby #1" );

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		_42Paris.doBureaucracy();

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";
	}

	return (0);
}


/* BUREAUCRACY OUTPUT:

Intern creates Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #4 (Unsigned)
<Bureaucrat> Person #1 signs <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #4 (Unsigned)
<Bureaucrat> Person #2 executes <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #4 (Signed)

Intern creates Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #3 (Unsigned)
<Bureaucrat> Person #3 signs <Form> Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #3 (Unsigned)
<Bureaucrat> Person #4 executes <Form> Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #3 (Signed)
* drilling noises * bixby #3 has been robotomized successfully

Intern creates Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #2 (Unsigned)
<Bureaucrat> Person #5 signs <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #2 (Unsigned)
<Bureaucrat> Person #6 executes <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #2 (Signed)

Intern creates Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #4 (Unsigned)
<Bureaucrat> Person #7 signs <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #4 (Unsigned)
~ Executing Form Failed : executing grade requirement not met ~

Intern creates Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #3 * (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #5 (Unsigned)
<Bureaucrat> Person #11 signs <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #5 (Unsigned)
<Bureaucrat> Person #12 executes <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #5 (Signed)
 That'll do, pig #5. That'll do ...

Intern creates Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #4 (Unsigned)
<Bureaucrat> Person #13 signs <Form> Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #4 (Unsigned)
<Bureaucrat> Person #14 executes <Form> Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #4 (Signed)
* drilling noises * bixby #4 has been unsuccessfully robotomized

Intern creates Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #1 * (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #5 (Unsigned)
<Bureaucrat> Person #17 signs <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #5 (Unsigned)
<Bureaucrat> Person #18 executes <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #5 (Signed)

Intern creates Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #5 (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #2 * (Unsigned)
<Bureaucrat> Person #1.1 signs <Form> Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #2 * (Unsigned)
~ Executing Form Failed : executing grade requirement not met ~

Intern creates Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #2 (Unsigned)
<Bureaucrat> Person #3.1 signs <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #2 (Unsigned)
<Bureaucrat> Person #4.1 executes <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #2 (Signed)
 That'll do, pig #2. That'll do ...

Intern creates Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #4 * (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #3 (Unsigned)
<Bureaucrat> Person #7.1 signs <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #3 (Unsigned)
~ Executing Form Failed : executing grade requirement not met ~

Intern creates Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #2 (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #3 (Unsigned)
<Bureaucrat> Person #11.1 signs <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #3 (Unsigned)
<Bureaucrat> Person #12.1 executes <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #3 (Signed)

Intern creates Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #1 (Unsigned)
<Bureaucrat> Person #13.1 signs <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #1 (Unsigned)
<Bureaucrat> Person #14.1 executes <Form> Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on pig #1 (Signed)
 That'll do, pig #1. That'll do ...

Intern creates Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #1 (Unsigned)
<Bureaucrat> Person #15.1 signs <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #1 (Unsigned)
<Bureaucrat> Person #16.1 executes <Form> Shrubbery Creation Form (s.grade 145, ex.grade 137) targeted on home #1 (Signed)

Intern creates Presidential Pardon Form (s.grade 25, ex.grade 5) targeted on * some president #5 * (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

Intern creates Robotomy Request Form (s.grade 72, ex.grade 45) targeted on bixby #1 (Unsigned)
~ Signing Form Failed : signing grade requirement not met ~

*/
