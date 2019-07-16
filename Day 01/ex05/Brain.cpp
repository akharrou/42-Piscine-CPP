/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:39:02 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 10:59:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/* HELPER(S)  — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string to_base(intmax_t N, std::string base) {

	std::string hexstr = "0x";
	intmax_t base_n = base.length();
	intmax_t N_copy = N;
	int col = 1;

	while (N_copy >= base_n) {
		N_copy /= base_n;
		++col;
	}
	hexstr.resize((2 + col));
	while (col > 0)
	{
		hexstr[1 + col--] = base[N % base_n];
		N /= base_n;
	}
	return (hexstr);
}


/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Brain::Brain( int intel_lvl )
	: _intelligence_lvl(intel_lvl) { }

Brain::~Brain() { }


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Brain::identify()
{
	return (to_base((size_t)this, "0123456789ABCDEF"));
}
