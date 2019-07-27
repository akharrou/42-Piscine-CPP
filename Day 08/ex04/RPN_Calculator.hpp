/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_Calculator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:09:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 20:24:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALCULATOR_HPP
# define RPN_CALCULATOR_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RPN_Calculator {

	public:

		struct AOperation {

			AOperation();
			virtual ~AOperation();

			void execute() const = 0;
		};

		RPN_Calculator( void );
		RPN_Calculator( const RPN_Calculator & src );
		~RPN_Calculator( void );

		RPN_Calculator & operator = ( const RPN_Calculator & rhs );

		void	tokenize ();
		void	postfix  ();
		void	evaluate ();

	private:
		std::string _expression;
		std::stack<AOperation*, std::deque<AOperation*>> _op_stack;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class OP_Push :
	public RPN_Calculator::AOperation {

		public:
			OP_Push();
			~OP_Push();

		void execute();
};

class OP_Add :
	public RPN_Calculator::AOperation {

		public:
			OP_Add();
			~OP_Add();

		void execute();
};

class OP_Substract :
	public RPN_Calculator::AOperation {

		public:
			OP_Substract();
			~OP_Substract();

		void execute();
};

class OP_Multiply :
	public RPN_Calculator::AOperation {

		public:
			OP_Multiply();
			~OP_Multiply();

		void execute();
};

class OP_Divide :
	public RPN_Calculator::AOperation {

		public:
			OP_Divide();
			~OP_Divide();

		void execute();
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


#include "RPN_Calculator.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */



/* PROTECTED CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - */



/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RPN_Calculator::RPN_Calculator( void ) {}


RPN_Calculator::RPN_Calculator( const RPN_Calculator & src ) {
	*this = src;
}

RPN_Calculator::~RPN_Calculator( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RPN_Calculator &			RPN_Calculator::operator = ( const RPN_Calculator & rhs ) {
	return (*this);
}



/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




/* PRIVATE MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - */




/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */



/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* RPN_CALCULATOR_HPP */



