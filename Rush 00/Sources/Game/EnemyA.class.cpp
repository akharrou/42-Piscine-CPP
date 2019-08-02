
#include "../Includes/EnemyA.class.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

EnemyA::EnemyA(void) : Enemy() {
    /*

    012345/<
    <|||\/|<
    01<|||<<
    <|||/\|<
    012345\<
    */

    hitBoxUnit_t hitBox[] = {
        {{ 6, 0 }, '/'}, {{ 7, 0 }, '<'},
        {{ 0, 1 }, '<'}, {{ 1, 1 }, '|'}, {{ 2, 1 }, '|'}, {{ 3, 1 }, '|'}, {{ 4, 1 }, '\\'}, {{ 5, 1 }, '/'}, {{ 6, 1 }, '|'}, {{ 7, 1 }, '<'},
        {{ 2, 2 }, '<'}, {{ 3, 2 }, '|'}, {{ 4, 2 }, '|'}, {{ 5, 2 }, '|'}, {{ 6, 2 }, '<'}, {{ 7, 2 }, '<'},
        {{ 0, 3 }, '<'}, {{ 1, 3 }, '|'}, {{ 2, 3 }, '|'}, {{ 3, 3 }, '|'}, {{ 4, 3 }, '/'}, {{ 5, 3 }, '\\'}, {{ 6, 3 }, '|'}, {{ 7, 3 }, '<'},
        {{ 6, 4 }, '\\'}, {{ 7, 4 }, '<'},

        { {-1, -1}, 0 }
    };

    m_hitBox = new hitBoxUnit_t [27];

    int i = 0;
    for (auto unit : hitBox)
		m_hitBox[i++] = unit;

   m_location.x = 70;
   m_location.y = 30;
}

EnemyA::~EnemyA( void ) { }

EnemyA::EnemyA( const Enemy& src ) { *this = src; }

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

void        EnemyA::update( state_t & GameState , screen_t GameScreen )
{
    if (GameState.tick % 40 == 0)
        --m_location.x;
    // if ()

    (void)GameState;
    (void)GameScreen;
}

// ABullet::ABullet( coord_t location ) :
// 	APawn( "ABullet", location ) {
// }

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */
