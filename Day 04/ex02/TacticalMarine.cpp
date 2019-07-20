/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:47:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 20:48:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

TacticalMarine::TacticalMarine( void ) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine( const TacticalMarine & src ) {
	*this = src;
}

TacticalMarine::~TacticalMarine( void ) {
	std::cout << "Aaargh ..." << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

TacticalMarine &	TacticalMarine::operator = ( const TacticalMarine & rhs ) {

	(void)rhs;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const TacticalMarine & in ) {

	(void)in;
	out << "TacticalMarine at your service !" << std::endl;
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

ISpaceMarine	*TacticalMarine::clone() const {
	return ((ISpaceMarine*)new TacticalMarine());
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}
