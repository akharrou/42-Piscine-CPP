/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:40:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <fstream>
# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class ShrubberyCreationForm : public AForm {

	protected:
		ShrubberyCreationForm( void );

	public:
		ShrubberyCreationForm( std::string name );
		ShrubberyCreationForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &		operator = ( const ShrubberyCreationForm & rhs );

		void	action( std::string target ) const;

};

#include "ShrubberyCreationForm.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

ShrubberyCreationForm::ShrubberyCreationForm( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

ShrubberyCreationForm::ShrubberyCreationForm( std::string name ) :
	AForm (name, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string name,
	const int signGradeReq, const int exeGradeReq ) :
	AForm (name, signGradeReq, exeGradeReq) {
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

void	ShrubberyCreationForm::action( std::string target ) const {

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

	std::ofstream	outfile( std::string(target + std::string("_shrubbery")) );

	if (outfile.is_open()) {
		outfile << tree;
		outfile << tree;
		outfile << tree;
		outfile << tree;
		// ...
		outfile.close();
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SHRUBBERYCREATIONFORM_HPP */
