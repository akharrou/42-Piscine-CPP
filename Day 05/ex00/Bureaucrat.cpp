/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 14:19:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

Bureaucrat::Bureaucrat( void )  :
	_name("n/a"),
	_highest_grade(0),
	_lowest_grade(0) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Bureaucrat::Bureaucrat( std::string name, int grade ) :
	_name(name),
	_highest_grade(1),
	_lowest_grade(150) {

	if ( grade < _highest_grade ) {
		throw GradeTooHighException();
	} if ( grade > _lowest_grade ) {
		throw GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat( std::string name, int grade,
	int highest_grade, int lowest_grade ) :
	_name(name),
	_highest_grade(highest_grade),
	_lowest_grade(lowest_grade) {

	if ( grade < _highest_grade ) {
		throw GradeTooHighException();
	} if ( grade > _lowest_grade ) {
		throw GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) :
	_name(src._name),
	_highest_grade(src._highest_grade),
	_lowest_grade(src._lowest_grade) {
	*this = src;
}

Bureaucrat::~Bureaucrat( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Bureaucrat &		Bureaucrat::operator = ( const Bureaucrat & rhs ) {

	if (this != &rhs)
        _grade = rhs._grade;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Bureaucrat & in ) {
	out << "<Bureaucrat> " << in.getName() << " ; Grade : " << in.getGrade();
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const std::string	Bureaucrat::getName  () const {
	return (_name);
}

unsigned int		Bureaucrat::getGrade () const {
	return (_grade);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Bureaucrat::incrementGrade() {

	if ( _grade - 1 < _highest_grade )
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade() {

	if ( _grade + 1 > _lowest_grade )
		throw GradeTooLowException();
	++_grade;
}


/* EXCEPTION HANDLER(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("GradeTooLowException");
}
