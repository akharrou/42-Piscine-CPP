
#ifndef RTYPE_HPP
# define RTYPE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <unistd.h>
# include <ncurses.h>

# include <iostream>
# include <cstdint>
# include <string>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AGame.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class RType
	: public AGame {

	private:

		typedef struct s_int_coordinate{
			int_fast8_t x;
			int_fast8_t y;
		} coord;

		typedef struct {
			coord	relativeCoord;
			int		symbol;
		} hitBoxUnit_t;

		class Pawn {

			private:
				std::string	m_type;

			protected:
				hitBoxUnit_t *hitBox;
				coord m_location;

			public:
				/*  */

		};

		APawn	**pawns;
		int 	ticks;
		WINDOW *game_area;
		WINDOW *info_area;

	public:
		RType( void );
		RType( const RType & src );
		~RType( void );

		RType &		operator = ( const RType & rhs );

		void	initializeGame  ( void );
		void	exitGame        ( void ) const;

		void	getUserInput    ( void );
		void	updateGameState ( void );
		void	renderGameFrame ( void ) const;

};

#include "RType.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RType::RType( void ) :
	AGame("RType") {
}

RType::RType( const RType & src ) {
	*this = src;
}

RType::~RType( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RType &			RType::operator = ( const RType & rhs ) {
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	RType::initializeGame  ( void ) {

}

void	RType::exitGame        ( void ) const {

}

void	RType::updateGameState ( void ) {

}

void	RType::renderGameFrame ( void ) const {

}

void	RType::getUserInput    ( void )
{

}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* RTYPE_HPP */


/* TODO :

	- set up multiple windows & their spacing
	- implement pawn class
	- get infoscreen to display : score, lives, time played
	- place player on the right window and get him to move
	- get the spaceship to shoot
	- implement enemy class
	- implement different enemy classes
	- implement collision with border
	- implement distant star background







/// IDEA OF LEVELS

typedef struct {
	void	(*level)();
} level_t;

level_t levels[] = {
	&level_1;
	&level_2;
	&level_3;
	&level_4;
	&level_5;
	&level_6;
}

*/
