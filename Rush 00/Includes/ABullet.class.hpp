

#ifndef ABULLET_CLASS_HPP
# define ABULLET_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Game.hpp"
# include "APawn.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class ABullet :
	public APawn {

	protected:
		ABullet( void );

	public:

		ABullet( std::string type , coord_t location );
		ABullet( const ABullet & src );
		virtual ~ABullet( void );

		ABullet &		operator = ( const ABullet & rhs );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ABULLET_CLASS_HPP */
