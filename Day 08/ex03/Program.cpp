/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:06:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 20:07:07 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

MindOpen::Program::Program( std::string Filename ) :
	_filename(Filename) {
}

MindOpen::Program::~Program() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	MindOpen::Program::execute() {

	AInstruction * tmp;

	while (!_instructionQueue.empty())
	{
		tmp = _instructionQueue.front();
		tmp->execute(*this);
		delete tmp;
		_instructionQueue.pop();
	}
	delete _init_ptr;
}
