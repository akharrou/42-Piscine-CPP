/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:39:02 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 23:24:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

Brain::Brain( int intel_lvl )
	: _intelligence_lvl(intel_lvl)
{
}

Brain::~Brain()
{
}


/* MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		Brain::identify()
{
	return (std::to_string((size_t)this));
}


/* STATIC VARIABLE(S)  — — — — — — — — — — — — — — — — — — — — — — — — — — — */
