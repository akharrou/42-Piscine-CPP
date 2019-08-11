/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:23:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/08/11 13:21:41 by akharrou         ###   ########.fr       */
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

Span::iterator	Span::begin() {
	return ( _container.begin() );
}

Span::iterator	Span::end() {
	return ( _container.end() );
}

unsigned int	Span::size() const {
	return ( _container.size() );
}

unsigned int	Span::maxsize() const {
	return ( _N );
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Span::addNumber( int n ) {

	( _container.size() < _N ) ?
		_container.insert(n) :
		throw Span::MaxCapacityReached();
}

int		Span::shortestSpan() {

	if ( _container.size() < 2 )
		return ( 0 );

	Span::iterator beforeLast = --_container.end();
	Span::iterator cur        = _container.begin();
	int shortestSpan = 2147483647;
	int tmp;

	while ( cur != beforeLast ) {
		tmp = *cur++ - *cur;
		shortestSpan = MIN ( shortestSpan , ABS( tmp ) );
	}

	return ( shortestSpan );
}

int		Span::longestSpan() {
	return ( *(--_container.end()) - *_container.begin() );
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char * Span::MaxCapacityReached::what() const throw() {
	return ("~ Max Capacity Reached ~");
}
