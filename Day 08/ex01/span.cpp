/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:23:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 21:50:57 by akharrou         ###   ########.fr       */
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

std::unordered_multiset<int>::iterator	Span::begin() {
	return (_container.begin());
}

std::unordered_multiset<int>::iterator	Span::end() {
	return (_container.end());
}

unsigned int	Span::size() const {
	return (_container.size());
}

unsigned int	Span::maxsize() const {
	return (_N);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

template < class IterType >
void	Span::addNumber( IterType Begin , IterType End ) {

	int elemCount = std::distance( Begin , End );

	if (_container.size() + elemCount < _N) {
		std::copy( Begin, End, _container.begin() );
	} else {
		throw Span::MaxCapacityReached();
	}
}

void	Span::addNumber( int n ) {

	if (_container.size() < _N) {
		_container.insert(n);
	} else {
		throw Span::MaxCapacityReached();
	}
}

int		Span::shortestSpan() {

	int first_min;
	int second_min;

	first_min  = *std::min_element(_container.begin(), _container.end());
	_container.erase(first_min);
	second_min = *std::min_element(_container.begin(), _container.end());
	_container.insert(first_min);

	return ( second_min - first_min );
}

int		Span::longestSpan() {
	return (
		*std::max_element(_container.begin(), _container.end())
		                     -
		*std::min_element(_container.begin(), _container.end())
	);
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

const char * Span::MaxCapacityReached::what() const throw() {
	return ("~ Max Capacity Reached ~");
}
