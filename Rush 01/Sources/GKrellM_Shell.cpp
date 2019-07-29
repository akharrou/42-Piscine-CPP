/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:56:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/29 00:57:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM_Shell.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */


GKrellM_Shell::GKrellM_Shell( void ) {

	coord_t shellMax;
	coord_t shellMin;

	initscr     ( );
    cbreak      ( );
    noecho      ( );
	curs_set    (0);
	start_color ( );
	clear       ( );
	refresh     ( );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	getmaxyx ( stdscr, shellMax.y, shellMax.x );
	shellMin = { 0 , 0 };

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	screen_t GeneralInfo_Screen = {
		newwin( shellMax.y * 0.265, shellMax.x * 0.25, shellMin.y + 1, shellMin.x + 2) ,
		{ static_cast<int_fast16_t>(shellMin.y + 1) , static_cast<int_fast16_t>(shellMin.x + 2) } ,
		{ static_cast<int_fast16_t>((shellMin.y + 1) + (shellMax.y * 0.265) - 1) , static_cast<int_fast16_t>(shellMax.x * 0.25) }
	};

	screen_t Network_Screen = {
		newwin( shellMax.y * 0.265, GeneralInfo_Screen.max.x, GeneralInfo_Screen.max.y + 1, GeneralInfo_Screen.min.x) ,
		{ static_cast<int_fast16_t>(GeneralInfo_Screen.max.y + 1) , static_cast<int_fast16_t>(GeneralInfo_Screen.min.x) } ,
		{ static_cast<int_fast16_t>(GeneralInfo_Screen.max.y + 1 + (shellMax.y * 0.265) - 1) , static_cast<int_fast16_t>(GeneralInfo_Screen.max.x + GeneralInfo_Screen.min.x) }
	};

	screen_t Processes_Screen = {
		newwin( shellMax.y * 0.1, (shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0), shellMin.y + 1, GeneralInfo_Screen.max.x + 3) ,
		{ static_cast<int_fast16_t>(shellMin.y + 1), static_cast<int_fast16_t>(GeneralInfo_Screen.max.x + 3) } ,
		{ static_cast<int_fast16_t>(shellMax.y * 0.1), static_cast<int_fast16_t>(GeneralInfo_Screen.max.x + 3 + ((shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0) - 1)) }
	};

	screen_t Zaz_Screen = {
		newwin( (shellMax.y - 2) - (shellMax.y * 0.265 * 2) + 1, (shellMax.x - 4), Network_Screen.max.y + 1, shellMin.x + 2) ,
		{ static_cast<int_fast16_t>(Network_Screen.max.y + 1) , static_cast<int_fast16_t>(shellMin.x + 2) } ,
		{ static_cast<int_fast16_t>(Network_Screen.max.y + 1 + (shellMax.y - 2) - (shellMax.y * 0.265 * 2) + 1) , static_cast<int_fast16_t>(shellMin.x + 2 + (shellMax.x - 4)) }
	};

	screen_t RAM_Screen = {
		newwin( (GeneralInfo_Screen.max.y + 1 + shellMax.y * 0.265) - (Processes_Screen.max.y + 1), ((shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0)) / 2 + 1, Processes_Screen.max.y + 1, Processes_Screen.min.x + shellMax.x * (1.0 - 0.265) / 2) ,
		{ static_cast<int_fast16_t>(Processes_Screen.max.y + 1), static_cast<int_fast16_t>(Processes_Screen.min.x + shellMax.x * (1.0 - 0.265) / 2) } ,
		{ static_cast<int_fast16_t>(Processes_Screen.max.y + 1 + ((GeneralInfo_Screen.max.y + 1 + shellMax.y * 0.265) - (Processes_Screen.max.y + 1))) , static_cast<int_fast16_t>(Processes_Screen.min.x + shellMax.x * (1.0 - 0.265) / 2 + ((shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0)) / 2 + 1) }
	};

	screen_t CPU_Screen = {
		newwin( (GeneralInfo_Screen.max.y + 1 + shellMax.y * 0.265) - (Processes_Screen.max.y + 1), ((shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0)) / 2 - 1, Processes_Screen.max.y + 1, GeneralInfo_Screen.max.x + 3) ,
		{ static_cast<int_fast16_t>(Processes_Screen.max.y + 1) , static_cast<int_fast16_t>(GeneralInfo_Screen.max.x + 3) } ,
		{ static_cast<int_fast16_t>(Processes_Screen.max.y + 1 + ((GeneralInfo_Screen.max.y + 1 + shellMax.y * 0.265) - (Processes_Screen.max.y + 1))) , static_cast<int_fast16_t>(GeneralInfo_Screen.max.x + 3 + ((shellMax.x - 4) - (shellMax.x * 0.25) - 1 + (static_cast<int>(shellMax.x * 0.25) % 2 == 0)) / 2 - 1) }
	};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	_modules.push_front( new Zaz_Module         ( Zaz_Screen         ) );
	_modules.push_front( new Processes_Module   ( Processes_Screen   ) );
	_modules.push_front( new Network_Module     ( Network_Screen     ) );
	_modules.push_front( new RAM_Module         ( RAM_Screen         ) );
	_modules.push_front( new CPU_Module         ( CPU_Screen         ) );
	_modules.push_front( new GeneralInfo_Module ( GeneralInfo_Screen ) );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
}

GKrellM_Shell::~GKrellM_Shell( void ) {

	for (unsigned int i = 0; i < _modules.size(); ++i) {
	if (_modules[i] != nullptr) {

			try {
				delwin(_modules[i]->screen.win);
				delete _modules[i];
			} catch ( std::exception & ) {}
		}
	}

	endwin();
}

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

static inline bool OneSecondPassed(std::chrono::high_resolution_clock::time_point t1) {
	return (
		std::chrono::duration<double>(
			std::chrono::high_resolution_clock::now() - t1).count()
			                          >
			                   1.0 /* second */
	);
}

void	GKrellM_Shell::run() {

	std::chrono::high_resolution_clock::time_point t1;

	try {

		while (1)
		{

			t1 = std::chrono::high_resolution_clock::now();

			updateModules();
			renderModules();

			while ( ! OneSecondPassed(t1) )
				/* wait until it has passed ... */;

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

	for (unsigned int i = 0; i < _modules.size(); ++i) {

		if (_modules[i])
			_modules[i]->render();
	}
}
