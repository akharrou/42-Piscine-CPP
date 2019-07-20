/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:56:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 17:01:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>
#include "ISquad.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class Squad
	: public ISquad {

	private:

		int		_squad_count;

	public:

		Squad( void );
		Squad( const Squad & src );
		~Squad( void );

		Squad &		operator = ( const Squad & rhs );

		int		push( ISpaceMarine *obj );

};

std::ostream & operator << ( std::ostream & out, const Squad & in );


#include "Squad.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

Squad::Squad( void ) :
	_squad_count(0) {
}

Squad::Squad( const Squad & src ) {
	*this = src;
}

Squad::~Squad( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Squad &			Squad::operator = ( const Squad & rhs ) {

	if (this != &rhs) {
		/* IMPLEMENT */
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Squad & in ) {

	out << /* IMPLEMENT */;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				Squad::getCount ()      const {
	return (_squad_count);
}

ISpaceMarine	*Squad::getUnit ( int ) const {
	return (/* pointer to the Nth unit, starting at 0, NULL if empty */);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SQUAD_HPP */
