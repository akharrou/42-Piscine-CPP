/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network_Module.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:53:31 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:31:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	/* Parse it here */
}

void	Network_Module::render() {

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* NETWORK ACTIVITY INFORMATION */\n\n";

	std::cout << "NETWORK Activity : " << NETWORK_activity << "\n";

}
