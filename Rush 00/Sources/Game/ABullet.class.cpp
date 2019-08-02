
#include "../includes/ABullet.class.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

ABullet::ABullet( void ) :
	APawn("ABullet") {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

ABullet::ABullet( std::string type , coord_t location ) :
	APawn( type, location ) {
}

ABullet::ABullet( const ABullet & src ) {
	*this = src;
}

ABullet::~ABullet( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

ABullet &			ABullet::operator = ( const ABullet & rhs ) {

	if (this != &rhs)
		m_location = rhs.m_location;
	return (*this);
}
