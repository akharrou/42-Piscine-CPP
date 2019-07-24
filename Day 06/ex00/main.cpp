/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:22:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 20:31:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <sstream>
#include <iostream>
#include <string>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int ac, char **av) {

	if (ac < 2) {
		std::cout << "Usage: ./convert "
		          << "\033[4m""literal_value""\033[0m\n";
		return (1);
	}

    char	var_char   = 0;
    int		var_int    = 0;
    float	var_float  = 0;
    double	var_double = 0;

	try {

		var_char = static_cast <char> (std::stoi(av[1]));

		if (var_char < 32 || 126 < var_char) {
			std::cout << "char: Non displayble\n";
		} else {
			std::cout << "char: " << var_char << "\n";
		}

	} catch( const std::exception & e ) {
		std::cout << "char: impossible\n";
	}

	try {

        var_int = static_cast <int> (std::stoi(av[1]));
		std::cout << "int: " << var_int << "\n";

	} catch( const std::exception & e ) {
		std::cout << "int: impossible\n";
	}

	try {

        var_float = static_cast <float> (std::stof(av[1]));
		std::cout << "float: " << var_float << "\n";

	} catch( const std::exception & e ) {
		std::cout << "float: impossible\n";
	}

	try {

        var_double = static_cast <double> (std::stod(av[1]));
		std::cout << "double: " << var_double << "\n";

	} catch( const std::exception & e ) {
		std::cout << "double: impossible\n";
	}

	return (0);
}
