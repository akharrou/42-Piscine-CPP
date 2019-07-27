/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:21:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 18:12:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         ABSTRACT CLASS DEFINITION                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */

MindOpen::AInstruction::AInstruction( void ) {}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MindOpen::AInstruction::AInstruction( std::string type ) :
	_type(type) {
}

MindOpen::AInstruction::AInstruction( const AInstruction & src ) {
	*this = src;
}

MindOpen::AInstruction::~AInstruction( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

MindOpen::AInstruction &	MindOpen::AInstruction::operator = ( const AInstruction & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::ostream &	operator << ( std::ostream& out, const MindOpen::AInstruction & in ) {
	out << std::string("<AInstruction> ") << in.getType();
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		MindOpen::AInstruction::getType() const {
	return (_type);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                        CONCRETE CLASS DEFINITIONS                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


IncrementPointer::IncrementPointer  () : AInstruction ("IncrementPointer") {}
IncrementPointer::~IncrementPointer () {}

void	IncrementPointer::execute( MindOpen::Program &prog ) const
{
	++byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementPointer::DecrementPointer  () : AInstruction ("DecrementPointer") {}
DecrementPointer::~DecrementPointer () {}

void	DecrementPointer::execute( MindOpen::Program &prog ) const
{
	--byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

IncrementByte::IncrementByte  () : AInstruction ("IncrementByte") {}
IncrementByte::~IncrementByte () {}

void	IncrementByte::execute( MindOpen::Program &prog ) const
{
	++(*byte);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementByte::DecrementByte  () : AInstruction ("DecrementByte") {}
DecrementByte::~DecrementByte () {}

void	DecrementByte::execute( MindOpen::Program &prog ) const
{
	--(*byte);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

PrintByte::PrintByte  () : AInstruction ("PrintByte") {}
PrintByte::~PrintByte () {}

void	PrintByte::execute( MindOpen::Program &prog ) const
{
	std::cout << *byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

GotoRightBracket::GotoRightBracket  () : AInstruction ("GotoRightBracket") {}
GotoRightBracket::~GotoRightBracket () {}

void	GotoRightBracket::execute( MindOpen::Program &prog ) const {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	prog._idx++;
	while (brackets_to_skip != 0)
	{
		if (prog._sourceCode[prog._idx] == ']')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (prog._sourceCode[prog._idx] == '[')
			++brackets_to_skip;
		prog._idx++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

GotoLeftBracket::GotoLeftBracket  () : AInstruction ("GotoLeftBracket") {}
GotoLeftBracket::~GotoLeftBracket () {}

void	GotoLeftBracket::execute( MindOpen::Program &prog ) const {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	prog._idx--;
	while (brackets_to_skip != 0)
	{
		if (prog._sourceCode[prog._idx] == '[')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (prog._sourceCode[prog._idx] == ']')
			++brackets_to_skip;
		prog._idx--;
	}
}
