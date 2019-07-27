/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:21:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 15:44:47 by akharrou         ###   ########.fr       */
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


IncrementPointer::IncrementPointer() :
	AInstruction ("IncrementPointer") {
}

IncrementPointer::~IncrementPointer() {}

void	IncrementPointer::execute( Byte * byte ) const
{
	++byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementPointer::DecrementPointer() :
	AInstruction ("DecrementPointer") {
}

DecrementPointer::~DecrementPointer() {}

void	DecrementPointer::execute( Byte * byte ) const
{
	--byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

IncrementByte::IncrementByte() :
	AInstruction ("IncrementByte") {
}

IncrementByte::~IncrementByte() {}

void	IncrementByte::execute( Byte * byte ) const
{
	++(*byte);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementByte::DecrementByte() :
	AInstruction ("DecrementByte") {
}

DecrementByte::~DecrementByte() {}

void	DecrementByte::execute( Byte * byte ) const
{
	--(*byte);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

PrintByte::PrintByte() :
	AInstruction ("PrintByte") {
}

PrintByte::~PrintByte() {}

void	PrintByte::execute( Byte * byte ) const
{
	std::cout << *byte;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

GotoRightBracket::GotoRightBracket() :
	AInstruction ("GotoRightBracket") {
}

GotoRightBracket::~GotoRightBracket() {}

void	GotoRightBracket::execute( std::string Source, size_t & idx ) const {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	idx++;
	while (brackets_to_skip != 0)
	{
		if (Source[idx] == ']')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (Source[idx] == '[')
			++brackets_to_skip;
		idx++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

GotoLeftBracket::GotoLeftBracket() :
	AInstruction ("GotoLeftBracket") {
}

GotoLeftBracket::~GotoLeftBracket() {}

void	GotoLeftBracket::execute( std::string Source, size_t & idx ) const {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	idx--;
	while (brackets_to_skip != 0)
	{
		if (Source[idx] == '[')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (Source[idx] == ']')
			++brackets_to_skip;
		idx--;
	}
}
