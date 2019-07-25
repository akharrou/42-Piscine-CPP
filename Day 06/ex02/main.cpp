/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 01:08:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 23:34:41 by akharrou         ###   ########.fr       */
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

	identify_from_pointer   (   generate () );
	identify_from_reference ( * generate () );

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

	A *typeA;
	B *typeB;
	C *typeC;

	typeA = dynamic_cast <A*> (&p);
	if (typeA) {
		std::cout << "A\n";
		return ;
	}
	typeB = dynamic_cast <B*> (&p);
	if (typeB) {
		std::cout << "B\n";
		return ;
	}
	typeC = dynamic_cast <C*> (&p);
	if (typeC) {
		std::cout << "C\n";
		return ;
	}
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
