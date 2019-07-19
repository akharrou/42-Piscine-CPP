/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:39:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:57:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

Character::Character(void) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

Character::Character( std::string const & name ) :
	_name(name),
	_weapon(NULL),
	_action_points(40),
	_max_action_points(40) {
}

Character::Character( const Character & src ) {
	*this = src;
}

Character::~Character( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Character &			Character::operator = ( const Character & rhs ) {

	if (this != &rhs) {
		_name = rhs._name;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Character & in ) {

	if (in.getWeapon()) {

		out << in.getName() << " has "
		    << in.getAP() << " AP and wields a "
			<< in.getWeapon()->getName()
			<< std::endl;

	} else {

		out << in.getName() << " has "
			<< in.getAP() << " AP and is unarmed"
			<< std::endl;

	}
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Character::getName() const {
	return (_name);
}

int				Character::getAP() const {
	return (_action_points);
}

AWeapon			*Character::getWeapon() const {
	return (_weapon);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void			Character::recoverAP( void ) {

	int repair_points = 10;

	if (_action_points != _max_action_points) {

		repair_points = (_action_points + repair_points > _max_action_points) ?
			 _max_action_points - _action_points : repair_points;
		_action_points += repair_points;
	}
}

void			Character::equip( AWeapon *weapon ) {
	_weapon = weapon;
}

void			Character::attack( Enemy *target ) {

	if (_weapon == NULL)
		return ;

	if (_action_points < _weapon->getAPCost())
		return ;

	std::cout << _name << " attacks " << target->getType()
	          << " with a " << _weapon->getName()
	          << std::endl;

	_weapon->attack();
	_action_points -= _weapon->getAPCost();
	target->takeDamage( _weapon->getDamage() );
}
