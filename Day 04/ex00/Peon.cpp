/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:45:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 09:59:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — */

Peon::Peon( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — */

Peon::Peon( std::string name )
	: Victim(name) {

	std::cout << "Zog zog." << std::endl;
}

Peon::Peon( const Peon & src ) {
	*this = src;
}

Peon::~Peon( void ) {
	std::cout << "Bleuark..." << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Peon &			Peon::operator = ( const Peon & rhs ) {

	if (this != &rhs) {
		_name = rhs._name;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void	Peon::getPolymorphed() const {
	std::cout << _name << " has been turned into a pink pony !" << std::endl;
}
