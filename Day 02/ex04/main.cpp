/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:16:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 20:07:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      Evaluates simple arithmetic expressions as fixed point values.
*/

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#include "eval_expr.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

int		main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./eval_expr "
		          << UNDERLINED("expression")
				  << std::endl;
		return (1);
	}

	size_t i = 0;
	std::cout << eval_expr( std::string(av[1]), i ) << std::endl;

	return (0);
}
