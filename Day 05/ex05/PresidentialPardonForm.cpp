/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:33:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm ("Presidential Pardon", target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target,
	const int signGradeReq, const int exeGradeReq ) :
	AForm ("Presidential Pardon", target, signGradeReq, exeGradeReq) {
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

