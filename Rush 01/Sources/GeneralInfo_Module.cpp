/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GeneralInfo_Module.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:50:56 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:29:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* GENERAL INFORMATION */\n\n";

	std::cout << Datetime    << "\n\n";
	std::cout << Username    << "\n";
	std::cout << Hostname    << "\n";
	std::cout << OS_Name     << "\n";
	std::cout << OS_Release  << "\n";
	std::cout << Platform    << "\n";
}
