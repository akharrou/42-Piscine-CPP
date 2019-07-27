/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:41:55 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 18:52:02 by akharrou         ###   ########.fr       */
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

	for (char c : prog._sourceCode)

		switch (c) {

			case '>':
				prog._instructionQueue.push( new IncrementPointer() );
				++prog._idx;
				break ;

			case '<':
				prog._instructionQueue.push( new DecrementPointer() );
				++prog._idx;
				break ;

			case '+':
				prog._instructionQueue.push( new IncrementByte() );
				++prog._idx;
				break ;

			case '-':
				prog._instructionQueue.push( new DecrementByte() );
				++prog._idx;
				break ;

			case '.':
				prog._instructionQueue.push( new PrintByte() );
				++prog._idx;
				break ;

			case '[':
				if (*prog._ptr == '\0')
					prog._instructionQueue.push( new GotoRightBracket() );
				break ;

			case ']':
				if (*prog._ptr != '\0')
					prog._instructionQueue.push( new GotoLeftBracket() );
				break ;

			default:
				++prog._idx;
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

	while (!_instructionQueue.empty()) {

		_instructionQueue.front();
		_instructionQueue.pop();
	}
}

void	MindOpen::Program::execute() {

	AInstruction *tmp;

	while (!_instructionQueue.empty()) {

		tmp = _instructionQueue.front();

		tmp->execute(*this);
		delete tmp;

		_instructionQueue.pop();
	}
}
