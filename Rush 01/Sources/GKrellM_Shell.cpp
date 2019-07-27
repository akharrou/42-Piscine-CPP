/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:44:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 16:48:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM_Shell.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell::GKrellM_Shell( void ) {

	(void)_modules;

	initscr();
    cbreak();
    noecho();
	curs_set(0);
	start_color();
	clear();
    refresh();

	// _modules[0] = new GeneralInfo();
	// _modules[1] = new CPU();
	// _modules[2] = new RAM();
	// _modules[3] = new Battery();

	mvprintw(5, 5, "HELLO WORLD !");
    refresh();

	sleep(3);
}

GKrellM_Shell::GKrellM_Shell( const GKrellM_Shell & src ) {
	*this = src;
}

GKrellM_Shell::~GKrellM_Shell( void ) {

	for (int i = 0; i < TOTAL_MODULES; ++i) {

		if (_modules[i] != NULL) {

			try {
				delete _modules[i];
			} catch ( std::exception & ) {}
		}
	}

	endwin();
}

/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell &	GKrellM_Shell::operator = ( const GKrellM_Shell & rhs ) {

	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	GKrellM_Shell::run() {

	std::cout << "GKrellM Shell Run" << std::endl;

	try {

		while (1)
		{
			updateModules();
			renderModules();
		}

	} catch ( std::exception & e ) {
		std::cerr << e.what() << std::endl;
	}
}

void	GKrellM_Shell::updateModules() {

	for (int i = 0; i < TOTAL_MODULES; ++i) {

		try {

			if (_modules[i] != NULL)
				_modules[i]->update();

		} catch ( std::exception & e ) {

			std::cerr << "~ Updating Error : " << e.what()
			          << " ; module " << _modules[i]->name
					  << " shutting down ~\n";

			delete _modules[i];
			_modules[i] = NULL;

		}
	}
}

void	GKrellM_Shell::renderModules() {

	for (int i = 0; i < TOTAL_MODULES; ++i) {

		try {

			if (_modules[i] != NULL)
				_modules[i]->render();

		} catch ( std::exception & e ) {

			std::cerr << "~ Rendering Error : " << e.what()
			          << " ; module " << _modules[i]->name
					  << " shutting down ~\n";

			delete _modules[i];
			_modules[i] = NULL;

		}
	}
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
