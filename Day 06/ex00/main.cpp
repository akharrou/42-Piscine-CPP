/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:22:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 19:45:20 by akharrou         ###   ########.fr       */
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

	char	var_char = 0;
	int		var_int = 0;
	float	var_float = 0;
	double	var_double = 0;

	std::string	param(av[1]);


        var_int    = static_cast <int>    (std::stoi(param));
        var_float  = static_cast <float>  (std::stof(param));
        var_double = static_cast <double> (std::stod(param));
	try {

        var_char   = static_cast <char>   (std::stoi(param));

		std::cout <<

	} catch(const std::exception & e) {}
	try {


	} catch(const std::exception & e) {}
	try {


	} catch(const std::exception & e) {}
	try {


	} catch(const std::exception & e) {}

		std::cout << "char:  " << var_char << "\n"
				  << "int:  " << var_int << "\n"
				  << "float:  " << var_float << "f\n"
				  << "double: " << var_double << "\n";

(void)var_char;
(void)var_int;
(void)var_float;
(void)var_double;
	return (0);
}



/*
	std::stringstream	param_copy_1(av[1]);
	std::stringstream	param_copy_2(av[1]);
	std::stringstream	param_copy_3(av[1]);
	std::stringstream	param_copy_4(av[1]);

	try {

		param_copy_1 >> var_char;
		param_copy_2 >> var_int;
		param_copy_3 >> var_float;
		param_copy_4 >> var_double;

		std::cout << "char:  " << var_char << "\n"
				  << "int:  " << var_int << "\n"
				  << "float:  " << var_float << "f\n"
				  << "double: " << var_double << "\n";

	} catch(const std::exception & e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}
 */
