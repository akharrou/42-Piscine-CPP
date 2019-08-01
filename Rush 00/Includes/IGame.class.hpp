
#ifndef IGAME_CLASS_HPP
# define IGAME_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IGame {

	public:
		virtual void	run             ( void )       = 0;
		virtual void	getUserInput    ( void )       = 0;
		virtual void	updateGameState ( void )       = 0;
		virtual void	renderGameFrame ( void ) const = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* IGAME_CLASS_HPP */
