

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "APawn.class.hpp"
# include "../Includes/Spaceship.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Enemy :
    public APawn {

    private:
        int m_HP;
        int m_attack;
        int m_reward;

    public:
        Enemy( void );
        Enemy( int HP, int attack, int reward);
        Enemy( std::string type, coord_t location);
        Enemy( const Enemy& src );
        virtual ~Enemy( void ) = 0;

        Enemy& operator = ( const Enemy& src );

    public:

        int     getHP ( void ) const;
        void    setHP ( int HP );

        int     getAttack ( void ) const;
        void    setAttack ( int attack );

        int     getReward ( void ) const;
        void    setReward ( int reward );

    public:
        void    takeDamage( int amount );
        void    attack( SpaceShip *spaceship );
        void    update( state_t & GameState , screen_t GameScreen );

};

#endif /* ENEMY_CLASS_HPP */
