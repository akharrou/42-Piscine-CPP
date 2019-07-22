
#ifndef RTYPE_HPP
# define RTYPE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Game.hpp"

# include "AGame.class.hpp"
# include "APawn.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define SPACESHIPS (0)
# define ENEMIES    (1)

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class APawn;
class RType
	: public AGame {

	private:

		screen_t	m_mainScreen;
		screen_t	m_gameScreen;
		screen_t	m_infoScreen;

		state_t		m_GameState;

	public:
		RType( void );
		RType( const RType & src );
		~RType( void );

		RType &		operator = ( const RType & rhs );

		int		initialize      ( void );
		void	exit            ( void ) const;

		void	getUserInput    ( void );
		void	updateGameState ( void );
		void	renderGameFrame ( void ) const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* RTYPE_HPP */


/* TODO :

	- get infoscreen to display : score, lives
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
