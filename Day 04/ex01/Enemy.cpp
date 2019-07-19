/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:03:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 13:11:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — */

Enemy::Enemy( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

Enemy::Enemy( int hp, std::string const & type ) :
	_type(type),
	_hit_points(hp),
	_max_hit_points(hp) {
}

Enemy::Enemy( const Enemy & src ) {
	*this = src;
}

Enemy::~Enemy( void ) { }


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Enemy &			Enemy::operator = ( const Enemy & rhs ) {

	if (this != &rhs) {
        _type           = rhs._type;
        _hit_points     = rhs._hit_points;
        _max_hit_points = rhs._max_hit_points;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Enemy & in ) {

	out << "<" << in.getType()
	    << "> Enemy : " <<  in.getHP()
		<< "/" << in.getMaxHP();
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Enemy::getType() const {
	return (_type);
}

int				Enemy::getHP() const {
	return (_hit_points);
}

int				Enemy::getMaxHP() const {
	return (_max_hit_points);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Enemy::takeDamage( int amount ) {

	if (amount < 0)
		return ;

	std::cout << "<" << _type
	          << "> * takes damage for "<< amount
			  << " hit points *"
			  << std::endl;

	_hit_points = (_hit_points - amount > 0) ?
		(_hit_points - amount) : 0;
}
