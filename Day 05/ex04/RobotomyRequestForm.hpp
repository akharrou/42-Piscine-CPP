/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 00:15:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AForm;
class RobotomyRequestForm :
	public AForm {

	protected:
		RobotomyRequestForm( void );
		std::string	_target;

	public:
		RobotomyRequestForm( std::string name );
		RobotomyRequestForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		RobotomyRequestForm( const RobotomyRequestForm & src );
		~RobotomyRequestForm( void );

		RobotomyRequestForm &	operator = ( const RobotomyRequestForm & rhs );

		void	action() const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ROBOTOMYREQUESTFORM_HPP */
