/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:22:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 23:00:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <sstream>
#include <iostream>
#include <ios>
#include <string>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define ISDIGIT(c) (c >= '0' && c <= '9')

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int ac, char **av) {

	if (ac < 2) {
		std::cout << "Usage: ./convert "
		          << "\033[4m""literal_value""\033[0m\n";
		return (1);
	}

	std::string param(av[1]);
	int i = param.find('.');
	int decimals = 0;

	/* Get Number of Decimals (default will be 1) */
	if (i != -1) {
		while ( param[++i] && ISDIGIT(param[i]) )
			  ++decimals;
	} else {
		decimals = 1;
	}

	char	var_char;
	int		var_int;
    float	var_float;
    double	var_double;

	std::cout.precision(decimals);
	std::cout.setf( std::ios::fixed, std:: ios::floatfield );

	try {

		var_char = static_cast <char> (std::stoi(param));

		if (std::stoi(param) > 127) {
			std::cout << "char: impossible\n";
		} else if (var_char < 32 || 126 < var_char) {
			std::cout << "char: Non displayble\n";
		} else {
			std::cout << "char: " << var_char << "\n";
		}

	} catch( const std::exception ) {
		std::cout << "char: impossible\n";
	}

	try {

		var_int = static_cast <int> (std::stoi(param));
		std::cout << "int: " << var_int << "\n";

	} catch( const std::exception ) {
		std::cout << "int: impossible\n";
	}

	try {

		var_float = (std::stof(param));
		std::cout << "float: " << var_float << "f\n";

	} catch( const std::exception ) {
		std::cout << "float: impossible\n";
	}

	try {

		var_double = (std::stod(param));
		std::cout << "double: " << var_double << "\n";

	} catch( const std::exception ) {
		std::cout << "double: impossible\n";
	}

	return (0);
}
