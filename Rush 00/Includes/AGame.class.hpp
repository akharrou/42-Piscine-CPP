
#ifndef AGAME_CLASS_HPP
# define AGAME_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct IUserInput { };
struct IGameState { };

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AGame {

	private:
		AGame( void );
		std::string	m_name;

	protected:
		bool		m_GameOver;
		IUserInput	m_input;
		IGameState	m_state;

	public:
		AGame( std::string name );
		AGame( const AGame & src );
		virtual ~AGame( void );

		AGame &		operator = ( const AGame & rhs );

		std::string		getName() const;

		void			runGame         ( void );

		virtual void	initializeGame  ( void )       = 0;
		virtual void	exitGame        ( void ) const = 0;

		virtual void	getUserInput    ( void )       = 0;
		virtual void	updateGameState ( void )       = 0;
		virtual void	renderGameFrame ( void ) const = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AGAME_CLASS_HPP */
