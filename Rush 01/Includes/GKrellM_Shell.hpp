/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:41:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 13:45:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_SHELL_HPP
# define GKRELLM_SHELL_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define TOTAL_MODULES (4)

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class GKrellM_Shell :
	public IMonitorDisplay {

	private:

		IMonitorModule *_modules[TOTAL_MODULES];

	public:

		GKrellM_Shell( void );
		GKrellM_Shell( const GKrellM_Shell & src );
		~GKrellM_Shell( void );

		GKrellM_Shell &  operator = ( const GKrellM_Shell & rhs );


};

std::ostream & operator << ( std::ostream & out, const GKrellM_Shell & in );


#include "GKrellM_Shell.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */



/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */



/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell::GKrellM_Shell( void ) :
	/* attribs. */ {
}

GKrellM_Shell::GKrellM_Shell( const GKrellM_Shell & src ) {
	*this = src;
}

GKrellM_Shell::~GKrellM_Shell( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell &			GKrellM_Shell::operator = ( const GKrellM_Shell & rhs ) {

	if (this != &rhs) {
		/* IMPLEMENT */
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const GKrellM_Shell & in ) {

	out << /* IMPLEMENT */;
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




/* PRIVATE MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - */




/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */



/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_SHELL_HPP */
