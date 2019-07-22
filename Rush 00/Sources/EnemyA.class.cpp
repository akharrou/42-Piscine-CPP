
#include "../Includes/EnemyA.class.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

EnemyA::EnemyA(void) :
    Enemy(100, 10, 10) { }

EnemyA::~EnemyA( void ) { }

EnemyA::EnemyA( const Enemy& src ) {
    *this = src;
}

/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

EnemyA &		EnemyA::operator=( const Enemy& src )
{
    if (this != &src)
    {
        this->setHP(src.getHP());
        this->setAttack(src.getAttack());
        this->setReward(src.getReward());
    }
	return (*this);
}

EnemyA::EnemyA(coord_t location) :
    Enemy( "EnemyA", location ) {

}

void       EnemyA::update( state_t & GameState , screen_t GameScreen )
{
    --m_location.x;
    // if ()

    (void)GameState;
    (void)GameScreen;
}

// ABullet::ABullet( coord_t location ) :
// 	APawn( "ABullet", location ) {
// }

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */
