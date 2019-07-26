/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:40:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 21:47:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <algorithm>
# include <unordered_set>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Span {

	private:

		std::unordered_multiset<int> _container;
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

		std::unordered_multiset<int>::iterator	begin ();
		std::unordered_multiset<int>::iterator	end   ();

		unsigned int	size    () const;
		unsigned int	maxsize () const;

		template < class IterType = std::unordered_multiset<int>::iterator >
		void	addNumber( IterType Begin , IterType End );
		void	addNumber( int );

		int	shortestSpan ();
		int	longestSpan  ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPAN_HPP */
