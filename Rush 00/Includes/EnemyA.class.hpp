

#ifndef ENEMYA_CLASS_HPP
# define ENEMYA_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "../Includes/Enemy.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class EnemyA :
    public Enemy {

    public:
        EnemyA( void );
        EnemyA( coord_t location);
        ~EnemyA( void );
        EnemyA( const Enemy& src );

        EnemyA & operator = ( const Enemy & src );

        void    update( state_t & GameState , screen_t GameScreen );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ENEMYA_CLASS_HPP */
