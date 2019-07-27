/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokens.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:37:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 00:58:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN_Calculator.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

RPN_Calculator::Token::Token( std::string type, std::string tokVal )
	: tokVal(tokVal), type(type) {}

RPN_Calculator::Token::~Token() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Num::Num( std::string val ) :
	RPN_Calculator::Token("Num", val) {
}

Num::~Num() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ParOpen::ParOpen() :
	RPN_Calculator::Token("", "(") {
}

ParOpen::~ParOpen() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

ParClose::ParClose() :
	RPN_Calculator::Token("", ")") {
}

ParClose::~ParClose() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Push::Push() :
	RPN_Calculator::Token("OP", "Push") {
}

Push::~Push() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Add::Add() :
	RPN_Calculator::Token("OP", "+") {
}

Add::~Add() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Substract::Substract() :
	RPN_Calculator::Token("OP", "-") {
}

Substract::~Substract() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Multiply::Multiply() :
	RPN_Calculator::Token("OP", "*") {
}

Multiply::~Multiply() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Divide::Divide() :
	RPN_Calculator::Token("OP", "/") {
}

Divide::~Divide() {}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::ostream & operator << ( std::ostream & out, const RPN_Calculator::Token & in ) {

	out << in.type << "(" << in.tokVal << ")";
	return (out);
}
