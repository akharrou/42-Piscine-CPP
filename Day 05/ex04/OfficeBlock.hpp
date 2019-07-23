/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:37:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 21:50:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class OfficeBlock {

	private:

		Bureaucrat * _SigningBureaucrat;
		Bureaucrat * _ExecutingBureaucrat;
		Intern     * _Intern;

	protected:
		OfficeBlock( const OfficeBlock & src );
		OfficeBlock & operator = ( const OfficeBlock & rhs );

	public:

		class FormSigningGradeTooHigh :
			public std::exception {
		};

		class FormExecutingGradeTooHigh :
			public std::exception {
		};

		class UnknownForm :
			public std::exception {
		};

		OfficeBlock( void );
		OfficeBlock( Bureaucrat *, Bureaucrat *, Intern * );
		~OfficeBlock( void );

		void	setIntern              ( Intern     * );
		void	setSigningBureaucrat   ( Bureaucrat * );
		void	setExecutingBureaucrat ( Bureaucrat * );

		void	doBureaucracy( std::string formName, std::string target ) const;

};

std::ostream & operator << ( std::ostream & out, const OfficeBlock & in );


#include "OfficeBlock.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

OfficeBlock::OfficeBlock( const OfficeBlock & src ) {
	*this = src;
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

OfficeBlock::OfficeBlock( void ) :
	_SigningBureaucrat(NULL),
	_ExecutingBureaucrat(NULL),
	_Intern(NULL) {
}

OfficeBlock::OfficeBlock( Bureaucrat *SigningBureaucrat,
	Bureaucrat *ExecutingBureaucrat, Intern *Intern ) :
	_SigningBureaucrat(SigningBureaucrat),
	_ExecutingBureaucrat(ExecutingBureaucrat),
	_Intern(Intern) {
}

OfficeBlock::~OfficeBlock( void ) { }


/* PRIVATE OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - */

OfficeBlock &			OfficeBlock::operator = ( const OfficeBlock & rhs ) {

	if (this != &rhs) {
        _SigningBureaucrat   = rhs._SigningBureaucrat;
        _ExecutingBureaucrat = rhs._ExecutingBureaucrat;
        _Intern              = rhs._Intern;
	}
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	OfficeBlock::setIntern( Intern *new_Intern ) {
	_Intern = new_Intern;
}

void	OfficeBlock::setSigningBureaucrat( Bureaucrat *new_SigningBureaucrat ) {
	_SigningBureaucrat = new_SigningBureaucrat;
}

void	OfficeBlock::setExecutingBureaucrat( Bureaucrat *new_ExecutingBureaucrat ) {
	_ExecutingBureaucrat = new_ExecutingBureaucrat;
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	OfficeBlock::doBureaucracy( std::string formName, std::string formTarget ) const {

	/* It attempts to, in order, make the intern create the
	requested form, have the second bureaucrat sign it, and have
	the second bureaucrat execute it */

	AForm	*someForm;

	try {

		_Intern->makeForm( formName, formTarget );

		try {

		} catch () {

		}

	} catch () {

	}

}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* OFFICEBLOCK_HPP */
