/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:30:46 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 21:50:45 by akharrou         ###   ########.fr       */
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
		// int max      = 50;
		// int mul      = 1;
		// int maxTimes = max * mul;

		// Span sp = Span( max );

		// for (int i = 0; i < maxTimes; i += mul)
		// 	sp.addNumber(i);

		// for_each(sp.begin(), sp.end(), [](int a) {
		// 	std::cout << a << std::endl;
		// });

	std::cout << "\n/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /\n\n";

		int max = 100;

		Span sp = Span( max );
		std::vector<int> vec(max, 5);

		sp.addNumber(vec.begin(), vec.end());

		for_each(sp.begin(), sp.end(), [](int a) {
			std::cout << a << std::endl;
		});

	std::cout << "\n/ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - /\n\n";

		std::cout << "shortestSpan : " << sp.shortestSpan () << std::endl;
		std::cout << "longestSpan  : " << sp.longestSpan  () << std::endl;

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
