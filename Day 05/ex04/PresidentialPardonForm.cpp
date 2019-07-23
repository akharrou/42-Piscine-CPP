/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 19:15:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( std::string name ) :
	AForm ("PresidentialPardonForm", 25, 5), _target(name) {
}

PresidentialPardonForm::PresidentialPardonForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm ("PresidentialPardonForm", signGradeReq, exeGradeReq),
	_target(name) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm &	PresidentialPardonForm::operator = (
		const PresidentialPardonForm & rhs ) {
	(void) rhs;
	return (*this);
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	PresidentialPardonForm::action() const {

	/*  Tells us <target> has been pardoned by Zaphod
	Beeblebrox. */

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
	          << std::endl;
}

