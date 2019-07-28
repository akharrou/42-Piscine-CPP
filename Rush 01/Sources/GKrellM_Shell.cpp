/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:44:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 13:59:42 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM_Shell.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell::GKrellM_Shell( void ) {

	(void)_modules;

	// initscr();
    // cbreak();
    // noecho();
	// curs_set(0);
	// start_color();
	// clear();
    // refresh();

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	_modules.push_front( new Zaz_Module         );
	_modules.push_front( new Network_Module     );
	_modules.push_front( new Processes_Module   );
	_modules.push_front( new RAM_Module         );
	_modules.push_front( new CPU_Module         );
	_modules.push_front( new GeneralInfo_Module );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	// mvprintw(5, 5, "HELLO WORLD !");
    // refresh();
}

GKrellM_Shell::GKrellM_Shell( const GKrellM_Shell & src ) {
	*this = src;
}

GKrellM_Shell::~GKrellM_Shell( void ) {

	for (unsigned int i = 0; i < _modules.size(); ++i) {
	if (_modules[i] != nullptr) {

				try {
				delete _modules[i];
			} catch ( std::exception & ) {}
		}
	}

	// endwin();
}

/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell &	GKrellM_Shell::operator = ( const GKrellM_Shell & rhs ) {

	(void)rhs;
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

static inline bool OneSecondPassed(std::chrono::high_resolution_clock::time_point t1) {
	return ( (std::chrono::high_resolution_clock::now() - t1).count() < 1.0 /* seconds */ );
}

void	GKrellM_Shell::run() {

	std::cout << "GKrellM Shell Running !" << std::endl;

	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

	try {

		while (1)
		{

			t1 = std::chrono::high_resolution_clock::now();

			updateModules();
			renderModules();

			while ( ! OneSecondPassed(t1) );
				/* wait for the rest of that second */
		}

	} catch ( std::exception & e ) {
		std::cerr << "~ Error : " << e.what() << " ~\n";
	}
}

void	GKrellM_Shell::updateModules() {

	if (_modules[0] != nullptr)
		std::thread thread_0( [&]() {
			_modules[0]->update();
		});

	if (_modules[1] != nullptr)
		std::thread thread_1( [&]() {
			_modules[1]->update();
		});

	if (_modules[2] != nullptr)
		std::thread thread_2( [&]() {
			_modules[2]->update();
		});

	if (_modules[3] != nullptr)
		std::thread thread_3( [&]() {
			_modules[3]->update();
		});

	if (_modules[4] != nullptr)
		std::thread thread_4( [&]() {
			_modules[4]->update();
		});

	if (_modules[5] != nullptr)
		std::thread thread_5( [&]() {
			_modules[5]->update();
		});
}

void	GKrellM_Shell::renderModules() {

	if (_modules[0] != nullptr)
		std::thread thread_0( [&]() {
			_modules[0]->render();
		});

	if (_modules[1] != nullptr)
		std::thread thread_1( [&]() {
			_modules[1]->render();
		});

	if (_modules[2] != nullptr)
		std::thread thread_2( [&]() {
			_modules[2]->render();
		});

	if (_modules[3] != nullptr)
		std::thread thread_3( [&]() {
			_modules[3]->render();
		});

	if (_modules[4] != nullptr)
		std::thread thread_4( [&]() {
			_modules[4]->render();
		});

	if (_modules[5] != nullptr)
		std::thread thread_5( [&]() {
			_modules[5]->render();
		});
}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* ARCHIVE

void	GKrellM_Shell::updateModules() {

	for (int i = 0; i < _modules.size(); ++i) {

		try {

			if (_modules[i] != nullptr)
				_modules[i]->update();

		} catch ( std::exception & e ) {

			std::cerr << "~ Updating Error : " << e.what()
			          << " ; module " << _modules[i]->name
					  << " shutting down ~\n";

			delete _modules[i];
			_modules[i] = nullptr;

		}
	}
}

void	GKrellM_Shell::renderModules() {

	for (int i = 0; i < _modules.size(); ++i) {

		try {

			if (_modules[i] != nullptr)
				_modules[i]->render();

		} catch ( std::exception & e ) {

			std::cerr << "~ Rendering Error : " << e.what()
			          << " ; module " << _modules[i]->name
					  << " shutting down ~\n";

			delete _modules[i];
			_modules[i] = nullptr;

		}
	}
}

*/
