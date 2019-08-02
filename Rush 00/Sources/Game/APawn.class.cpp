
#include "../Includes/APawn.class.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

APawn::APawn( void ) :
	m_type("n/a") {
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

APawn::APawn( std::string type, int width, int height )
	: m_type(type), m_width(width), m_height(height) { }

APawn::APawn( std::string type , coord_t location ) :
	m_type( type ), m_location(location) {
}

APawn::APawn( std::string type ) :
	m_type( type ) {
}

APawn::APawn( const APawn & src ) {
	*this = src;
}

APawn::~APawn( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

APawn &		APawn::operator = ( const APawn & rhs ) {

	if (this != &rhs) {
		m_type = rhs.m_type;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const APawn & in ) {
	out << "<" << in.getType() << "> APawn";
	return (out);
}


/* ACCESSOR(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

std::string		APawn::getType() const {
	return (m_type);
}

int				APawn::getHeight() const {
	return (m_height);
}

int				APawn::getWidth() const {
	return (m_width);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void		APawn::draw(WINDOW *window) const
{
	for ( int i = 0; m_hitBox[i].symbol; ++i )
	{
		mvwaddch(
			window,
			m_location.y + m_hitBox[i].relativecoord_t.y,
			m_location.x + m_hitBox[i].relativecoord_t.x,
			m_hitBox[i].symbol
		);
	}
}
