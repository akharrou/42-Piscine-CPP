/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:49:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:51:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

Character::Character( void ) {

	for (int i = 0; i < _max_inventory; ++i)
		inventory[i] = NULL;
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Character::Character( std::string name ) :
	_name(name) {

	for (int i = 0; i < _max_inventory; ++i)
		inventory[i] = NULL;
}

Character::Character( const Character & src ) {
	*this = src;
}

Character::~Character( void ) {

	for (int i = 0; i < _max_inventory; ++i)
		if (inventory[i]) {
			delete (inventory[i]);
			inventory[i] = NULL;
		}
}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Character &			Character::operator = ( const Character & rhs ) {

	if (this != &rhs) {

		_name = rhs._name;

		for (int i = 0; i < _max_inventory; ++i) {

			if (inventory[i])
				delete (inventory[i]);
			inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Character & in ) {

	out << "<Character> " << in.getName() << std::endl;
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const std::string &		Character::getName() const {
	return (_name);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Character::equip( AMateria *m ) {

	if (!m)
		return ;

	int i;

	for (i = 0; i < _max_inventory; ++i)
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break ;
		}
/*
	if (i == _max_inventory)
		std::cout << "* too many Materia's currently held *\n";
	else
		std::cout << "<" << m->getType() << "> Materia w/ "
				  << m->getXP() << " XP equipped."
				  << std::endl;
*/
}

void	Character::unequip( int idx ) {

	if (idx < 0 || idx > (_max_inventory - 1))
		return ;
	inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter & target ) {

	if (inventory[idx] != NULL)
		inventory[idx]->use( target );
}
