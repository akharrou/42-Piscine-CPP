/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantPigTerminationForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:33:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantPigTerminationForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

MutantPigTerminationForm::MutantPigTerminationForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MutantPigTerminationForm::MutantPigTerminationForm( std::string target ) :
	AForm ("Mutant Pig Termination", target, 130, 50) {
}

MutantPigTerminationForm::MutantPigTerminationForm( std::string target,
	const int signGradeReq, const int exeGradeReq ) :
	AForm ("Mutant Pig Termination", target, signGradeReq, exeGradeReq) {
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

