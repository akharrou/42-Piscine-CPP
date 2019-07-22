/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:19:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 15:58:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */

Form::Form( void ) :
	_name("n/a"), _signed(false),
	_sign_grade_required(1),
	_execute_grade_required(1),
	_highest_grade(HIGHEST_GRADE),
	_lowest_grade(LOWEST_GRADE) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Form::Form( std::string name, const int signGradeReq, const int exeGradeReq ) :
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

Form::Form( const Form & src ) :
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

Form::~Form( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Form &			Form::operator = ( const Form & rhs ) {

	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Form & in ) {

	out << "————————————————————————————————————————————————————————————\n"
		<< "<Form> " << in.getName()                                  << "\n"
		<< "State : " << ((in.getSigned()) ? "Signed" : "not Signed") << "\n"
		<< "Signature Grade Req. : " << in.getSignGradeReq()          << "\n"
		<< "Execution Grade Req. : " << in.getExeGradeReq()           << "\n"
		<< "————————————————————————————————————————————————————————————\n";
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		Form::getName() const {
	return (_name);
}

bool			Form::getSigned() const {
	return (_signed);
}

int				Form::getSignGradeReq() const {
	return (_sign_grade_required);
}

int				Form::getExeGradeReq() const {
	return (_execute_grade_required);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

bool	Form::beSigned( Bureaucrat &bureaucrat ) {

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
		return ((_signed = true));
	}
}
