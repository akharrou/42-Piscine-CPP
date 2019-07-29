
#include "../Includes/AMonitorDisplay.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AMonitorDisplay::AMonitorDisplay( void ) {}

AMonitorDisplay::AMonitorDisplay( const AMonitorDisplay & src ) {
	*this = src;
}

AMonitorDisplay::~AMonitorDisplay () {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

AMonitorDisplay &  AMonitorDisplay::operator = ( const AMonitorDisplay & rhs ) {
	(void)rhs;
	return (*this);
}
