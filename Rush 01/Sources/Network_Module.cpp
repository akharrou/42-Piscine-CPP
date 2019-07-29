
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Network_Module::Network_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "Network Module";
}

Network_Module::~Network_Module( void ) {}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Network_Module::update() {

	system( "top -F -n0 -l1 | grep \"Network\" > " NETWORK_ACTIVITY_FILENAME );

	NETWORK_infile.open( NETWORK_ACTIVITY_FILENAME );
	if (NETWORK_infile.is_open()) {
		std::getline(NETWORK_infile, NETWORK_activity, '\0');
		NETWORK_infile.close();
	}
}

void	Network_Module::render() {

	werase ( screen.win );

	std::string title ("|Network Info|");

	mvwprintw(screen.win, 2, 2,
	         "%s", NETWORK_activity.c_str());

	box    ( screen.win, 0, 0 );

	mvwprintw(screen.win, 0, (screen.max.x - screen.min.x - title.length()) / 2,
	          "%s", title.c_str()
	);

	wrefresh ( screen.win );
}
