/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:30:46 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/11 13:20:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include <vector>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "span.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan () << std::endl;
		std::cout << sp.longestSpan  () << std::endl;
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	{
		int max      = 20;
		int mul      = 5;
		int maxTimes = max * mul;

		Span sp = Span( max );
		std::vector<int> vec;

		for (int i = 0; i < maxTimes; i += mul)
			vec.push_back(i);

		sp.addNumber(vec.begin(), vec.end());

		for ( Span::iterator first = sp.begin(); first != sp.end(); ++first )
			std::cout << *first << std::endl;

	std::cout << "\n/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /\n\n";

	try {

		std::cout << "shortestSpan : " << sp.shortestSpan () << std::endl;
		std::cout << "longestSpan  : " << sp.longestSpan  () << std::endl;

	} catch ( std::exception & e ) {

		std::cout << e.what() << std::endl;
	}

	std::cout << "\n/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /\n\n";

		try {
			sp.addNumber(1);
		} catch ( std::exception & e ) {
			std::cout << "oops : " << e.what() << std::endl;
		}

	std::cout << "\n/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /\n\n";

	}

	return (0);
}
