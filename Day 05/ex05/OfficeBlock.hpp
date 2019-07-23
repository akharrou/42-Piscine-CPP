/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:37:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 10:34:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Intern;
class Bureaucrat;
class OfficeBlock {

	private:

		Bureaucrat * _SigningBureaucrat;
		Bureaucrat * _ExecutingBureaucrat;
		Intern     * _Intern;

	protected:
		OfficeBlock( const OfficeBlock & src );
		OfficeBlock & operator = ( const OfficeBlock & rhs );

	public:

		class FormSigningGradeNotMet :
			public std::exception {
				public: virtual const char* what() const throw();
		};

		class FormExecutingGradeNotMet :
			public std::exception {
				public: virtual const char* what() const throw();
		};

		class FormNotSigned :
			public std::exception {
				public: virtual const char* what() const throw();
		};

		class FormAlreadySigned :
			public std::exception {
				public: virtual const char* what() const throw();
		};

		class FormUnknown :
			public std::exception {
				public: virtual const char* what() const throw();
		};

		OfficeBlock( void );
		OfficeBlock( Bureaucrat *, Bureaucrat *, Intern * );
		~OfficeBlock( void );

		void	setIntern              ( Intern     * );
		void	setSigningBureaucrat   ( Bureaucrat * );
		void	setExecutingBureaucrat ( Bureaucrat * );

		Intern		* getIntern              () const;
		Bureaucrat	* getSigningBureaucrat   () const;
		Bureaucrat	* getExecutingBureaucrat () const;

		bool	isActive () const;
		void	doBureaucracy( std::string formName, std::string target ) const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* OFFICEBLOCK_HPP */
