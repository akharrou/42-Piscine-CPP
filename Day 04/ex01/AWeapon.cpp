/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:17:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:21:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — */

AWeapon::AWeapon( void ) { }


/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — */

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) :
	_name(name),
	_damage_points(damage),
	_action_points(apcost) {
}

AWeapon::AWeapon( const AWeapon & src ) {
	*this = src;
}

AWeapon::~AWeapon( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

AWeapon &			AWeapon::operator = ( const AWeapon & rhs ) {

	if (this != &rhs) {
		_name = rhs._name;
		_damage_points = rhs._damage_points;
		_action_points = rhs._action_points;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const AWeapon & in ) {

	out << "<" << in.getName() << ">"
	    << " deals " << in.getDamage()
		<< " damage points and costs " << in.getAPCost()
		<< " action points";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		AWeapon::getName() const {
	return (_name);
}

int				AWeapon::getAPCost() const {
	return (_action_points);
}

int				AWeapon::getDamage() const {
	return (_damage_points);
}
