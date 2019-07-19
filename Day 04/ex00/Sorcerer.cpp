/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:33:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 10:03:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

Sorcerer::Sorcerer( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

Sorcerer::Sorcerer( std::string name, std::string title )
	: _name(name), _title(title) {

	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer( const Sorcerer & src ) {
	*this = src;
}

Sorcerer::~Sorcerer( void ) {

	std::cout << _name << ", " << _title
	          << ", is dead. Consequences will never be the same !"
	          << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Sorcerer &			Sorcerer::operator = ( const Sorcerer & rhs ) {

	if (this != &rhs) {
        _name  = rhs._name;
        _title = rhs._title;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Sorcerer & in ) {

	out << "I am " << in.getName() << ", " << in.getTitle()
	    << ", and I like ponies !" << std::endl;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Sorcerer::getName() const {
	return (_name);
}

std::string		Sorcerer::getTitle() const {
	return (_title);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void	Sorcerer::polymorph( const Victim & target ) const {
	target.getPolymorphed();
}
