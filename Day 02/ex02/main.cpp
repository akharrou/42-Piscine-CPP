/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:41:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 16:14:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int		main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl << std::endl;

	std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n" << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	Fixed c( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << "min( " << c << ", " << b << " ) = " << Fixed::min( c, b ) << std::endl;
	std::cout << "max( " << c << ", " << b << " ) = " << Fixed::max( c, b ) << std::endl << std::endl;

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl << std::endl;

	std::cout << a << " / "<< c << " + "<< b << " - 0.00390625 + " << a << " = "
	          << a / c + b - ++a
			  << std::endl << std::endl;

	std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n" << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	Fixed n1( 2  );
	Fixed n2( 4  );
	Fixed n3( 8  );
	Fixed n4( 16 );
	Fixed n5( 24 );

	std::cout << n1 << " + " << n2 << " + " << n3 << " + " << n4 << " + " << n5 << " = "
	          << n1 + n2 + n3 + n4 + n5
			  << std::endl << std::endl;

	std::cout << n1 << " - " << n2 << " - " << n3 << " - " << n4 << " - " << n5 << " = "
	          << n1 - n2 - n3 - n4 - n5
			  << std::endl << std::endl;

	std::cout << n1 << " * " << n2 << " * " << n3 << " * " << n4 << " * " << n5 << " = "
	          << n1 * n2 * n3 * n4 * n5
			  << std::endl << std::endl;

	std::cout << n5 << " / " << n4 << " / " << n1 << " = "
	          << n5 / n4 / n1
			  << std::endl << std::endl;

	std::cout << n5 << " / " << n1 << " / " << n2 << " / " << n3 << " = "
	          << n5 / n1 / n2 / n3
			  << std::endl << std::endl;

	std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n" << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "(" << n1 << " > " << n2 << ")" << " is "
	          << ((n1 > n2) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n2 << " > " << n1 << ")" << " is "
	          << ((n2 > n1) ? "true" : "false")
	          << std::endl << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "(" << n1 << " == " << n2 << ")" << " is "
	          << ((n1 == n2) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n1 << " == " << n1 << ")" << " is "
	          << ((n1 == n1) ? "true" : "false")
	          << std::endl << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "(" << n3 << " != " << n4 << ")" << " is "
	          << ((n3 != n4) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n3 << " != " << n3 << ")" << " is "
	          << ((n3 != n3) ? "true" : "false")
	          << std::endl << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "(" << n3 << " <= " << n4 << ")" << " is "
	          << ((n3 <= n4) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n3 << " <= " << n3 << ")" << " is "
	          << ((n3 <= n3) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n3 << " <= " << n1 << ")" << " is "
	          << ((n3 <= n1) ? "true" : "false")
	          << std::endl << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "(" << n3 << " >= " << n4 << ")" << " is "
	          << ((n3 >= n4) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n3 << " >= " << n3 << ")" << " is "
	          << ((n3 >= n3) ? "true" : "false")
	          << std::endl;

	std::cout << "(" << n3 << " >= " << n2 << ")" << " is "
	          << ((n3 >= n2) ? "true" : "false")
	          << std::endl << std::endl;

	std::cout << "/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n" << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}
