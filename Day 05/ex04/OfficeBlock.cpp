/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:57:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 00:19:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

OfficeBlock &		OfficeBlock::operator = ( const OfficeBlock & rhs ) {

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

	/* It attempts to, make the intern create the requested form,
	have the first bureaucrat sign it and finally have the second
	bureaucrat execute it, respectively. */

	AForm	*someForm;

	try {

		someForm = _Intern    -> makeForm     ( formName, formTarget );
		_SigningBureaucrat    -> signForm     ( *someForm );
		_ExecutingBureaucrat  -> executeForm  ( *someForm );

	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char	*OfficeBlock::FormUnknown::what() const throw() {
	return ("~ Creation of form failed : unknown form type ~");
}

const char	*OfficeBlock::FormSigningGradeNotMet::what() const throw() {
	return ("~ Signing Form Failed : signing grade requirement not met ~");
}

const char	*OfficeBlock::FormAlreadySigned::what() const throw() {
	return ("~ Signing Form Failed : already signed ~");
}

const char	*OfficeBlock::FormExecutingGradeNotMet::what() const throw() {
	return ("~ Executing Form Failed : executing grade requirement not met ~");
}

const char	*OfficeBlock::FormNotSigned::what() const throw() {
	return ("~ Executing Form Failed : form not signed ~");
}
