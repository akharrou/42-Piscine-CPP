/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:33:50 by akharrou         ###   ########.fr       */
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

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( std::string target,
			const int signGradeReq, const int exeGradeReq );
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &	operator = ( const ShrubberyCreationForm & rhs );

		void	action() const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SHRUBBERYCREATIONFORM_HPP */
