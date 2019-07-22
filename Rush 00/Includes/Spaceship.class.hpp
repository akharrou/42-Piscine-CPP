

#ifndef SPACESHIP_CLASS_HPP
# define SPACESHIP_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include "APawn.class.hpp"
# include "RType.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class SpaceShip
	: public APawn {

	private:

		int m_HP;
		int m_MaxHP;

		int m_AP;
		int m_MaxAP;

	public:
		SpaceShip( void );
		SpaceShip( int m_HP, int m_AP );
		SpaceShip(int m_HP, int m_AP, screen_t GameWindow);
		SpaceShip(const SpaceShip &src);
		~SpaceShip( void );

		int		getHP    () const;
		int		getMaxHP () const;
		int		getAP    () const;
		int		getMaxAP () const;

		void	setHP    (int hp);

		// void takeDamage( int amt );
		// void attack( Enemy *enemy );
		// void restoreHP( int amt );
		// void restoreAP( int amt );

		SpaceShip &		operator = ( const SpaceShip & rhs );

		void	update ( state_t & GameState , screen_t GameScreen );

};

std::ostream & operator << ( std::ostream & out, const SpaceShip & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SPACESHIP_CLASS_HPP */
