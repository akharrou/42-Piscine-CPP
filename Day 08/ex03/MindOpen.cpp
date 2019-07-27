/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:41:55 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 17:02:37 by akharrou         ###   ########.fr       */
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

	for (size_t i; i < prog._sourceCode.size(); ++i)
	{
		str = av[1];
		ptr = malloc(sizeof(char) * 2100);
		ft_memset(&ptr, 2100);
		i = 0;

		while (str[i])
		{
			switch ()

			if (str[i] == '>')
			{
				ptr++;
			}
			else if (str[i] == '<')
			{
				ptr--;
			}
			else if (str[i] == '+')
			{
				(*ptr)++;
			}
			else if (str[i] == '-')
			{
				(*ptr)--;
			}
			else if (str[i] == '.')
			{
				ft_putchar(*ptr);
			}
			else if (str[i] == '[' && *ptr == 0)
			{
				i = ft_go_to_matching_right_bracket(str, i);
			}
			else if (str[i] == ']' && *ptr != 0)
			{
				i = ft_go_to_matching_left_bracket(str, i);
			}
			i++;
		}
		return ;
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

		delete _instructionQueue.front();
		_instructionQueue.pop();
	}
}
