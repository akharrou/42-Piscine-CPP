/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_Calculator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:46:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 01:14:50 by akharrou         ###   ########.fr       */
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

	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

int		RPN_Calculator::evaluateInfix   ( std::string expression ) {

	return ( evaluatePostfix ( postfixify ( tokenize ( expression ) ) ) );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::deque <RPN_Calculator::Token *>
	RPN_Calculator::tokenize( std::string infix_expression )
{
	std::deque <std::string> tokens;
	std::deque <RPN_Calculator::Token *> objTokens;

    std::string expr(infix_expression);
	std::string	tmp;

	for (size_t i = 0; i < expr.length(); ++i) {

		if (ISDIGIT(expr[i])) {

			tmp = std::to_string(std::stoi(&expr[i]));
			tokens.push_back(tmp);
			i += tmp.length() - 1;

		} else if (expr[i] != ' ') {
				tokens.push_back(expr.substr(i, 1));
		}
	}

	std::cout << "Tokens : ";
	for_each(tokens.begin(), tokens.end(), [&objTokens](std::string token) {

		if (token == "+") {
			objTokens.push_back( new Add );
			std::cout << "Op(+) ";
		}
		else if (token == "-") {
			objTokens.push_back( new Substract );
			std::cout << "Op(-) ";
		}
		else if (token == "*") {
			objTokens.push_back( new Multiply );
			std::cout << "Op(*) ";
		}
		else if (token == "/") {
			objTokens.push_back( new Divide );
			std::cout << "Op(/) ";
		}
		else if (token == "(") {
			objTokens.push_back( new ParOpen );
			std::cout << "ParOpen ";
		}
		else if (token == ")") {
			objTokens.push_back( new ParClose );
			std::cout << "ParClose ";
		}
		else {
			objTokens.push_back( new Num(token) );
			std::cout << "Num(" << token << ") ";
		}
	});
	std::cout << std::endl;

	return (objTokens);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::deque  <RPN_Calculator::Token *>
	RPN_Calculator::postfixify ( std::deque <RPN_Calculator::Token *> tokenObjs )
{
	std::deque <RPN_Calculator::Token *> postfixVector;
	std::stack  <RPN_Calculator::Token *> tmpStack;

	std::deque<RPN_Calculator::Token *>::iterator it = tokenObjs.begin();

	std::cout << "Postfix : ";
	for (; it != tokenObjs.end(); ++it)
	{
		if (IS_PAROPEN((*it)->tokVal)) {

			tmpStack.push((*it));

		} else if (IS_PRECEDENCE_LVL_2((*it)->tokVal)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_2(tmpStack.top()->tokVal)) {

				std::cout << *(tmpStack.top()) << " ";
				postfixVector.push_back(tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push((*it));

		} else if (IS_PRECEDENCE_LVL_3((*it)->tokVal)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_3(tmpStack.top()->tokVal)) {

				std::cout << *(tmpStack.top()) << " ";
				postfixVector.push_back(tmpStack.top());
				tmpStack.pop();
			}
			tmpStack.push((*it));

		} else if (IS_PARCLOSE((*it)->tokVal)) {

			if (!tmpStack.empty()) {
				while (!tmpStack.empty() && !IS_PAROPEN(tmpStack.top()->tokVal)) {

					std::cout << *(tmpStack.top()) << " ";
					postfixVector.push_back(tmpStack.top());
					tmpStack.pop();
				}
				if (tmpStack.empty())
					throw RPN_Calculator::InvalidExpression();
				tmpStack.pop();
			}

		} else {

			std::cout << *(*it) << " ";
			postfixVector.push_back((*it));
		}
	}

	while (!tmpStack.empty()) {

		std::cout << *tmpStack.top() << " ";
		postfixVector.push_back(tmpStack.top());
		tmpStack.pop();
	}

	return (postfixVector);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct {
	const char *op;
	int (*ft_op)(int, int);
} op_t;

#define TOTAL_OPERATIONS (4)
op_t operations[TOTAL_OPERATIONS] = {

	{ "+", [](int a, int b) { return a + b; } },
	{ "-", [](int a, int b) { return a - b; } },
	{ "*", [](int a, int b) { return a * b; } },
	{ "/", [](int a, int b) {
		if (b == 0)
			throw RPN_Calculator::DivisionByZero();
		return a / b;
	}},
};

int	RPN_Calculator::evaluatePostfix ( std::deque <RPN_Calculator::Token *> postfixVector ) {

	std::stack<RPN_Calculator::Token *> tmpStack;

	int lhs_operand;
	int rhs_operand;
	int res = 0;

	std::deque<RPN_Calculator::Token *>::iterator it = postfixVector.begin();

	if (it == postfixVector.end())
		return (res);

	for (; it != postfixVector.end(); ++it)
	{

		if (!ISOPERATOR(postfixVector.front()->tokVal)) {

			tmpStack.push(*it);

		} else {

			for (int i = 0; i < TOTAL_OPERATIONS; ++i) {

				if (postfixVector.front()->tokVal == operations[i].op) {

					postfixVector.pop_front();

					rhs_operand = 0;
					lhs_operand = 0;

					if (!tmpStack.empty()) {

						rhs_operand = std::stoi(tmpStack.top()->tokVal);
						tmpStack.pop();

						if (!tmpStack.empty()) {
							lhs_operand = std::stoi(tmpStack.top()->tokVal);
							tmpStack.pop();
						}
					}

					tmpStack.push(
						new Num(std::to_string(operations[i].ft_op(rhs_operand, lhs_operand)))
					);
				}
			}
		}
	}

	try {

		res = std::stoi(tmpStack.top()->tokVal);
		tmpStack.pop();

	} catch ( std::exception & e ) {
		throw RPN_Calculator::InvalidExpression();
	}

	if (!tmpStack.empty())
		throw RPN_Calculator::InvalidExpression();

	std::cout << "Result : " << res << std::endl;

	return (res);
}

/* EXCEPTIONS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char *RPN_Calculator::InvalidExpression::what() const throw() {
	return ("~ Invalid Expression ~");
}

const char *RPN_Calculator::DivisionByZero::what() const throw() {
	return ("~ Forbidden Operation : division by zero ~");
}
