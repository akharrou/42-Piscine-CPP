/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:15:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 20:33:16 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Intern::Intern( void ) { }

Intern::Intern( const Intern & src ) {
	*this = src;
}

Intern::~Intern( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Intern &			Intern::operator = ( const Intern & rhs ) {
	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct {
	std::string name;
	AForm *(*form)( std::string target );
} form_t;

#define FORM_TYPES (3)
form_t	types[FORM_TYPES] = {

	{
		"shrubbery creation",
		[]( std::string target ) {
			return ( (AForm *) new ShrubberyCreationForm( target ));
		}
	},
	{
		"robotomy request",
		[]( std::string target ) {
			return ( (AForm *) new RobotomyRequestForm( target ));
		}
	},
	{
		"presidential pardon",
		[]( std::string target ) {
			return ( (AForm *) new PresidentialPardonForm( target ));
		}
	}
};

AForm	*Intern::makeForm( std::string formName,
	std::string formTarget ) const {

	AForm	*someForm;

	for ( int i = 0; i < FORM_TYPES; ++i ) {

		if ( formName == types[i].name ) {

			try {

				someForm = types[i].form( formTarget );
				std::cout << "Intern creates <Form> " << someForm->getName()
						<< std::endl;

			} catch ( std::bad_alloc ) {

				std::cout << "~ Creation of \'" << formName << "\' Form Failed ~" << std::endl;
				someForm = NULL;
			}

			return (someForm);
		}
	}

	std::cout << "~ Unknown Form Type ~" << std::endl;
	return (NULL);
}
