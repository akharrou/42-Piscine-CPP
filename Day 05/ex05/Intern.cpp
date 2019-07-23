/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:15:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:37:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "MutantPigTerminationForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

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

#define FORM_TYPES (4)
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
	},
	{
		"mutant pig termination",
		[]( std::string target ) {
			return ( (AForm *) new MutantPigTerminationForm( target ));
		}
	},
};

AForm	*Intern::makeForm( std::string formName,
	std::string formTarget ) const {

	AForm	*someForm;

	for ( int i = 0; i < FORM_TYPES; ++i ) {

		if ( formName == types[i].name ) {

			someForm = types[i].form( formTarget );
			std::cout << "Intern creates " << someForm->getName()
			          << " Form (s.grade " << someForm->getSignGradeReq()
					  << ", ex.grade " << someForm->getExeGradeReq() << ") "
					  << "targeted on " << formTarget
					  << " (" << ((someForm->getSigned()) ? "Signed" : "Unsigned") << ")"
					  << std::endl;
			return (someForm);
		}
	}
	throw OfficeBlock::FormUnknown();
}
