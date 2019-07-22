
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

void AGame::run(void)
{
	while (!m_gameScreenOver)
	{
		getUserInput();
		updateGameState();
		renderGameFrame();
	}
	exit();
}
