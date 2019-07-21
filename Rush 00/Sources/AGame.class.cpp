
#include "../Includes/AGame.class.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AGame::AGame( void ) :
	m_GameOver(false) {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AGame::AGame( std::string name ) :
	m_name(name), m_GameOver(false) {
}

AGame::AGame( const AGame & src ) {
	*this = src;
}

AGame::~AGame( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AGame &			AGame::operator = ( const AGame & rhs ) {

	if (this != &rhs) {
        m_name     = rhs.m_name;
        m_GameOver = rhs.m_GameOver;
        m_input    = rhs.m_input;
        m_state    = rhs.m_state;
	}
	return (*this);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - */

std::string		AGame::getName() const {
	return (m_name);
}


/* PUBLIC MEMEBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

void AGame::runGame(void)
{
	while (!m_GameOver)
	{
		getUserInput();
		updateGameState();
		renderGameFrame();
	}
	exitGame();
}
