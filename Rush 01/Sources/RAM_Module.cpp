/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM_Module.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:52:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:31:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n";
	std::cout << "/* RAM MEMORY INFORMATION */\n\n";

	std::cout << "RAM Usage : " << RAM_usage << "\n";

}
