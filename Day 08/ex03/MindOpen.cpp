/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:41:55 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 19:43:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <algorithm>
#include <fstream>

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

static void		GotoRightBracket ( std::string sourceCode, size_t & idx );
static void		GotoLeftBracket  ( std::string sourceCode, size_t & idx );

void	MindOpen::load ( std::string Filename ) {

	MindOpen::Program	prog   ( Filename );
	std::ifstream		infile ( Filename );

	std::string			sourceCode;
	Byte *				ptr;

	if (!infile.is_open())
		throw InvalidFile();

	std::getline(infile, sourceCode, '\0');
	infile.close();

	size_t n_bytes = std::count(sourceCode.begin(), sourceCode.end(), '>');

	ptr = new Byte [ n_bytes * 2 ] ;
	bzero(ptr, n_bytes * 2);

	prog._ptr = new Byte [ n_bytes * 2 ] ;
	bzero(prog._ptr, n_bytes * 2);

	for (size_t i = 0; i < sourceCode.size(); ++i)

		switch (sourceCode[i]) {

			case '>':
				++ptr;
				prog._instructionQueue.push( new IncrementPointer() );
				break ;

			case '<':
				--ptr;
				prog._instructionQueue.push( new DecrementPointer() );
				break ;

			case '+':
				++(*ptr);
				prog._instructionQueue.push( new IncrementByte() );
				break ;

			case '-':
				--(*ptr);
				prog._instructionQueue.push( new DecrementByte() );
				break ;

			case '.':
				prog._instructionQueue.push( new PrintByte() );
				break ;

			case '[':
				if (*ptr == '\0')
					GotoRightBracket( sourceCode, i );
				break ;

			case ']':
				if (*ptr != '\0')
					GotoLeftBracket( sourceCode, i );
				break ;
		}

	// delete [] ptr;
	_programs.push_back(prog);
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

	// delete [] _ptr;

	// AInstruction * tmp;

	// while (!_instructionQueue.empty())
	// {
	// 	tmp = _instructionQueue.front();
	// 	if (tmp != NULL)
	// 		delete tmp;
	// 	_instructionQueue.pop();
	// }
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

static void		GotoRightBracket( std::string sourceCode, size_t & idx ) {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	idx++;
	while (brackets_to_skip != 0)
	{
		if (sourceCode[idx] == ']')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (sourceCode[idx] == '[')
			++brackets_to_skip;
		idx++;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

static void		GotoLeftBracket( std::string sourceCode, size_t & idx ) {

	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	idx--;
	while (brackets_to_skip != 0)
	{
		if (sourceCode[idx] == '[')
		{
			--brackets_to_skip;
			if (brackets_to_skip == 0)
				return ;
		}
		else if (sourceCode[idx] == ']')
			++brackets_to_skip;
		idx--;
	}
}
