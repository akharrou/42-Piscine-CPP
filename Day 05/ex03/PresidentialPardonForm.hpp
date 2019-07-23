/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:32:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 19:15:26 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class PresidentialPardonForm : public AForm {

	protected:
		PresidentialPardonForm( void );
		std::string	_target;

	public:
		PresidentialPardonForm( std::string name );
		PresidentialPardonForm( std::string name,
			const int signGradeReq, const int exeGradeReq );
		PresidentialPardonForm( const PresidentialPardonForm & src );
		~PresidentialPardonForm( void );

		PresidentialPardonForm &	operator = ( const PresidentialPardonForm & rhs );

		void	action() const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* PRESIDENTIALPARDONFORM_HPP */
