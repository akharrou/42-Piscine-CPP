/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:45:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 10:02:41 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — */

Victim::Victim( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — */

Victim::Victim( std::string name )
	: _name(name) {

	std::cout << "Some random victim called " << _name << " just popped !"
	          << std::endl;
}

Victim::Victim( const Victim & src ) {
	*this = src;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << _name << " just died for no apparent reason !"
			  << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Victim &			Victim::operator = ( const Victim & rhs ) {

	if (this != &rhs) {
		_name = rhs._name;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Victim & in ) {

	out << "I'm " << in.getName() << " and I like otters !" << std::endl;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Victim::getName() const {
	return (_name);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void			Victim::getPolymorphed() const {
	std::cout << _name << " has been turned into a cute little sheep !"
	          << std::endl;
}
