
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

CPU_Module::CPU_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "CPU Module";

	size_t len = 100;

	sysctlbyname( "machdep.cpu.core_count",   & CPU_coreCount,   &len, NULL, 0 );
	sysctlbyname( "machdep.cpu.thread_count", & CPU_threadCount, &len, NULL, 0 );
	sysctlbyname( "machdep.cpu.cache.size",   & CPU_cacheSize,   &len, NULL, 0 );

	sysctlbyname("machdep.cpu.brand_string", NULL, &len, NULL, 0);
	CPU_model = new char [len];
	sysctlbyname("machdep.cpu.brand_string", CPU_model, &len, NULL, 0);
}

CPU_Module::~CPU_Module( void ) {
	delete [] CPU_model;
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	CPU_Module::update() {

	system( "top -F -n0 -l1 | grep \"CPU usage\" > " CPU_USAGE_FILENAME );

	CPU_infile.open( CPU_USAGE_FILENAME );
	if (CPU_infile.is_open()) {
		std::getline(CPU_infile, CPU_usage, '\0');
		CPU_infile.close();
	}
}

void	CPU_Module::render() {

	werase ( screen.win );


	std::string title ("|CPU Info|");

	mvwprintw(screen.win,	2,
							2,
						"CPU Model: %s", CPU_model);
	mvwprintw(screen.win,	4,
							2,
						"CPU Core Count: %d", CPU_coreCount);
	mvwprintw(screen.win,	6,
							2,
						"CPU Thread Count: %d", CPU_threadCount);
	mvwprintw(screen.win,	8,
							2,
						"CPU Cache Size: %d", CPU_cacheSize);

	mvwprintw( screen.win, 10, 2, "%s", CPU_usage.c_str() );

	box    ( screen.win , 0 , 0 );
	mvwprintw(screen.win,	0,
						(screen.max.x - screen.min.x - title.length()) / 2,
						"%s", title.c_str());

	wrefresh ( screen.win );
}
