/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:00:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 22:59:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>
# include <initializer_list>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                            TEMPLATE DECLARATION                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

template < typename T >
class Array {

	private:
		T		*_array;
		size_t	_size;

	public:

		class BadAccess :
			public std::exception {
				public: virtual const char *what() const throw();
		};

		Array( void );
		Array( unsigned int n );
		Array( std::initializer_list <T> );
		Array( const Array<T> & src );
		~Array( void );

		Array &		operator =  ( const Array & rhs );
		T &			operator [] ( size_t idx );
  		const T &	operator [] ( size_t idx ) const;

		size_t	size() const;

};

template < typename T >
std::ostream &	operator << ( std::ostream & out, const Array<T> & in );


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                          TEMPLATE IMPLEMENTATION                          */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

template < typename T >
Array<T>::Array( void ) :
	_array(nullptr), _size(0) {
}

template < typename T >
Array<T>::Array( unsigned int n ) :
	_array(new T[n]), _size(n) {
	for (size_t i = 0; i < n; ++i)
		_array[i] = 0;
}

template < typename T >
Array<T>::Array( std::initializer_list <T> list ) {

	_array = new T [list.size()];
	_size = list.size();
	std::copy(list.begin(), list.end(), _array);
}

template < typename T >
Array<T>::Array( const Array<T> & src ) :
	_array(new T[src._size]), _size(src._size) {
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

			if (_array != nullptr) {

				delete [] _array;
				_size = 0;
				_array = nullptr;
			}
			_array = new T[rhs._size];
		}
		std::copy(rhs._array, rhs._array + rhs._size, _array);
	}
	return (*this);
}

template < typename T >
T &  Array<T>::operator [] ( size_t idx ) {

	if (idx >= _size) {
		throw BadAccess();
	} else {
		return _array[idx];
	}
}

template < typename T >
const T &  Array<T>::operator [] ( size_t idx ) const {

	if (idx >= _size) {
		throw BadAccess();
	} else {
		return _array[idx];
	}
}

template < typename T >
std::ostream &	operator << ( std::ostream& out, const Array<T> & in ) {

	if (in.size() > 0)
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
const char	*Array<T>::BadAccess::what() const throw() {
	return ("~ Bad Access ~");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ARRAY_HPP */
