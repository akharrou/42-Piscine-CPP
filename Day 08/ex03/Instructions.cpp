/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:21:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 19:42:06 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

IncrementPointer::IncrementPointer() {}
IncrementPointer::~IncrementPointer() {}

void	IncrementPointer::execute( MindOpen::Program & prog ) const
{
	++prog._ptr;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementPointer::DecrementPointer() {}
DecrementPointer::~DecrementPointer() {}

void	DecrementPointer::execute( MindOpen::Program & prog ) const
{
	--prog._ptr;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

IncrementByte::IncrementByte() {}
IncrementByte::~IncrementByte() {}

void	IncrementByte::execute( MindOpen::Program & prog ) const
{
	++(*prog._ptr);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

DecrementByte::DecrementByte() {}
DecrementByte::~DecrementByte() {}

void	DecrementByte::execute( MindOpen::Program & prog ) const
{
	--(*prog._ptr);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

PrintByte::PrintByte() {}
PrintByte::~PrintByte() {}

void	PrintByte::execute( MindOpen::Program & prog ) const
{
	std::cout << *prog._ptr;
}
