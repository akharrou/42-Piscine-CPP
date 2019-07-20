/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:27:25 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 15:32:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MiningBarge::MiningBarge( void ) {

	for (int i = 0; i < _max_lasers; ++i)
		_lasers[i] = NULL;
}

MiningBarge::MiningBarge( const MiningBarge & src ) {
	*this = src;
}

MiningBarge::~MiningBarge( void ) {

}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

MiningBarge &			MiningBarge::operator = ( const MiningBarge & rhs ) {

	if (this != &rhs) {

		for (int i = 0; i < _max_lasers; ++i)
			_lasers[i] = rhs._lasers[i];
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const MiningBarge & in ) {
	(void)in;
	out << "<MiningBarge>";
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	MiningBarge::equip ( IMiningLaser *laser ) {

	if (!laser)
		return ;

	for ( int i = 0; i < _max_lasers; ++i )
		if (_lasers[i] == NULL)
			_lasers[i] = laser;
}

void	MiningBarge::mine  ( IAsteroid *asteroid ) const {

	if (!asteroid)
		return ;

	for ( int i = 0; i < _max_lasers; ++i ) {

		if (_lasers[i])
			_lasers[i]->mine( asteroid );
	}
}
