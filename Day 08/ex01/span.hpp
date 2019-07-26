/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:40:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 00:24:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <algorithm>
# include <set>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Span {

	private:

		std::multiset<int, std::less<int>> _container;
		unsigned int _N;

	public:

		class MaxCapacityReached : public std::exception {
				public: virtual const char * what() const throw();
		};

		Span( void );
		Span( unsigned int N );
		Span( const Span & src );
		~Span( void );

		Span &	operator = ( const Span & rhs );

		std::multiset<int>::iterator	begin ();
		std::multiset<int>::iterator	end   ();

		unsigned int	size    () const;
		unsigned int	maxsize () const;

		template < class IterType = std::multiset<int>::iterator >
		void	addNumber( IterType Begin , IterType End );
		void	addNumber( int );

		int	shortestSpan ();
		int	longestSpan  ();

};

template < class IterType >
void	Span::addNumber( IterType Begin , IterType End ) {

	int elemCount = std::distance( Begin , End );

	if (_container.size() + elemCount <= _N) {
		while (Begin != End)
			_container.insert(*Begin++);
	} else {
		throw Span::MaxCapacityReached();
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPAN_HPP */
