/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Processes_Module.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:53:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 14:59:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

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

	system( "top -F -n0 -l1 | grep \"Processes\" > " PROCESSES_ACTIVITY_FILENAME );

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
