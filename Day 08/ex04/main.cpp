/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:08:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 01:49:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "RPN_Calculator.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int ac, char **av) {

	RPN_Calculator inst;

	if (ac == 2) {

		try {

			inst.evaluateInfix(av[1]);

		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
