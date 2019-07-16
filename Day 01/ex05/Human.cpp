/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:39:02 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 23:35:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Human::Human( int intel_lvl ) : _brain(Brain(intel_lvl)) {
	std::cout << "A human is born (level " << intel_lvl << ")." << std::endl;
}

Human::Human() : _brain(Brain(10)) {
	std::cout << "A human is born (level " << 10 << ")." << std::endl;
}

Human::~Human() { }


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string	Human::identify() {
	return (_brain.identify());
}

Brain		Human::getBrain() {
	return (_brain);
}
