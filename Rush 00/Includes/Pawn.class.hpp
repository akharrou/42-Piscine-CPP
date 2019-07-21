


#ifndef PAWN_HPP
# define PAWN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Pawn {

	private:
		std::string	m_type;

	protected:
		int_fast16_t

	public:

		Pawn( void );
		Pawn( /* regular */ );
		Pawn( const Pawn & src );
		~Pawn( void );

		std::string		toString();
		Pawn &		operator = ( const Pawn & rhs );

};

std::ostream & operator << ( std::ostream & out, const Pawn & in );


#include "Pawn.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */



/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Pawn::Pawn( void ) :
	/* attribs. */ {
}

Pawn::Pawn( /* regular */ ) :
	/* attribs. */ {
}

Pawn::Pawn( const Pawn & src ) {
	*this = src;
}

Pawn::~Pawn( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Pawn &			Pawn::operator = ( const Pawn & rhs ) {

	if (this != &rhs) {
		/* IMPLEMENT */
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Pawn & in ) {

	out << /* IMPLEMENT */;
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */




/* PRIVATE MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - */




/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* PAWN_HPP */
