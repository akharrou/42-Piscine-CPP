
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Processes_Module::Processes_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "Processes Module";
}

Processes_Module::~Processes_Module( void ) {}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Processes_Module::update() {

	system( "top -F -n0 -l1 | grep \"Processes\" > " PROCESSES_ACTIVITY_FILENAME );

	PROCESSES_infile.open( PROCESSES_ACTIVITY_FILENAME );
	if (PROCESSES_infile.is_open()) {
		std::getline(PROCESSES_infile, PROCESSES_activity, '\0');
		PROCESSES_infile.close();
	}
}

void	Processes_Module::render() {

	werase ( screen.win );


	std::string title ("|Processes Info|");
	box    ( screen.win, 0, 0 );

	mvwprintw(screen.win, 0, (screen.max.x - screen.min.x - title.length()) / 2,
	         "%s", title.c_str()
	);

	mvwprintw( screen.win, 1, 2, PROCESSES_activity.c_str() );

	wrefresh ( screen.win );
}
