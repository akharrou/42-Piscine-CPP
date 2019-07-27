/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:21:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 18:16:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         ABSTRACT CLASS DEFINITION                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MindOpen::AInstruction::AInstruction( void ) {}

MindOpen::AInstruction::AInstruction( const AInstruction & src ) {
	*this = src;
}

MindOpen::AInstruction::~AInstruction( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

MindOpen::AInstruction &
	MindOpen::AInstruction::operator = ( const AInstruction & rhs ) {
	return (*this);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                        CONCRETE CLASS DEFINITIONS                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	IncrementPointer::execute( MindOpen::Program & prog ) const
{
	++prog._ptr;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	DecrementPointer::execute( MindOpen::Program & prog ) const
{
	--prog._ptr;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	IncrementByte::execute( MindOpen::Program & prog ) const
{
	++(*prog._ptr);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	DecrementByte::execute( MindOpen::Program & prog ) const
{
	--(*prog._ptr);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	PrintByte::execute( MindOpen::Program & prog ) const
{
	std::cout << *prog._ptr;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	GotoRightBracket::execute( MindOpen::Program & prog ) const {

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

void	GotoLeftBracket::execute( MindOpen::Program & prog ) const {

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
