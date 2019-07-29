
#include "../Includes/AMonitorModule.hpp"

/* PRIVATE CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - */

AMonitorModule::AMonitorModule() {}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

AMonitorModule::AMonitorModule( screen_t window ) :
	screen( window ) {
}

AMonitorModule::AMonitorModule( const AMonitorModule & src ) {
	*this = src;
}

AMonitorModule::~AMonitorModule( void ) { }


/* PRIVATE OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - */

AMonitorModule &  AMonitorModule::operator = ( const AMonitorModule & rhs ) {
	(void)rhs;
	return (*this);
}
