/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:33:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:34:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Logger.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Logger::Logger( std::string filename )
	: _file(filename) { }

Logger::~Logger() { }


/* PRIVATE MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Logger::makeLogEntry( std::string msg ) const {

	std::string timestamp;
	time_t rawtime;

	time (&rawtime);
	timestamp = std::string(ctime(&rawtime));
	timestamp.erase(timestamp.length() - 1, 1);

	return ("[" + timestamp + "] : " + msg);
}

void	Logger::logToFile( std::string str ) const {

	std::ofstream	outfile(_file);

	if (outfile.is_open()) {
		outfile << str;
		outfile.close();
	}
}

void	Logger::logToConsole( std::string str ) const {
	std::cout << str << std::flush;
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

typedef struct {
	std::string name;
	void (Logger::*logft)(std::string) const;
} func_t;

void	Logger::log(std::string const &dest, std::string const &message) {

	func_t logfuncs[2] = {
		{ "logToFile",    &Logger::logToFile    },
		{ "logToConsole", &Logger::logToConsole }
	};

	for ( int i = 0; i < 2; ++i ) {
		if (logfuncs[i].name == dest)
			(*this.*logfuncs[i].logft)( makeLogEntry(message) );
	}

}
