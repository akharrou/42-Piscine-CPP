

#include "../Includes/Enemy.class.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Enemy::Enemy(void) : APawn("Enemy", 20, 20), m_HP(100), m_attack(1), m_reward(50) {

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

    m_location = { 40, 40 };
}

Enemy::Enemy(int HP, int attack, int reward) :
    m_HP(HP), m_attack(attack), m_reward(reward) {

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

    m_location = { 20, 20 };
}

Enemy::Enemy( std::string type, coord_t location)
    : APawn( type, location ) {
}

Enemy::Enemy(const Enemy& src)
{
    *this = src;
}

Enemy::~Enemy(void) {}

/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Enemy& Enemy::operator = (const Enemy& src)
{
    if (this != &src)
    {
        this->m_HP = src.m_HP;
        this->m_attack = src.m_HP;
    }
    return *this;
}

/* PRIVATE MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

int     Enemy::getHP(void) const
{
    return this->m_HP;
}

void    Enemy::setHP(int HP)
{
    this->m_HP = HP;
}

int     Enemy::getAttack(void) const
{
    return this->m_attack;
}

void    Enemy::setAttack(int attack)
{
    this->m_attack = attack;
}

int     Enemy::getReward(void) const
{
    return this->m_reward;
}

void    Enemy::setReward(int reward)
{
    this->m_reward = reward;
}

void    Enemy::takeDamage( int amt )
{
    if (amt > this->m_HP)
    {
        this->m_HP = 0;
    }
    else
    {
        this->m_HP -= amt;
    }
}

void    Enemy::attack( SpaceShip *spaceship )
{
    if (this->m_attack > spaceship->getHP())
    {
        spaceship->setHP(0);
    }
    else
    {
        spaceship->setHP(spaceship->getHP() - this->m_attack);
    }
}

void    Enemy::update( state_t & GameState, screen_t GameScreen )
{
    // Need to update x by -1.
    this->m_location.x -= 1;
    if (this->m_location.x <= 0)
    {
        // Delete from list.
    }

    (void)GameState;
    (void)GameScreen;
}
