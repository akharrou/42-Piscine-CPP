/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_Calculator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:09:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 23:24:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALCULATOR_HPP
# define RPN_CALCULATOR_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <sstream>
# include <algorithm>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <vector>
# include <stack>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define ISDIGIT(c) ('0' <= c && c <= '9')

#define IS_PAROPEN(tok) (tok == "(")
#define IS_PRECEDENCE_LVL_2(tok) (tok == "+" || tok == "-")
#define IS_PRECEDENCE_LVL_3(tok) (tok == "*" || tok == "/")
#define IS_PARCLOSE(tok) (tok == ")")

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RPN_Calculator {

	public:

		struct Token {

			std::string tokVal;

			Token();
			Token( std::string tokVal );
			virtual ~Token();

			virtual void execute() const = 0;
		};

		RPN_Calculator( void );
		RPN_Calculator( const RPN_Calculator & src );
		~RPN_Calculator( void );

		RPN_Calculator & operator = ( const RPN_Calculator & rhs );

		int		evaluateInfix   ( std::string expression );
		int		evaluatePostfix ( std::stack <Token *> tokens );

		std::vector <std::string>	tokenize   ( std::string infix_expression );
		std::stack  <Token *>		postfixify ( std::vector <std::string> tokens );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Num :
	public RPN_Calculator::Token {

		public:
			Num();
			Num( std::string tokVal );
			~Num();

		void execute();
};

class ParOpen :
	public RPN_Calculator::Token {

		public:
			ParOpen();
			ParOpen( std::string tokVal );
			~ParOpen();

		void execute();
};

class ParClose :
	public RPN_Calculator::Token {

		public:
			ParClose();
			ParClose( std::string tokVal );
			~ParClose();

		void execute();
};

class Push :
	public RPN_Calculator::Token {

		public:
			Push();
			Push( std::string tokVal );
			~Push();

		void execute();
};

class Add :
	public RPN_Calculator::Token {

		public:
			Add();
			Add( std::string tokVal );
			~Add();

		void execute();
};

class Substract :
	public RPN_Calculator::Token {

		public:
			Substract();
			Substract( std::string tokVal );
			~Substract();

		void execute();
};

class Multiply :
	public RPN_Calculator::Token {

		public:
			Multiply();
			Multiply( std::string tokVal );
			~Multiply();

		void execute();
};

class Divide :
	public RPN_Calculator::Token {

		public:
			Divide();
			Divide( std::string tokVal );
			~Divide();

		void execute();
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct {
	std::string token;
	RPN_Calculator::Token *(*tokenConstructor)(void);
} token_t;

token_t tokens = {

	{ "(",  [](void) { return new ParOpen   } },
	{ ")",  [](void) { return new ParClose  } },
	{ "+",  [](void) { return new Add       } },
	{ "-",  [](void) { return new Substract } },
	{ "*",  [](void) { return new Multiply  } },
	{ "/",  [](void) { return new Divide    } },
	{ "->", [](void) { return new Push      } },
	{ "N",  [](void) { return new Num       } }
};


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */



/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

int		RPN_Calculator::evaluateInfix   ( std::string expression ) {
	return ( evaluatePostfix( postfix( tokenize( expression ) ) ) );
}

int		RPN_Calculator::evaluatePostfix ( std::stack <Token *> tokens ) {
	return (0);
}

std::vector <std::string>
	RPN_Calculator::tokenize ( std::string infix_expression )
{
	std::vector <std::string> tokens;

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

	std::vector<std::string>::iterator it;

	std::cout << "Tokens: ";
	for_each(tokens.begin(), tokens.end(), [](std::string token) {

		if (token == "+")
			std::cout << "Op(+) ";
		else if (token == "-")
			std::cout << "Op(-) ";
		else if (token == "*")
			std::cout << "Op(*) ";
		else if (token == "/")
			std::cout << "Op(/) ";
		else if (token == "(")
			std::cout << "ParOpen ";
		else if (token == ")")
			std::cout << "ParClose ";
		else
			std::cout << "Num(" << token << ") ";
	});
	return (tokens);
}

std::stack  <RPN_Calculator::Token *>
	RPN_Calculator::postfixify  ( std::vector <std::string> tokens )
{
	std::vector <std::string> postfixVec;
	std::vector <std::string> tmpStack;

	std::vector <Token *>     postfixTokenVec;

	std::vector<std::string>::iterator it;

	for (it = tokens.begin(); it != tokens.end(); ++it)
	{
		std::cout << *it << " ";

		if (IS_PAROPEN(*it)) {

			tmpStack.push_back(*it);

		} else if (IS_PRECEDENCE_LVL_2(*it)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_2(tmpStack.back())) {
				postfixVec.push_back(tmpStack.back());
				tmpStack.pop_back();
			}
			tmpStack.push_back(*it);

		} else if (IS_PRECEDENCE_LVL_3(*it)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_3(tmpStack.back())) {
				postfixVec.push_back(tmpStack.back());
				tmpStack.pop_back();
			}
			tmpStack.push_back(*it);

		} else if (IS_PARCLOSE(*it)) {

			if (!tmpStack.empty()) {
				while (!tmpStack.empty() && !IS_PAROPEN(tmpStack.back())) {
					postfixVec.push_back(tmpStack.back());
					tmpStack.pop_back();
				}
				tmpStack.pop_back();
			}

		} else {
			postfixVec.push_back(*it);
		}
	};

	while (!tmpStack.empty()) {
		postfixVec.push_back(tmpStack.back());
		tmpStack.pop_back();
	}

	std::cout << "Postfix : ";
	for_each(postfixVec.begin(), postfixVec.end(), [](std::string token) {

		if (token == "+") {
			postfixTokenVec.push_back( new );
			std::cout << "Op(+) ";
		}
		else if (token == "-") {
			postfixTokenVec.push_back( new );
			std::cout << "Op(-) ";
		}
		else if (token == "*") {
			postfixTokenVec.push_back( new );
			std::cout << "Op(*) ";
		}
		else if (token == "/") {
			postfixTokenVec.push_back( new );
			std::cout << "Op(/) ";
		}
		else {
			postfixTokenVec.push_back();
			std::cout << "Num(" << token << ") ";
		}
	});

	return (postfixVec);
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* RPN_CALCULATOR_HPP */



