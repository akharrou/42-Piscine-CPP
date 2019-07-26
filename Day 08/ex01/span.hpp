/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:40:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 17:01:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <vector>

# include <exception>
# include <stdexcept>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Span {

	private:

		unsigned int		_N;
		unsigned int		_size;
		std::vector<int>	_arr;

	public:

		struct MaxCapacityReached : public std::exception {
			virtual const char * what() throw();
		};

		Span( void );
		Span( unsigned int N );
		Span( const Span & src );
		~Span( void );

		Span &		operator = ( const Span & rhs );

		unsigned int	getSize() const;
		void	addNumber( int );

		unsigned int	shortestSpan () const;
		unsigned int	longestSpan  () const;

};

#include "Span.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Span::Span( void ) :
	_N(0) {
}

Span::Span( unsigned int N ) :
	_N(N) {
}

Span::Span( const Span & src ) {
	*this = src;
}

Span::~Span( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Span &	Span::operator = ( const Span & rhs ) {

	if (this != &rhs) {
		_N = rhs._N;
		_arr = rhs._arr;
		_size = rhs._size;
	}
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

unsigned int	Span::getSize() const {
	return (_size);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Span::addNumber( int n ) {

	if (_size < _N) {
		_arr.push_back(n);
		++_size;
	} else {
		throw Span::MaxCapacityReached();
	}
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char * Span::MaxCapacityReached::what() throw() {
	return ("~ Max Capacity Reached ~");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPAN_HPP */
