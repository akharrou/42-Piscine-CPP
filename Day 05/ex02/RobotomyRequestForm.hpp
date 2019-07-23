/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:40:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RobotomyRequestForm : public AForm {

	protected:
		RobotomyRequestForm( void );

	public:
		RobotomyRequestForm( std::string name );
		RobotomyRequestForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		RobotomyRequestForm( const RobotomyRequestForm & src );
		~RobotomyRequestForm( void );

		RobotomyRequestForm &	operator = ( const RobotomyRequestForm & rhs );

		void	action( std::string target ) const;

};

#include "RobotomyRequestForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

RobotomyRequestForm::RobotomyRequestForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RobotomyRequestForm::RobotomyRequestForm( std::string name ) :
	AForm (name, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm (name, signGradeReq, exeGradeReq) {
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

void	RobotomyRequestForm::action( std::string target ) const {

	/*  Makes some drilling noises, and tells us that
	<target> has been robotomized successfully 50% of
	the time. the rest of times, tells us it’s a
	failure. */

	static unsigned times = 0;

	if (times++ % 2 == 0) {
		std::cout << "* drilling noises * "
		          << "<AForm> " << target
				  << " has been robotomized successfully"
				  << std::endl;
	} else {
		std::cout << "* drilling noises * "
		          << "<AForm> " << target
				  << " has been unsuccessfully robotomized"
				  << std::endl;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ROBOTOMYREQUESTFORM_HPP */
