/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:00:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 16:30:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <array>
#include <vector>
#include <deque>
#include <list>

#include <set>
#include <unordered_set>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "easyfind.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	std::array  <int, 10>  arr0 = {{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }};
	std::vector <int>      arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::deque  <int>      arr2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list   <int>      arr3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::set    <int>      arr4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::unordered_set <int> arr5 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int max = 20;

	for (int i = 0; i < max; ++i) {

		try {

			easyfind(arr0, i);
			easyfind(arr1, i);
			easyfind(arr2, i);
			easyfind(arr3, i);
			easyfind(arr4, i);
			easyfind(arr5, i);

			std::cout << i << " was found" << std::endl;

		} catch ( std::string & e ) {
			std::cout << e << std::endl;
		}

	}

	return (0);
}
