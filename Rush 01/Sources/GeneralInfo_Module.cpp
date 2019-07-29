
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GeneralInfo_Module::GeneralInfo_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "GeneralInfo Module";

	struct utsname uts;

	uname(&uts);

    Username   = getenv("USER");
    Hostname   = getenv("HOSTNAME");
    OS_Name    = uts.sysname;
    OS_Release = uts.release;
    Platform   = uts.machine;
}

GeneralInfo_Module::~GeneralInfo_Module( void ) {}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	GeneralInfo_Module::update() {

	Datetime = std::ctime(
					&(timestr =
						std::chrono::system_clock::to_time_t(
							std::chrono::system_clock::now()
						)
					)
				);
}

void	GeneralInfo_Module::render() {

    werase ( screen.win );

	std::string title ("|General Info|");

	mvwprintw(screen.win,	2,
							(screen.max.x - screen.min.x - Datetime.length()) / 2,
						"%s", Datetime.c_str());
	mvwprintw(screen.win,	4,
							2,
						"Username: %s", Username.c_str());
	mvwprintw(screen.win,	6,
							2,
						"Hostname: %s", Hostname.c_str());
	mvwprintw(screen.win,	8,
							2,
						"OS Name: %s", OS_Name.c_str());
	mvwprintw(screen.win,	10,
							2,
						"OS Release: %s", OS_Release.c_str());
	mvwprintw(screen.win,	12,
							2,
						"Platform: %s", Platform.c_str());

	box    ( screen.win, 0, 0 );

	mvwprintw(screen.win,	0,
						(screen.max.x - screen.min.x - title.length()) / 2,
						"%s", title.c_str());

    wrefresh ( screen.win );
}
