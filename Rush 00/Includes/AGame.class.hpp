
#ifndef AGAME_CLASS_HPP
# define AGAME_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AGame {

	private:
		std::string	m_name;

	protected:
		AGame( void );
		bool		m_gameScreenOver;

	public:
		AGame( std::string name );
		AGame( const AGame & src );
		virtual ~AGame( void );

		AGame &		operator = ( const AGame & rhs );

		std::string		getName() const;

		void			run         ( void );

		virtual int		initialize  ( void )           = 0;
		virtual void	exit        ( void ) const     = 0;

		virtual void	getUserInput    ( void )       = 0;
		virtual void	updateGameState ( void )       = 0;
		virtual void	renderGameFrame ( void ) const = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AGAME_CLASS_HPP */
