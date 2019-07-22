
#include "../Includes/Spaceship.class.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

SpaceShip::SpaceShip( void ) :
	APawn("SpaceShip", 16, 7), m_HP(3), m_MaxHP(3), m_AP(100), m_MaxAP(100) {


    /* SpaceShip

               \\++
                \\++
             >>|||||||\
             >>>||||||||>
             >>|||||||/
                //++
               //++
    */

	hitBoxUnit_t hitBox[] = {

		{{ 2, 0 }, '\\'}, {{ 3, 0 }, '\\'}, {{ 4, 0 }, '+'}, {{ 5, 0 }, '+'},
		{{ 3, 1 }, '\\'}, {{ 4, 1 }, '\\'}, {{ 5, 1 }, '+'}, {{ 6, 1 }, '+'},
		{{ 0, 2 }, '>'}, {{ 1, 2 }, '>'}, {{ 2, 2 }, '|'}, {{ 3, 2 }, '|'}, {{ 4, 2 }, '|'}, {{ 5, 2 }, '|'}, {{ 6, 2 }, '|'}, {{ 7, 2 }, '|'}, {{ 8, 2 }, '|'}, {{ 9, 2 }, '\\'},
		{{ 0, 3 }, '>'}, {{ 1, 3 }, '>'}, {{ 2, 3 }, '>'}, {{ 3, 3 }, '|'}, {{ 4, 3 }, '|'}, {{ 5, 3 }, '|'}, {{ 6, 3 }, '|'}, {{ 7, 3 }, '|'}, {{ 8, 3 }, '|'}, {{ 9, 3 }, '|'}, {{ 10, 3 }, '|'}, {{ 11, 3 }, '>'},
		{{ 0, 4 }, '>'}, {{ 1, 4 }, '>'}, {{ 2, 4 }, '|'}, {{ 3, 4 }, '|'}, {{ 4, 4 }, '|'}, {{ 5, 4 }, '|'}, {{ 6, 4 }, '|'}, {{ 7, 4 }, '|'}, {{ 8, 4 }, '|'}, {{ 9, 4 }, '/'},
		{{ 4, 5 }, '/'}, {{ 5, 5 }, '/'}, {{ 6, 5 }, '+'}, {{ 7, 5 }, '+'},
		{{ 3, 6 }, '/'}, {{ 4, 6 }, '/'}, {{ 5, 6 }, '+'}, {{ 6, 6 }, '+'},

		{ {-1, -1}, 0 }
	};

	m_hitBox = new hitBoxUnit_t [49];

	int i = 0;
	for (auto unit : hitBox)
		m_hitBox[i++] = unit;

	m_location = { 1, 1 };
}

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

SpaceShip::SpaceShip( int m_HP, int m_AP ) :
	m_HP(m_HP),  m_MaxHP(m_HP), m_AP(m_AP), m_MaxAP(m_AP) {


    /* SpaceShip

               \\++
                \\++
             >>|||||||\
             >>>||||||||>
             >>|||||||/
                 //++
                //++
    */

	hitBoxUnit_t hitBox[] = {

		{{ 2, 0 }, '\\'}, {{ 3, 0 }, '\\'}, {{ 4, 0 }, '+'}, {{ 5, 0 }, '+'},
		{{ 3, 1 }, '\\'}, {{ 4, 1 }, '\\'}, {{ 5, 1 }, '+'}, {{ 6, 1 }, '+'},
		{{ 0, 2 }, '>'}, {{ 1, 2 }, '>'}, {{ 2, 2 }, '|'}, {{ 3, 2 }, '|'}, {{ 4, 2 }, '|'}, {{ 5, 2 }, '|'}, {{ 6, 2 }, '|'}, {{ 7, 2 }, '|'}, {{ 8, 2 }, '|'}, {{ 9, 2 }, '\\'},
		{{ 0, 3 }, '>'}, {{ 1, 3 }, '>'}, {{ 2, 3 }, '>'}, {{ 3, 3 }, '|'}, {{ 4, 3 }, '|'}, {{ 5, 3 }, '|'}, {{ 6, 3 }, '|'}, {{ 7, 3 }, '|'}, {{ 8, 3 }, '|'}, {{ 9, 3 }, '|'}, {{ 10, 3 }, '|'}, {{ 11, 3 }, '>'},
		{{ 0, 4 }, '>'}, {{ 1, 4 }, '>'}, {{ 2, 4 }, '|'}, {{ 3, 4 }, '|'}, {{ 4, 4 }, '|'}, {{ 5, 4 }, '|'}, {{ 6, 4 }, '|'}, {{ 7, 4 }, '|'}, {{ 8, 4 }, '|'}, {{ 9, 4 }, '/'},
		{{ 4, 5 }, '/'}, {{ 5, 5 }, '/'}, {{ 6, 5 }, '+'}, {{ 7, 5 }, '+'},
		{{ 3, 6 }, '/'}, {{ 4, 6 }, '/'}, {{ 5, 6 }, '+'}, {{ 6, 6 }, '+'},

		{ {-1, -1}, 0 }
	};

	m_hitBox = new hitBoxUnit_t [49];

	int i = 0;
	for (auto unit : hitBox)
		m_hitBox[i++] = unit;

	m_location = { 1, 1 };
}

SpaceShip::SpaceShip( int m_HP, int m_AP, screen_t GameWindow ) :
	m_HP(m_HP),  m_MaxHP(m_HP), m_AP(m_AP), m_MaxAP(m_AP) {


    /* SpaceShip

               \\++
                \\++
             >>|||||||\
             >>>||||||||>
             >>|||||||/
                 //++
                //++
    */

	hitBoxUnit_t hitBox[] = {

		{{ 2, 0 }, '\\'}, {{ 3, 0 }, '\\'}, {{ 4, 0 }, '+'}, {{ 5, 0 }, '+'},
		{{ 3, 1 }, '\\'}, {{ 4, 1 }, '\\'}, {{ 5, 1 }, '+'}, {{ 6, 1 }, '+'},
		{{ 0, 2 }, '>'}, {{ 1, 2 }, '>'}, {{ 2, 2 }, '|'}, {{ 3, 2 }, '|'}, {{ 4, 2 }, '|'}, {{ 5, 2 }, '|'}, {{ 6, 2 }, '|'}, {{ 7, 2 }, '|'}, {{ 8, 2 }, '|'}, {{ 9, 2 }, '\\'},
		{{ 0, 3 }, '>'}, {{ 1, 3 }, '>'}, {{ 2, 3 }, '>'}, {{ 3, 3 }, '|'}, {{ 4, 3 }, '|'}, {{ 5, 3 }, '|'}, {{ 6, 3 }, '|'}, {{ 7, 3 }, '|'}, {{ 8, 3 }, '|'}, {{ 9, 3 }, '|'}, {{ 10, 3 }, '|'}, {{ 11, 3 }, '>'},
		{{ 0, 4 }, '>'}, {{ 1, 4 }, '>'}, {{ 2, 4 }, '|'}, {{ 3, 4 }, '|'}, {{ 4, 4 }, '|'}, {{ 5, 4 }, '|'}, {{ 6, 4 }, '|'}, {{ 7, 4 }, '|'}, {{ 8, 4 }, '|'}, {{ 9, 4 }, '/'},
		{{ 4, 5 }, '/'}, {{ 5, 5 }, '/'}, {{ 6, 5 }, '+'}, {{ 7, 5 }, '+'},
		{{ 3, 6 }, '/'}, {{ 4, 6 }, '/'}, {{ 5, 6 }, '+'}, {{ 6, 6 }, '+'},

		{ {-1, -1}, 0 }
	};

	m_hitBox = new hitBoxUnit_t [49];

	int i = 0;
	for (auto unit : hitBox)
		m_hitBox[i++] = unit;

	m_location = { (int_fast16_t)(GameWindow.bottom.x + 1) , (int_fast16_t)(GameWindow.bottom.y * 0.5) };
}

SpaceShip::SpaceShip( const SpaceShip & src ) {
	*this = src;
}

SpaceShip::~SpaceShip( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

SpaceShip &			SpaceShip::operator = ( const SpaceShip & rhs ) {

	if (this != &rhs) {
		m_HP = rhs.m_HP;
		m_AP = rhs.m_AP;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const SpaceShip & in ) {

	out << "<" << in.getType() << ">" << " : " << in.getHP() << "/" << in.getMaxHP();
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int		SpaceShip::getHP    () const {
	return (m_HP);
}

int		SpaceShip::getMaxHP () const {
	return (m_MaxHP);
}

int		SpaceShip::getAP    () const {
	return (m_AP);
}

int		SpaceShip::getMaxAP () const {
	return (m_MaxAP);
}

void    SpaceShip::setHP    (int hp) {
	this->m_HP = hp;
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	SpaceShip::update( state_t & GameSate, screen_t GameWindow )
{
	switch ( GameSate.UserInput.character )
	{
		case KEY_UP:
		case 'w':
			if (m_location.y - 1 >= GameWindow.top.y)
				m_location.y -= 1;
			break;

		case KEY_DOWN:
		case 's':
			if (m_location.y + 1 <= (GameWindow.bottom.y - this->getHeight()))
				m_location.y += 1;
			break;

		case KEY_LEFT:
		case 'a':
			if (m_location.x - 1 >= GameWindow.top.x - 2)
				m_location.x -= 1;
			break;

		case KEY_RIGHT:
		case 'd':
			if (m_location.x + 1 <= (GameWindow.bottom.x - this->getWidth()))
				m_location.x += 1;
			break;

		case ' ':
			// shoot();
			break;

		default:
			break;
	}
	(void)GameWindow;
}
