/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:19:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:22:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */

AForm::AForm( void ) :
	_name("n/a"), _signed(false),
	_sign_grade_required(1),
	_execute_grade_required(1),
	_highest_grade(HIGHEST_GRADE),
	_lowest_grade(LOWEST_GRADE) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AForm::AForm( std::string name, const int signGradeReq, const int exeGradeReq ) :
	_name(name), _signed(false),
	_sign_grade_required(signGradeReq),
	_execute_grade_required(exeGradeReq),
	_highest_grade(HIGHEST_GRADE),
	_lowest_grade(LOWEST_GRADE) {

	if ( _sign_grade_required < _highest_grade )
		throw GradeTooHighException();
	if ( _sign_grade_required > _lowest_grade )
		throw GradeTooLowException();

	if ( _execute_grade_required < _highest_grade )
		throw GradeTooHighException();
	if ( _execute_grade_required > _lowest_grade )
		throw GradeTooLowException();
}

AForm::AForm( const AForm & src ) :
	_name(src._name),
	_sign_grade_required(src._sign_grade_required),
	_execute_grade_required(src._execute_grade_required),
	_highest_grade(HIGHEST_GRADE),
	_lowest_grade(LOWEST_GRADE) {

	if ( _sign_grade_required < _highest_grade )
		throw GradeTooHighException();
	if ( _sign_grade_required > _lowest_grade )
		throw GradeTooLowException();

	if ( _execute_grade_required < _highest_grade )
		throw GradeTooHighException();
	if ( _execute_grade_required > _lowest_grade )
		throw GradeTooLowException();

	*this = src;
}

AForm::~AForm( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AForm &			AForm::operator = ( const AForm & rhs ) {

	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const AForm & in ) {

	out << "————————————————————————————————————————————————————————————\n"
		<< "<AForm> " << in.getName()                                  << "\n"
		<< "State : " << ((in.getSigned()) ? "Signed" : "not Signed") << "\n"
		<< "Signature Grade Req. : " << in.getSignGradeReq()          << "\n"
		<< "Execution Grade Req. : " << in.getExeGradeReq()           << "\n"
		<< "————————————————————————————————————————————————————————————\n";
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AForm::getName() const {
	return (_name);
}

bool			AForm::getSigned() const {
	return (_signed);
}

int				AForm::getSignGradeReq() const {
	return (_sign_grade_required);
}

int				AForm::getExeGradeReq() const {
	return (_execute_grade_required);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	AForm::beSigned( Bureaucrat const & bureaucrat ) {

	int bureaucratGrade = bureaucrat.getGrade();

	if ( bureaucratGrade < _highest_grade)
		throw GradeTooHighException();
	if ( bureaucratGrade > _lowest_grade )
		throw GradeTooLowException();

	if ( _signed ) {
		throw "form already signed";
	} else if ( bureaucratGrade > _sign_grade_required ) {
		throw "signature grade requirement not met";
	} else {
		_signed = true;
	}
}

void	AForm::execute  ( Bureaucrat const & bureaucrat ) const {

	int bureaucratGrade = bureaucrat.getGrade();

	if ( bureaucratGrade < _highest_grade)
		throw GradeTooHighException();
	if ( bureaucratGrade > _lowest_grade )
		throw GradeTooLowException();

	if ( bureaucratGrade < _execute_grade_required ) {

		if ( !_signed )
			throw "form is not signed";
		action ( _name );

	} else {
		throw "the execution grade requirement was not met";
	}
}
