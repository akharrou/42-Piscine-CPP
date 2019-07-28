/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU_Module.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:51:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:28:36 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
