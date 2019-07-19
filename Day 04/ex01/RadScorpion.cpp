/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:13:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:14:25 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

RadScorpion::RadScorpion( void )
	: Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion( const RadScorpion & src ) {
	*this = src;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "* SPROTCH *" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

RadScorpion &			RadScorpion::operator = ( const RadScorpion & rhs ) {

	if (this != &rhs) {
        _type           = rhs._type;
        _hit_points     = rhs._hit_points;
        _max_hit_points = rhs._max_hit_points;
	}
	return (*this);
}
