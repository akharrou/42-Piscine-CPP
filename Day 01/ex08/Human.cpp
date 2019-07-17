/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:24:55 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:22:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	Human::meleeAttack( std::string const & target ) {
	std::cout << "* meleeAttack( " << target << " ) *" << std::endl;
}

void	Human::rangedAttack( std::string const & target ) {
	std::cout << "* rangedAttack( " << target << " ) *" << std::endl;
}

void	Human::intimidatingShout( std::string const & target ) {
	std::cout << "* intimidatingShout( " << target << " ) *" << std::endl;
}

typedef struct {
	std::string	name;
	void (Human::*func)( const std::string &target );
} func_t;

void	Human::action(std::string const &action_name,
			std::string const &target)
{

	func_t actions[3] = {
		{ "meleeAttack",       &Human::meleeAttack       },
		{ "rangedAttack",      &Human::rangedAttack      },
		{ "intimidatingShout", &Human::intimidatingShout },
	};

	for ( int i = 0; i < 3; ++i ) {
		if (actions[i].name == action_name)
			(*this.*actions[i].func)(target);
	}

}

/* How do I create and use an array of pointer-to-member-function?
http://www.cs.technion.ac.il/users/yechiel/c++-faq/array-memfnptrs.html */
