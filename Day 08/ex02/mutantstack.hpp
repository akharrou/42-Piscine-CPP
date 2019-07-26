/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:40:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 11:35:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <stack>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                            TEMPLATE DECLARATION                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
class MutantStack :
	public std::stack< T, std::deque<T> > {

	public:
		typedef typename std::deque<T>::iterator iterator;

		/* std::stacks are implemented under the hood with
		a certain container (in this case we insured that
		it will be implemented with a std::deque<T>).

		This container is a 'protected' member to the
		std::stack instance, under the identifier 'c'.

		See '/Library/Developer/CommandLineTools/usr/include/c++/v1/stack'
		@line 31.

		So we'll just be accessing it; and here we are just
		giving a slightly more readable name */

#		define container c

		iterator	begin ();
		iterator	end   ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                          TEMPLATE IMPLEMENTATION                          */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
typename MutantStack< T >::iterator		MutantStack< T >::begin ()
{
	return ( this->container.begin() );
}

template < typename T >
typename MutantStack< T >::iterator		MutantStack< T >::end   ()
{
	return ( this->container.end() );
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MUTANTSTACK_HPP */
