
#include "../Includes/AGame.class.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AGame::AGame( void ) :
	m_gameScreenOver(false) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AGame::AGame( std::string name ) :
	m_name(name), m_gameScreenOver(false) {
}

AGame::AGame( const AGame & src ) {
	*this = src;
}

AGame::~AGame( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AGame &			AGame::operator = ( const AGame & rhs ) {

	if (this != &rhs) {
        m_name           = rhs.m_name;
        m_gameScreenOver = rhs.m_gameScreenOver;
	}
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AGame::getName() const {
	return (m_name);
}


/* PUBLIC MEMEBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define MAIN_MENU (0)
#define GAME (0)
#define GAMEOVER (0)

void AGame::run(void)
{
	int consoleState = 0;

	while (1) {

		switch (consoleState)
		{
			case MAIN_MENU:
				/* code */
				break;

		default:
			break;
		}
	}


	main_menu();
	while (!m_gameScreenOver)
	{
		getUserInput();
		updateGameState();
		renderGameFrame();
	}
	exit();
}
