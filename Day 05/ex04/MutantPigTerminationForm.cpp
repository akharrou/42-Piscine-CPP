/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantPigTerminationForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 00:43:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantPigTerminationForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

MutantPigTerminationForm::MutantPigTerminationForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MutantPigTerminationForm::MutantPigTerminationForm( std::string name ) :
	AForm ("MutantPigTerminationForm", 130, 50), _target(name) {
}

MutantPigTerminationForm::MutantPigTerminationForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm ("MutantPigTerminationForm", signGradeReq, exeGradeReq),
	_target(name) {
}

MutantPigTerminationForm::MutantPigTerminationForm( const MutantPigTerminationForm & src ) {
	*this = src;
}

MutantPigTerminationForm::~MutantPigTerminationForm( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

MutantPigTerminationForm &	MutantPigTerminationForm::operator = (
		const MutantPigTerminationForm & rhs ) {
	(void) rhs;
	return (*this);
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	MutantPigTerminationForm::action() const {

	std::cout << " That'll do, " << _target << ". That'll do ..."
	          << std::endl;
}

