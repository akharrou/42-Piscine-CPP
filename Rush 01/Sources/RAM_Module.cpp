
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RAM_Module::RAM_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "RAM Module";
}

RAM_Module::~RAM_Module( void ) {}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	RAM_Module::update() {

	system( "top -F -n0 -l1 | grep \"PhysMem\" > " RAM_USAGE_FILENAME );

	RAM_infile.open( RAM_USAGE_FILENAME );
	if (RAM_infile.is_open()) {
		std::getline(RAM_infile, RAM_usage, '\0');
		RAM_infile.close();
	}

	/* Parse it here */
}

void	RAM_Module::render() {

	werase ( screen.win );

	std::string title ("|RAM Info|");
	box    ( screen.win, 0, 0 );

	mvwprintw(screen.win,	2,
							2,
						"%s", RAM_usage.c_str());

	mvwprintw(screen.win,	0,
						(screen.max.x - screen.min.x - title.length()) / 2,
						"%s", title.c_str());

	wrefresh ( screen.win );
}
