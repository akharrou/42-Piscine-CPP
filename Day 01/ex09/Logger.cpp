/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:33:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:03:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Logger.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Logger::Logger( std::string filename )
	: _file(filename) { }

Logger::~Logger() { }


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Logger::makeLogEntry( std::string msg ) const {

	std::string timestamp;
	time_t rawtime;

	time (&rawtime);
	timestamp = std::string(ctime(&rawtime));
	timestamp[timestamp.length() - 1] = '\0';

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
