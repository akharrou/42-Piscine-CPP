/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:20:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 18:23:27 by akharrou         ###   ########.fr       */
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

class AForm {

	private:
		const std::string	_name;

		bool		_signed;

		const int	_sign_grade_required;
		const int	_execute_grade_required;

		const int	_highest_grade;
		const int	_lowest_grade;

	protected:
		AForm( void );

	public:

		class GradeTooHighException	:
			public Bureaucrat::GradeTooHighException { };

		class GradeTooLowException	:
			public Bureaucrat::GradeTooLowException { };

		AForm( std::string name, const int signGradeReq, const int exeGradeReq );
		AForm( const AForm & src );
		virtual ~AForm( void );

		AForm &		operator = ( const AForm & rhs );

		std::string		getName          () const;
		bool			getSigned        () const;
		int				getSignGradeReq  () const;
		int				getExeGradeReq   () const;

		void	beSigned ( Bureaucrat const & );
		void	execute  ( Bureaucrat const & ) const;

		virtual void	action () const = 0;
};

std::ostream & operator << ( std::ostream & out, const AForm & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* FORM_HPP */
