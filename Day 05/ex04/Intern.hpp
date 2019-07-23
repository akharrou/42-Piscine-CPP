/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:04:05 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 09:37:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AForm.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AForm;
class Intern {

	public:

		Intern( void );
		Intern( const Intern & src );
		~Intern( void );

		Intern & operator = ( const Intern & rhs );

		AForm	*makeForm( std::string formName , std::string formTarget ) const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* INTERN_HPP */
