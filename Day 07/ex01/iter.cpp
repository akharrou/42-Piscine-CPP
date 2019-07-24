/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:22:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 11:59:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
void iter( T **arr, size_t len, void (*f)(T elem) ) {

	for (size_t i = 0; i < len; ++i)
		f ( (*arr)[i] );
}

template < typename T >
void print( T elem ) {
	std::cout << elem << std::endl;
}

void printFloat( float elem ) {
	std::cout << elem << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main(int ac, char **av) {

	size_t arrSize = 5;

	if (ac > 1)
		arrSize = (std::atoi(av[1]));

	int          * int_arr    = new int         [arrSize];
	float        * float_arr  = new float       [arrSize];
	double       * double_arr = new double      [arrSize];
	std::string  * string_arr = new std::string [arrSize];

	for ( size_t i = 0; i < arrSize; ++i ) {

		int_arr    [i] = i;
		float_arr  [i] = i;
		double_arr [i] = i;
		string_arr [i] = std::to_string(i);
	}

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nType : int\n\n";
	iter <int>         ( & int_arr    , arrSize, & print <int>         );

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nType : float\n\n";
	iter <float>       ( & float_arr  , arrSize, & printFloat          );

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nType : double\n\n";
	iter <double>      ( & double_arr , arrSize, & print <double>      );

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nType : string\n\n";
	iter <std::string> ( & string_arr , arrSize, & print <std::string> );

	std::cout << std::endl;

	return (0);
}
