/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:40:11 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 19:28:08 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <algorithm>
# include <vector>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Span {

	private:

		unsigned int		_N;
		std::vector<int>	_container;

	public:

		struct MaxCapacityReached : public std::exception {
			virtual const char * what() const throw();
		};

		Span( void );
		Span( unsigned int N );
		Span( const Span & src );
		~Span( void );

		Span &		operator = ( const Span & rhs );

		std::vector<int>::iterator	begin ();
		std::vector<int>::iterator	end   ();

		unsigned int	size    () const;
		unsigned int	maxsize () const;

		void	addNumber( int );

		int	shortestSpan ();
		int	longestSpan  ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPAN_HPP */
