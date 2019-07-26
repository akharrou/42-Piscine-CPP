/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:21:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 13:25:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instructions.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         ABSTRACT CLASS DEFINITION                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */

AInstruction::AInstruction( void ) {}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AInstruction::AInstruction( std::string type ) :
	_type(type) {
}

AInstruction::AInstruction( const AInstruction & src ) {
	*this = src;
}

AInstruction::~AInstruction( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AInstruction &	AInstruction::operator = ( const AInstruction & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const AInstruction & in ) {
	out << std::string("<AInstruction> ") << in.getType();
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AInstruction::getType() const {
	return (_type);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                        CONCRETE CLASS DEFINITIONS                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


void	IncrementPointer::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	DecrementPointer::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	IncrementByte::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	DecrementByte::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	PrintByte::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	GotoRightBracket::execute const {

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	GotoLeftBracket::execute const {

}
