/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:15:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 19:15:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

ShrubberyCreationForm::ShrubberyCreationForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

ShrubberyCreationForm::ShrubberyCreationForm( std::string name ) :
	AForm ("ShrubberyCreationForm", 145, 137), _target(name) {
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm (name, signGradeReq, exeGradeReq), _target(name) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

ShrubberyCreationForm &	ShrubberyCreationForm::operator = (
		const ShrubberyCreationForm & rhs ) {
	(void) rhs;
	return (*this);
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	ShrubberyCreationForm::action() const {

	/* Creates a file called <target>_shrubbery,
	and write ASCII trees inside it, in the
	current directory. */

	std::string tree =
		"          \\/ |    |/\n"
		"       \\/ / \\||/  /_/___/_\n"
		"        \\/   |/ \\/\n"
		"   _\\__\\_\\   |  /_____/_\n"
		"          \\  | /          /\n"
		" __ _-----`  |{,-----------~\n"
		"           \\ }{\n"
		"            }{{\n"
		"            }}{\n"
		"            {{}\n"
		"      , -=-~{ .-^- _\n"
		"             `}\n"
		"             {\n\n";

	std::ofstream	outfile( std::string(_target + std::string("_shrubbery")) );

	if (outfile.is_open()) {
		outfile << tree;
		outfile << tree;
		outfile << tree;
		outfile << tree;
		// ...
		outfile.close();
	}
}
