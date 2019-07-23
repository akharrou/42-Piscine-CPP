/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 00:15:05 by akharrou         ###   ########.fr       */
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

class AForm;
class ShrubberyCreationForm :
	public AForm {

	protected:
		ShrubberyCreationForm( void );
		std::string	_target;

	public:
		ShrubberyCreationForm( std::string name );
		ShrubberyCreationForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &	operator = ( const ShrubberyCreationForm & rhs );

		void	action() const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SHRUBBERYCREATIONFORM_HPP */
