/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_Calculator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:09:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 01:52:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALCULATOR_HPP
# define RPN_CALCULATOR_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <deque>
# include <stack>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define ISOPERATOR(c) (c == "+" || c == "-" || c == "*" || c == "/")
#define ISDIGIT(c)    ('0' <= c && c <= '9')

#define IS_PAROPEN(tok) (tok == "(")
#define IS_PRECEDENCE_LVL_2(tok) (tok == "+" || tok == "-")
#define IS_PRECEDENCE_LVL_3(tok) (tok == "*" || tok == "/")
#define IS_PARCLOSE(tok) (tok == ")")

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RPN_Calculator {

	public:

		struct Token {

			std::string tokVal;
			std::string type;

			Token( std::string type, std::string tokVal );
			virtual ~Token() = 0;
		};

		RPN_Calculator( void );
		RPN_Calculator( const RPN_Calculator & src );
		~RPN_Calculator( void );

		RPN_Calculator & operator = ( const RPN_Calculator & rhs );

		int		evaluateInfix   ( std::string expression );
		int		evaluatePostfix ( std::deque <Token *> tokens );

		std::deque <Token *>	tokenize   ( std::string infix_expression );
		std::deque <Token *>	postfixify ( std::deque <Token *> tokenObjs );

		struct InvalidExpression : public std::exception {
			virtual const char * what() const throw();
		};

		struct DivisionByZero : public std::exception {
			virtual const char * what() const throw();
		};

};

std::ostream & operator << ( std::ostream & out, const RPN_Calculator::Token & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Num :
	public RPN_Calculator::Token {

	Num( std::string val );
	~Num();
};

struct ParOpen :
	public RPN_Calculator::Token {

	ParOpen();
	~ParOpen();
};

struct ParClose :
	public RPN_Calculator::Token {

	ParClose();
	~ParClose();
};

struct Push :
	public RPN_Calculator::Token {

	Push();
	~Push();
};

struct Add :
	public RPN_Calculator::Token {

	Add();
	~Add();
};

struct Substract :
	public RPN_Calculator::Token {

	Substract();
	~Substract();
};

struct Multiply :
	public RPN_Calculator::Token {

	Multiply();
	~Multiply();
};

struct Divide :
	public RPN_Calculator::Token {

	Divide();
	~Divide();
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* RPN_CALCULATOR_HPP */
