/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:36:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:42:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMonitorDisplay.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AMonitorDisplay::AMonitorDisplay( void ) {}

AMonitorDisplay::AMonitorDisplay( const AMonitorDisplay & src ) {
	*this = src;
}

AMonitorDisplay::~AMonitorDisplay () {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AMonitorDisplay &  AMonitorDisplay::operator = ( const AMonitorDisplay & rhs ) {
	(void)rhs;
	return (*this);
}
