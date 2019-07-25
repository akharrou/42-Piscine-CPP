/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:57 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 17:33:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include <iomanip>
#include "Array.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main()
{

	{
		Array <char>       char_ages   = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
		Array <int>        int_ages    = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
		Array <float>      float_ages  = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
		Array <double>     double_ages = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
		Array<std::string> string_ages = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };

		std::cout.precision(2);
		std::cout.setf( std::ios::fixed, std::ios::floatfield );

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Type : char\n\n";
		std::cout <<  char_ages    << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Type : int\n\n";
		std::cout <<  int_ages     << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Type : float\n\n";
		std::cout <<  float_ages   << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Type : double\n\n";
		std::cout <<  double_ages  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Type : string\n\n";
		std::cout <<  string_ages  << std::endl;
	}

	{
		Array <char>  _1;
		Array <int>   _2(10);
		Array <int>   _3(_2);

		Array <float> _4(10);
		Array <float> _5 = _4;

		std::cout.precision(2);
		std::cout.setf( std::ios::fixed, std::ios::floatfield );

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Arr #_1 : Type : char\n\n";
		std::cout <<  _1  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Arr #_2 : Type : int\n\n";
		std::cout <<  _2  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Arr #_3 : Type : int\n\n";
		std::cout <<  _3  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Arr #_4 : Type : float\n\n";
		std::cout <<  _4  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "Arr #_5 : Type : float\n\n";
		std::cout <<  _5  << std::endl;

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "_1 has a size of " << _1.size() << " elements" << std::endl;
		std::cout << "Out of bounds access attempt on _1[0] : Type : char\n\n";

		try {
			std::cout << _1[0] << std::endl;
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl << std::endl;
		}

		std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
		std::cout << "_4 has a size of " << _4.size() << " elements" << std::endl;
		std::cout << "Out of bounds access attempt on _4[11] : Type : float\n\n";

		try {
			std::cout << _4[11] << std::endl;
		} catch ( std::exception & e ) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	return (0);
}
