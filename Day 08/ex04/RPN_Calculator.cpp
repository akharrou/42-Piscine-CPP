/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_Calculator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:46:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 20:46:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN_Calculator.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RPN_Calculator::RPN_Calculator( void ) {}


RPN_Calculator::RPN_Calculator( const RPN_Calculator & src ) {
	*this = src;
}

RPN_Calculator::~RPN_Calculator( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RPN_Calculator & RPN_Calculator::operator = ( const RPN_Calculator & rhs ) {
	return (*this);
}
