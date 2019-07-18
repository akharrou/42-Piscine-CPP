/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:43:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 20:18:33 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

Fixed		eval_expr( std::string expr, size_t & i ) {

	Fixed	leftHandSide;

	leftHandSide = parseMultiplicative(expr, i);
	while (expr[i]) {

		if (expr[i] == ')') {
			++i;
			break ;
		} else if (expr[i] == '+') {
			leftHandSide = leftHandSide + parseMultiplicative(expr, ++i);
		} else if (expr[i] == '-') {
			leftHandSide = leftHandSide - parseMultiplicative(expr, ++i);
		} else if (expr[i] == ' ') {
			++i;
		} else {
			break ;
		}
	}
	return (leftHandSide);
}

Fixed		parseMultiplicative( std::string expr, size_t & i ) {

	Fixed	leftHandSide;

	leftHandSide = parseFixedNumber(expr, i);
	while (expr[i]) {

		if (expr[i] == '*') {
			leftHandSide = leftHandSide * parseFixedNumber(expr, ++i);
		} else if (expr[i] == '/') {
			leftHandSide = leftHandSide / parseFixedNumber(expr, ++i);
		} else if (expr[i] == ' ') {
			++i;
		} else {
			break ;
		}
	}
	return (leftHandSide);
}

Fixed		parseFixedNumber( std::string expr, size_t & i ) {

	Fixed	number;

	while (expr[i]) {

		if (expr[i] == '(') {
			return ( eval_expr(expr, ++i) );
		} else if (std::string("+-0123456789").find(expr[i]) != std::string::npos) {
			return Fixed( parseNumber(expr, i) );
		} else {
			++i;
		}
	}
	return (number);
}

float		parseNumber( std::string expr, size_t & i ) {

	std::istringstream inStrStream;
	float val;
	float sign;

	sign = (expr[i] == '-') ? -1 : 1;
	i   += (expr[i] == '-' || expr[i] == '+') ?  1 : 0;

	inStrStream.str(expr.substr(i));
	inStrStream >> val;

	while (std::string("0123456789.").find(expr[i]) != std::string::npos)
		++i;

	return ( val * sign );
}
