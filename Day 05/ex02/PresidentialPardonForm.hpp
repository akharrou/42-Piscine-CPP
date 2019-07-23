/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:40:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class PresidentialPardonForm : public AForm {

	protected:
		PresidentialPardonForm( void );

	public:
		PresidentialPardonForm( std::string name );
		PresidentialPardonForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		PresidentialPardonForm( const PresidentialPardonForm & src );
		~PresidentialPardonForm( void );

		PresidentialPardonForm &	operator = ( const PresidentialPardonForm & rhs );

		void	action( std::string target ) const;

};

#include "PresidentialPardonForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

PresidentialPardonForm::PresidentialPardonForm( std::string name ) :
	AForm (name, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm (name, signGradeReq, exeGradeReq) {
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

void	PresidentialPardonForm::action( std::string target ) const {

	/*  Tells us <target> has been pardoned by Zaphod
	Beeblebrox. */

	std::cout << target << " has been pardoned by Zaphod Beeblebrox"
	          << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* PRESIDENTIALPARDONFORM_HPP */
