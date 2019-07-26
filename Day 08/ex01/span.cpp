/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:23:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 19:28:13 by akharrou         ###   ########.fr       */
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

std::vector<int>::iterator	Span::begin() {
	return (_container.begin());
}

std::vector<int>::iterator	Span::end() {
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

	if (_container.size() < _N) {
		_container.push_back(n);
	} else {
		throw Span::MaxCapacityReached();
	}
}

int		Span::shortestSpan() {

	std::vector<int>::iterator iter_min;
	int first_min;
	int second_min;

	iter_min  = std::min_element(_container.begin(), _container.end());
	first_min = *iter_min;
	_container.erase(iter_min);
	second_min = *std::min_element(_container.begin(), _container.end());
	_container.push_back(first_min);

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
