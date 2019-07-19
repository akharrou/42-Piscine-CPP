/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:28:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 19:30:01 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class SuperTrap : public NinjaTrap, FragTrap {

	public:

		SuperTrap( void );
		SuperTrap( std::string name );
		SuperTrap( const SuperTrap & src );
		~SuperTrap( void );

		SuperTrap &		operator = ( const SuperTrap & rhs );

};

std::ostream & operator << ( std::ostream & out, const SuperTrap & in );


#include "SuperTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

SuperTrap::SuperTrap( void )
	: /* attribs. */ { }

SuperTrap::SuperTrap( /* regular */ )
	: /* attribs. */ { }

SuperTrap::SuperTrap( const SuperTrap & src ) {
	*this = src;
}

SuperTrap::~SuperTrap( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

SuperTrap &			SuperTrap::operator = ( const SuperTrap & rhs ) {

	if (this != &rhs) {
		/* IMPLEMENT */
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const SuperTrap & in ) {

	out << /* IMPLEMENT */;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */




/* PRIVATE MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — */




/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SUPERTRAP_HPP */
