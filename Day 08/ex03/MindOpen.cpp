/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:41:55 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 19:04:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <algorithm>
#include <ostream>
#include <fstream>
#include <sstream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MindOpen::MindOpen() {}

MindOpen::~MindOpen() {

	if (!_programs.empty())
		_programs.clear();
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	MindOpen::load ( std::string Filename ) {

	MindOpen::Program	prog   ( Filename );
	std::ifstream		infile ( Filename );

	if (!infile.is_open())
		throw InvalidFile();

	std::getline(infile, prog._sourceCode, '\0');
	size_t n_bytes = std::count (prog._sourceCode.begin(), prog._sourceCode.end(), '>');

	prog._ptr = new Byte [ n_bytes * 2 ] ;
	bzero(&prog._ptr, n_bytes * 2);

	for (prog._idx = 0; prog._idx < prog._sourceCode.size(); ++prog._idx)

		switch (prog._sourceCode[prog._idx]) {

			case '>':
				prog._instructionQueue.push( new IncrementPointer() );
				break ;

			case '<':
				prog._instructionQueue.push( new DecrementPointer() );
				break ;

			case '+':
				prog._instructionQueue.push( new IncrementByte() );
				break ;

			case '-':
				prog._instructionQueue.push( new DecrementByte() );
				break ;

			case '.':
				prog._instructionQueue.push( new PrintByte() );
				break ;

			case '[':
				if (*prog._ptr == '\0')
					GotoRightBracket(prog);
				break ;

			case ']':
				if (*prog._ptr != '\0')
					GotoLeftBracket(prog);
				break ;
		}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	MindOpen::executeAll( void ) {

	std::for_each(_programs.begin(), _programs.end(), [](Program program) {
		program.execute();
	});
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	MindOpen::execute( std::string Filename ) {

	std::vector<Program>::iterator it =
		std::find_if(_programs.begin(), _programs.end(), [&Filename](Program program) {
			return (program._filename == Filename);
		});

	if (it != _programs.end()) {
		(*it).execute();
	} else {
		throw FileNotFound();
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char *MindOpen::FileNotFound::what () const throw() {
	return ("~ File Not Found ~");
}

const char *MindOpen::InvalidFile::what () const throw() {
	return ("~ Invalid File ~");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

MindOpen::Program::Program( std::string Filename ) :
	_filename(Filename) {
}

MindOpen::Program::~Program() {

	AInstruction * tmp;

	while (!_instructionQueue.empty())
	{
		tmp = _instructionQueue.front();
		delete tmp;
		_instructionQueue.pop();
	}
}

void	MindOpen::Program::execute() {

	AInstruction * tmp;

	while (!_instructionQueue.empty())
	{
		tmp = _instructionQueue.front();
		tmp->execute(*this);
		delete tmp;
		_instructionQueue.pop();
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                             UTILITY FUNCTIONS                             */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

static void		GotoRightBracket( MindOpen::Program & prog ) {

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

static void		GotoLeftBracket( MindOpen::Program & prog ) {

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
