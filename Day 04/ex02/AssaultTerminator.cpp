/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:49:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 19:10:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

AssaultTerminator::AssaultTerminator( void ) {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator( const AssaultTerminator & src ) {
	*this = src;
}

AssaultTerminator::~AssaultTerminator( void ) {
	std::cout << "I'll be back ..." << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

AssaultTerminator &	AssaultTerminator::operator = ( const AssaultTerminator & rhs ) {

	(void)rhs;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const AssaultTerminator & in ) {

	(void)in;
	out << "AssaultTerminator on GUARD !" << std::endl;
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

ISpaceMarine	*AssaultTerminator::clone() const {

	ISpaceMarine	*clone = new AssaultTerminator();

	*clone = *this;
	return (clone);
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void	AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

