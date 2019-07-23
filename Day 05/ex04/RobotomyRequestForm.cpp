/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:39 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 19:15:39 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

RobotomyRequestForm::RobotomyRequestForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RobotomyRequestForm::RobotomyRequestForm( std::string name ) :
	AForm ("RobotomyRequestForm", 72, 45), _target(name) {
}

RobotomyRequestForm::RobotomyRequestForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm ("RobotomyRequestForm", signGradeReq, exeGradeReq),
	_target(name) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RobotomyRequestForm &	RobotomyRequestForm::operator = (
		const RobotomyRequestForm & rhs ) {
	(void) rhs;
	return (*this);
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	RobotomyRequestForm::action() const {

	/*  Makes some drilling noises, and tells us that
	<target> has been robotomized successfully 50% of
	the time. the rest of times, tells us it’s a
	failure. */

	static unsigned times = 0;

	if (times++ % 2 == 0) {
		std::cout << "* drilling noises * "
		          << _target << " has been robotomized successfully"
				  << std::endl;
	} else {
		std::cout << "* drilling noises * "
		          << _target << " has been unsuccessfully robotomized"
				  << std::endl;
	}
}
