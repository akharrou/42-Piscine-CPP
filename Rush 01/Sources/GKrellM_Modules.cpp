/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Modules.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:01:44 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 14:01:09 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                        GENERAL INFORMATION MODULE                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GeneralInfo_Module::GeneralInfo_Module( void ) {

	name = "GeneralInfo Module";

	struct utsname uts;

	uname(&uts);

    Username   = getenv("USER");
    Hostname   = getenv("HOSTNAME");
    OS_Name    = uts.sysname;
    OS_Release = uts.release;
    Platform   = uts.machine;
}

GeneralInfo_Module::GeneralInfo_Module( const GeneralInfo_Module & src ) {
	*this = src;
}

GeneralInfo_Module::~GeneralInfo_Module( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

GeneralInfo_Module &	GeneralInfo_Module::operator = ( const GeneralInfo_Module & rhs ) {
	(void)rhs;
	return (*this);
}


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

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* GENERAL INFORMATION */\n\n";

	std::cout << Datetime    << "\n\n";
	std::cout << Username    << "\n";
	std::cout << Hostname    << "\n";
	std::cout << OS_Name     << "\n";
	std::cout << OS_Release  << "\n";
	std::cout << Platform    << "\n";
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                                CPU MODULE                                 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

CPU_Module::CPU_Module( void ) {

	name = "CPU Module";

	size_t len = 256;

	sysctlbyname( "machdep.cpu.core_count",   & CPU_coreCount,   &len, NULL, 0 );
	sysctlbyname( "machdep.cpu.thread_count", & CPU_threadCount, &len, NULL, 0 );
	sysctlbyname( "machdep.cpu.cache.size",   & CPU_cacheSize,   &len, NULL, 0 );
	sysctlbyname( "machdep.cpu.brand_string",   CPU_model,       &len, NULL, 0 );
}

CPU_Module::CPU_Module( const CPU_Module & src ) {
	*this = src;
}

CPU_Module::~CPU_Module( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

CPU_Module &	CPU_Module::operator = ( const CPU_Module & rhs ) {
	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	CPU_Module::update() {

	system( "top -F -n0 -l1 | grep \"CPU usage\" > " CPU_USAGE_FILENAME );

	CPU_infile.open( CPU_USAGE_FILENAME );
	if (CPU_infile.is_open()) {
		std::getline(CPU_infile, CPU_usage, '\0');
		CPU_infile.close();
	}

	/* Parse it here */
}

void	CPU_Module::render() {

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* CPU INFORMATION */\n\n";

	std::cout << "CPU Model : "         << CPU_model               << "\n";
	std::cout << "CPU Core Count : "    << CPU_coreCount           << "\n";
	std::cout << "CPU Thread Count : "  << CPU_threadCount         << "\n";
	std::cout << "CPU Cache Size : "    << CPU_cacheSize << "KB"   << "\n\n";

	std::cout << "CPU Usage : "         << CPU_usage               << "\n";
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                                RAM MODULE                                 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RAM_Module::RAM_Module( void ) {
	name = "RAM Module";
}

RAM_Module::RAM_Module( const RAM_Module & src ) {
	*this = src;
}

RAM_Module::~RAM_Module( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RAM_Module &	RAM_Module::operator = ( const RAM_Module & rhs ) {
	(void)rhs;
	return (*this);
}


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

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* RAM MEMORY INFORMATION */\n\n";

	std::cout << "RAM Usage : " << RAM_usage << "\n";

}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                              NETWORK MODULE                               */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Network_Module::Network_Module( void ) {
	name = "Network Module";
}

Network_Module::Network_Module( const Network_Module & src ) {
	*this = src;
}

Network_Module::~Network_Module( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Network_Module &	Network_Module::operator = ( const Network_Module & rhs ) {
	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Network_Module::update() {

	system( "top -F -n0 -l1 | grep \"Network\" > " NETWORK_ACTIVITY_FILENAME );

	NETWORK_infile.open( NETWORK_ACTIVITY_FILENAME );
	if (NETWORK_infile.is_open()) {
		std::getline(NETWORK_infile, NETWORK_activity, '\0');
		NETWORK_infile.close();
	}

	/* Parse it here */
}

void	Network_Module::render() {

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* NETWORK ACTIVITY INFORMATION */\n\n";

	std::cout << "NETWORK Activity : " << NETWORK_activity << "\n";

}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                             PROCESSES MODULE                              */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Processes_Module::Processes_Module( void ) {
	name = "Processes Module";
}

Processes_Module::Processes_Module( const Processes_Module & src ) {
	*this = src;
}

Processes_Module::~Processes_Module( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Processes_Module &	Processes_Module::operator = ( const Processes_Module & rhs ) {
	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Processes_Module::update() {

	system( "top -F -n0 -l1 | grep \"Network\" > " PROCESSES_ACTIVITY_FILENAME );

	PROCESSES_infile.open( PROCESSES_ACTIVITY_FILENAME );
	if (PROCESSES_infile.is_open()) {
		std::getline(PROCESSES_infile, PROCESSES_activity, '\0');
		PROCESSES_infile.close();
	}

	/* Parse it here */
}

void	Processes_Module::render() {

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* PROCESSES ACTIVITY INFORMATION */\n\n";

	std::cout << "PROCESSES Activity : " << PROCESSES_activity << "\n";

}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                               ZAZ'S MODULE                                */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

Zaz_Module &	Zaz_Module::operator = ( const Zaz_Module & rhs ) {
	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Zaz_Module::update() {

	static int state = 0;

	unicorn = unicornFrame[state++ % 5];

	if (state == INT_MAX)
		state = 2;
}

void	Zaz_Module::render() {

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* ZAZ'S FAVORITE ANIMAL */\n\n";

	std::cout << unicorn << "\n";
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Zaz_Module::~Zaz_Module( void ) {}

Zaz_Module::Zaz_Module( const Zaz_Module & src ) {
	*this = src;
}

Zaz_Module::Zaz_Module( void ) {
	name = "Zaz Module";

	unicornFrame[0] =
		"        /'\n"
		"       //\n"
		"   .  //\n"
		"   |\\//7\n"
		"  /' \" \\\n"
		" .   . .\n"
		" | (    \\     '._\n"
		" |  '._  '    '. '\n"
		" /    \\'-'_---. ) )\n"
		".              :.'\n"
		"|               \\\n"
		"| .    .   .     .\n"
		"' .    |  |      |\n"
		" \\^   /_-':     /\n"
		" / | |    '\\  .'\n"
		"/ /| |     \\\\  |\n"
		"\\ \\( )     // /\n"
		" \\ | |    // /\n"
		"  L! !   // /\n"
		"   [_]  L[_|\n";

	unicornFrame[1] =
        "                                /"
        "                      __       //"
        "                      -\\~,\\=\\ //"
        "                    --=_\\=---//="
        "                  -_ =/  \\/ //\\/"
        "                  _,~/   |_   _|\\,"
        "     __          ,/_/    \\' | `/_"
        "    //\\\\          /       | | |\\_"
        "   /(\\ _\\________/        (,_,)`"
        "  J(\\_/                       \\"
        " ,)\\/     v                \\   |"
        " / Y      (         Y       | /J"
        "(7 |       \\        |       '/ \\"
        "'| (       /\\_______\\_     _Y_  \\"
        " 'Y \\     / \\     7   \\   /   \\  \\"
        " ',) (   /   )   /    |  /    (  )"
        "   '~(  )   / __/     i J     / /"
        "     \\  /   \\ \\       | |   _/ /"
        "     | |     )_\\_     )_\\_/__\\/"
        "     /_\\     |___\\    |___\\"
        "    (___)";

	unicornFrame[2] =
        "                   /"
        "                   __       //"
        "                   -\\= \\=\\ //"
        "                 --=_\\=---//=--"
        "               -_==/  \\/ //\\/--"
        "                ==/   /O   O\\==--"
        "   _ _ _ _     /_/    \\  ]  /--"
        "  /\\ ( (- \\    /       ] ] ]==-"
        " (\\ _\\_\\_\\-\\__/     \\  (,_,)--"
        "(\\_/                 \\     \\-"
        "\\/      /       (   ( \\  ] /)"
        "/      (         \\   \\_ \\./ )"
        "(       \\         \\      )  \\"
        "(       /\\_ _ _ _ /---/ /\\_  \\"
        " \\     / \\     / ____/ /   \\  \\"
        "  (   /   )   / /  /__ )   (  )"
        "  (  )   / __/ '---`       / /"
        "  \\  /   \\ \\             _/ /"
        "  ] ]     )_\\_         /__\\/"
        "  /_\\     ]___\\"
        " (___)";

	unicornFrame[3] =
        "                      . . . ."
        "                      ,`,`,`,`,"
        ". . . .               `\\`\\`\\`\\;"
        "`\\`\\`\\`\\`,            ~|;!;!;\\!"
        " ~\\;\\;\\;\\|\\          (--,!!!~`!       ."
        "(--,\\\\\\===~\\         (--,|||~`!     ./"
        " (--,\\\\\\===~\\         `,-,~,=,:. _,//"
        "  (--,\\\\\\==~`\\        ~-=~-.---|\\;/J,"
        "   (--,\\\\\\((```==.    ~'`~/       a |"
        "     (-,.\\\\('('(`\\\\.  ~'=~|     \\_.  \\"
        "        (,--(,(,(,'\\\\. ~'=|       \\\\_;>"
        "          (,-( ,(,(,;\\\\ ~=/        \\"
        "          (,-/ (.(.(,;\\\\,/          )"
        "           (,--/,;,;,;,\\\\         ./------."
        "             (==,-;-'`;'         /_,----`. \\"
        "     ,.--_,__.-'                    `--.  ` \\"
        "    (='~-_,--/        ,       ,!,___--. \\  \\_)"
        "   (-/~(     |         \\   ,_-         | ) /_|"
        "   (~/((\\    )\\._,      |-'         _,/ /"
        "    \\\\))))  /   ./~.    |           \\_\\;"
        " ,__/////  /   /    )  /"
        "  '===~'   |  |    (, <."
        "           / /       \\. \\"
        "         _/ /          \\_\\"
        "        /_!/            >_\\";

	unicornFrame[4] =
        "								      |"
        "        \\\\\\\\                         ||"
        "         \\\\\\\\\\                       ||"
        "          \\\\\\\\                       ||"
        "           \\\\\\\\           \\\\\\\\\\      ||"
        "             \\\\\\         \\\\\\\\\\\\\\\\\\   ||"
        "      __    __\\\\\\__    \\\\\\\\\\\\\\|\\ \\\\\\\\||"
        "     /  |  /       \\  \\\\\\\\\\\\\\\\|\\\\ ___||_"
        "    / | | /         \\  \\\\\\\\\\\\\\\\_ \\     o \\____"
        " __/ /| |/      \\    \\\\\\\\\\\\\\\\\\/               \\"
        "|__L/ |________  \\    \\\\\\\\\\\\\\/     \\____/-----/"
        "       __/ /\\     \\    \\\\\\\\\\/        /"
        "      |__L/  \\ \\   \\    \\\\\\/      / /"
        "              \\ \\   \\_   \\/      / /"
        "               \\ \\       /      / /"
        "                \\ \\/           / /"
        "                 \\ |          / /"
        "                  \\|           /"
        "                   |    |     /"
        "                   \\    |____/|"
        "                    \\   |  \\  |"
        "                     \\  |   \\ \\"
        "                      \\ \\    \\ \\"
        "                       \\ \\    \\ \\"
        "                        \\ \\    \\ \\"
        "                         \\ \\    \\_\\"
        "                          \\_\\    | \\"
        "                           | \\   \\\\|"
        "                           \\\\|    \\|"
        "                            \\|";

}
