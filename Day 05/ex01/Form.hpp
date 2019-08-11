/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:20:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/11 12:24:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Bureaucrat.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Form {

	private:
		const std::string	_name;

		bool		_signed;

		const int	_sign_grade_required;
		const int	_execute_grade_required;

		const int	_highest_grade;
		const int	_lowest_grade;

	protected:
		Form( void );

	public:

		class GradeTooHighException	:
			public Bureaucrat::GradeTooHighException { };

		class GradeTooLowException	:
			public Bureaucrat::GradeTooLowException { };

		Form( std::string name, const int signGradeReq, const int exeGradeReq );
		Form( const Form & src );
		~Form( void );

		Form &		operator = ( const Form & rhs );

		std::string		getName          () const;
		bool			getSigned        () const;
		int				getSignGradeReq  () const;
		int				getExeGradeReq   () const;

		bool	beSigned( Bureaucrat & );

};

std::ostream & operator << ( std::ostream & out, const Form & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* FORM_HPP */
