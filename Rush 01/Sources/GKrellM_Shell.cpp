/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:44:27 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:50:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM_Shell.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GKrellM_Shell::GKrellM_Shell( void ) {

	// initscr();
    // cbreak();
    // noecho();
	// curs_set(0);
	// start_color();
	// clear();
    // refresh();

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	screen_t newScreen = { stdscr, 0 , 0 };

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	_modules.push_front( new Zaz_Module         ( newScreen ) );
	_modules.push_front( new Processes_Module   ( newScreen ) );
	_modules.push_front( new Network_Module     ( newScreen ) );
	_modules.push_front( new RAM_Module         ( newScreen ) );
	_modules.push_front( new CPU_Module         ( newScreen ) );
	_modules.push_front( new GeneralInfo_Module ( newScreen ) );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    // refresh();
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

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

static inline bool OneSecondPassed(std::chrono::high_resolution_clock::time_point t1) {
	return ( std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t1).count() > 1.0 /* seconds */ );
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

		}

	} catch ( std::exception & e ) {
		std::cerr << "~ Error : " << e.what() << " ~\n";
	}
}

void	GKrellM_Shell::updateModules() {

	std::thread thread_0;
	std::thread thread_1;
	std::thread thread_2;
	std::thread thread_3;
	std::thread thread_4;
	std::thread thread_5;

	if (_modules[0] != nullptr)
		thread_0 = std::thread( [&]() {
			_modules[0]->update();
		});

	if (_modules[1] != nullptr)
		thread_1 = std::thread( [&]() {
			_modules[1]->update();
		});

	if (_modules[2] != nullptr)
		thread_2 = std::thread( [&]() {
			_modules[2]->update();
		});

	if (_modules[3] != nullptr)
		thread_3 = std::thread( [&]() {
			_modules[3]->update();
		});

	if (_modules[4] != nullptr)
		thread_4 = std::thread( [&]() {
			_modules[4]->update();
		});

	if (_modules[5] != nullptr)
		thread_5 = std::thread( [&]() {
			_modules[5]->update();
		});

	thread_0.join();
	thread_1.join();
	thread_2.join();
	thread_3.join();
	thread_4.join();
	thread_5.join();
}

void	GKrellM_Shell::renderModules() {

	_modules[0]->render();
	_modules[1]->render();
	_modules[2]->render();
	_modules[3]->render();
	_modules[4]->render();
	_modules[5]->render();

	// std::thread thread_0,
	//             thread_1,
	//             thread_2,
	//             thread_3,
	//             thread_4,
	//             thread_5;

	// if (_modules[0] != nullptr)
	// 	thread_0 = std::thread( [&]() {
	// 		_modules[0]->render();
	// 	});

	// if (_modules[1] != nullptr)
	// 	thread_1 = std::thread( [&]() {
	// 		_modules[1]->render();
	// 	});

	// if (_modules[2] != nullptr)
	// 	thread_2 = std::thread( [&]() {
	// 		_modules[2]->render();
	// 	});

	// if (_modules[3] != nullptr)
	// 	thread_3 = std::thread( [&]() {
	// 		_modules[3]->render();
	// 	});

	// if (_modules[4] != nullptr)
	// 	thread_4 = std::thread( [&]() {
	// 		_modules[4]->render();
	// 	});

	// if (_modules[5] != nullptr)
	// 	thread_5 = std::thread( [&]() {
	// 		_modules[5]->render();
	// 	});

	// thread_0.join();
	// thread_1.join();
	// thread_2.join();
	// thread_3.join();
	// thread_4.join();
	// thread_5.join();
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
