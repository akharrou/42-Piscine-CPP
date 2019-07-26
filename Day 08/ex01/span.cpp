/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:23:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 00:22:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

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
		_container = rhs._container;
	}
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::multiset<int>::iterator	Span::begin() {
	return (_container.begin());
}

std::multiset<int>::iterator	Span::end() {
	return (_container.end());
}

unsigned int	Span::size() const {
	return (_container.size());
}

unsigned int	Span::maxsize() const {
	return (_N);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Span::addNumber( int n ) {
	(_container.size() < _N) ?
		_container.insert(n) : throw Span::MaxCapacityReached();
}

int		Span::shortestSpan() {
	return ( *(++_container.begin()) - *_container.begin() );
}

int		Span::longestSpan() {
	return ( *(--_container.end()) - *_container.begin() );
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char * Span::MaxCapacityReached::what() const throw() {
	return ("~ Max Capacity Reached ~");
}
