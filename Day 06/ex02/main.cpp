/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 01:08:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/11 13:34:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Base {
	public:
		virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Base	*generate ( void );

void	identify_from_pointer   ( Base * p );
void	identify_from_reference ( Base & p );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	std::cout << "\nTEST : random\n";

	std::cout << "Pointer   : "; identify_from_pointer   (   generate () );
	std::cout << "Reference : "; identify_from_reference ( * generate () );

	std::cout << "\nTEST Pointers:\n";

	identify_from_pointer ( new A );
	identify_from_pointer ( new B );
	identify_from_pointer ( new C );

	std::cout << "\nTEST References:\n";

	identify_from_reference ( * ( new A ) );
	identify_from_reference ( * ( new B ) );
	identify_from_reference ( * ( new C ) );

	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void	identify_from_pointer ( Base * p ) {

	A *typeA;
	B *typeB;
	C *typeC;

	typeA = dynamic_cast <A*> (p);
	if (typeA) {
		std::cout << "A\n";
		return ;
	}
	typeB = dynamic_cast <B*> (p);
	if (typeB) {
		std::cout << "B\n";
		return ;
	}
	typeC = dynamic_cast <C*> (p);
	if (typeC) {
		std::cout << "C\n";
		return ;
	}
}

void	identify_from_reference ( Base & p ) {

	try {

		A & typeA = dynamic_cast <A&> (p);
		(void) typeA;
		std::cout << "A\n";
		return ;

	} catch ( std::bad_cast & ) {}

	try {

		B & typeB = dynamic_cast <B&> (p);
		(void) typeB;
		std::cout << "B\n";
		return ;

	} catch ( std::bad_cast & ) {}

	try {

		C & typeC = dynamic_cast <C&> (p);
		(void) typeC;
		std::cout << "C\n";
		return ;

	} catch ( std::bad_cast & ) {}

	std::cout << "Not A nor B nor C\n";
}

Base * generate(void) {

	srand(time(0));

	int i = rand() % 3;

	if (i == 0) {
		return ( dynamic_cast <Base*> ( new A() ));
	} else if (i == 1) {
		return ( dynamic_cast <Base*> ( new B() ));
	} else {
		return ( dynamic_cast <Base*> ( new C() ));
	}
}
