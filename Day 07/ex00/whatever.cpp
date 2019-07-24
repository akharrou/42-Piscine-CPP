/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:11:57 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 11:21:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
void	swap( T & a, T & b ) {

	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
T & max( T & a, T & b ) {
	return ( (a > b) ? a : b );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
T & min( T & a, T & b ) {
	return ( (a < b) ? a : b );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
		std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
		std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	}

	return (0);
}
