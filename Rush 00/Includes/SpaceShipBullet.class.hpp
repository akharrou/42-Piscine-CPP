

#ifndef SPACESHIPBULLT_CLASS_HPP
# define SPACESHIPBULLT_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include "ABullet.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class SpaceShipBullet :
	public ABullet {

	protected:
		SpaceShipBullet( void );

	public:

		SpaceShipBullet( coord_t location );
		SpaceShipBullet( const SpaceShipBullet & src );
		~SpaceShipBullet( void );

		SpaceShipBullet &		operator = ( const SpaceShipBullet & rhs );

		colliding
		void	update ( state_t & , screen_t );

};
#include "SpaceShipBullet.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

SpaceShipBullet::SpaceShipBullet( void ) { }


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

SpaceShipBullet::SpaceShipBullet( coord_t location ) :
	ABullet( "SpaceShipBullet" , location ) {
}

SpaceShipBullet::SpaceShipBullet( const SpaceShipBullet & src ) {
	*this = src;
}

SpaceShipBullet::~SpaceShipBullet( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

SpaceShipBullet &			SpaceShipBullet::operator = ( const SpaceShipBullet & rhs ) {

	if (this != &rhs) {
		m_location = rhs.m_location;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	SpaceShipBullet::update ( state_t & GameState , screen_t GameWindow ) {


	if (colliding()) {

		/* delete itself */
			/* do 1 dmg to enemy */
		if (not out of bounds)
			/* increase score */
	} else {
		m_location.x += 1;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPACESHIPBULLT_CLASS_HPP */
