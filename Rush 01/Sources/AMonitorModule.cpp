/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:03:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:09:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AMonitorModule.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

AMonitorModule::AMonitorModule() {}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AMonitorModule::AMonitorModule( screen_t window ) :
	win( window ) {
}

AMonitorModule::AMonitorModule( const AMonitorModule & src ) {
	*this = src;
}

AMonitorModule::~AMonitorModule( void ) { }


/* PRIVATE OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - */

AMonitorModule &  AMonitorModule::operator = ( const AMonitorModule & rhs ) {
	(void)rhs;
	return (*this);
}
