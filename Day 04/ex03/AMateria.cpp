/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:26:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:45:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

AMateria::AMateria( void ) :
	xp_(0) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AMateria::AMateria( const std::string & type ) :
	xp_(0), type_(type) {
}

AMateria::AMateria( const AMateria & src ) {
	*this = src;
}

AMateria::~AMateria( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AMateria &			AMateria::operator = ( const AMateria & rhs ) {

	if (this != &rhs) {
		xp_ = rhs.xp_;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const AMateria & in ) {

	out << "Materia of type " << in.getType()
		<< "; currently at " << in.getXP()
		<< " xp" << std::endl;
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	AMateria::setXP( unsigned int xp ) {
	xp_ = xp;
}

const std::string &		AMateria::getType() const {
	return (type_);
}
unsigned int			AMateria::getXP() const {
	return (xp_);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	AMateria::use( ICharacter & target ) {

	(void)target;
	xp_ += 10;
}
