/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:40:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/25 20:30:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <deque>
# include <stack>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T, class _Container = std::deque<T> >
class MutantStack {

	private:

		_Container _container;

		typedef _Container	container_type;
		typedef size_t		size_type;
		typedef T			value_type;

		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	public:

		MutantStack( void );
		MutantStack( const MutantStack & src );
		~MutantStack( void );

		MutantStack<T, _Container> &	operator =  ( const MutantStack <T, _Container> & rhs );
		bool	operator == ( const MutantStack <T, _Container> & rhs );
		bool	operator != ( const MutantStack <T, _Container> & rhs );
		bool	operator <  ( const MutantStack <T, _Container> & rhs );
		bool	operator <= ( const MutantStack <T, _Container> & rhs );
		bool	operator >  ( const MutantStack <T, _Container> & rhs );
		bool	operator >= ( const MutantStack <T, _Container> & rhs );

		void push ( const value_type& val );
		void push ( value_type&& val );

		void pop();

		reference & 		top();
		const_reference &	top() const;

		bool empty() const;

		size_type size() const;

		void swap (MutantStack<T,_Container> & x, MutantStack<T,_Container> & y) noexcept(noexcept(x.swap(y)));

};


#include "MutantStack.hpp"


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

template <class T, class _Container>
MutantStack<T, _Container>::MutantStack( void ) {}

template <class T, class _Container>
MutantStack<T, _Container>::MutantStack( const MutantStack & src ) {
	*this = src;
}

template <class T, class _Container>
MutantStack<T, _Container>::~MutantStack( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

template <class T, class _Container>
MutantStack<T, _Container> &	MutantStack<T, _Container>::operator = ( const MutantStack & rhs ) {

	if (this != &rhs) {
		/* IMPLEMENT */
	}
	return (*this);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator == ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator != ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator <  ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator <= ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator >  ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}

template <class T, class _Container>
bool	MutantStack<T, _Container>::operator >= ( const MutantStack <T, _Container> & rhs ) {
	return (true);
}



/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




/* PRIVATE MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - */




/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */



/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MUTANTSTACK_HPP */
