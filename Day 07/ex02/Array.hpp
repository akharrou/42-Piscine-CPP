/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 14:28:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                            TEMPLATE DECLARATIONS                          */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
class Array {

	private:
		T		*_array;
		size_t	_size;

	public:

		class OutOfBounds :
			public std::exception {
				public: virtual const char *what() const throw();
		};

		Array( void );
		Array( unsigned int n );
		Array( const Array & src );
		~Array( void );

		Array &			operator =  ( const Array & rhs );
		Array &			operator [] ( size_t idx );
  		const Array &	operator [] ( size_t idx ) const;

		size_t	size() const;

};

template < typename T >
std::ostream &	operator << ( std::ostream & out, const Array<T> & in );


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                          TEMPLATE IMPLEMENTATIONS                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

template < typename T >
Array<T>::Array( void ) :
	_array(NULL), _size(0) {
}

template < typename T >
Array<T>::Array( unsigned int n ) :
	_array(new T[n]), _size(n) {
}

template < typename T >
Array<T>::Array( const Array & src ) {
	*this = src;
}

template < typename T >
Array<T>::~Array( void ) {
	if (_array != NULL)
		delete [] (_array);
}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
Array<T> &  Array<T>::operator = ( const Array<T> & rhs ) {

	if (this != &rhs) {

		if (_size != rhs._size) {
			delete [] _array;
			_size = 0;
			_array = nullptr;
			_array = new T[rhs._size];
		}
		std::copy(_array, _array + rhs._size, rhs._array);
	}
	return (*this);
}

template < typename T >
Array<T> &  Array<T>::operator [] ( size_t idx ) {

	if (idx >= _size) {
		throw std::exception();
	} else {
		return _array[idx];
	}
}

template < typename T >
const Array<T> &  Array<T>::operator [] ( size_t idx ) const {

	if (idx >= _size) {
		throw OutOfBounds();
	} else {
		return _array[idx];
	}
}

template < typename T >
std::ostream &	operator << ( std::ostream& out, const Array<T> & in ) {

	for ( size_t i = 0; i < in.size(); ++i )
		out << in[i] << "\n";
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
size_t	Array<T>::size() const {
	return (_size);
}

/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
const char	*Array<T>::OutOfBounds::what() const throw() {
	return ("~ Out of Bounds Access ~");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ARRAY_HPP */
