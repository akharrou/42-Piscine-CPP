/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:33:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:34:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>

class Logger {

	private:

		std::string		_file;

		void			logToFile( std::string str ) const;
		void			logToConsole( std::string str ) const;
		std::string		makeLogEntry( std::string msg ) const;

	public:

		Logger( std::string filename );
		~Logger();

		void	log( std::string const & dest, std::string const & message );

};

#endif /* LOGGER_HPP */
