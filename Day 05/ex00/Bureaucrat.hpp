/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:40:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/22 14:15:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCREAT_HPP
# define BUREAUCREAT_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Bureaucrat {

	private:

		const std::string	_name;

		int	_grade;
		int	_highest_grade;
		int	_lowest_grade;

	protected:

		Bureaucrat( void );

	public:

		class GradeTooHighException	: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException	: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		Bureaucrat( std::string name, int grade );
		Bureaucrat( std::string name, int grade, int highest_grade, int lowest_grade );
		Bureaucrat( const Bureaucrat & src );
		~Bureaucrat( void );

		Bureaucrat &		operator = ( const Bureaucrat & rhs );

		const std::string	getName  () const;
		unsigned int		getGrade () const;

		void	incrementGrade ();
		void	decrementGrade ();

};

std::ostream & operator << ( std::ostream & out, const Bureaucrat & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* BUREAUCREAT_HPP */
