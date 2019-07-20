/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:36:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:51:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "IMiningLaser.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

#include "IAsteroid.hpp"
#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"

#include "MiningBarge.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	MiningBarge		*_42SiliconValley = new MiningBarge();

	IAsteroid		*asteroid_1 = new AsteroBocal();
	IAsteroid		*asteroid_2 = new BocalSteroid();

	IMiningLaser	*laser_1 = new DeepCoreMiner();
	IMiningLaser	*laser_2 = new StripMiner();

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << "Laser #1 is a " << laser_1->getType() << " !\n";
		std::cout << "Laser #2 is a " << laser_2->getType() << " !\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

		std::cout << "Asteroid #1 is a " << asteroid_1->getName() << " !\n";
		std::cout << "Asteroid #2 is a " << asteroid_2->getName() << " !\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nEQUIPPING BARGE :\n\n";

		_42SiliconValley->equip(laser_2); std::cout << "_42SiliconValley->equip(laser_2);\n";
		_42SiliconValley->equip(laser_1); std::cout << "_42SiliconValley->equip(laser_1);\n";

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n<DeepCoreMiner> LASER #1 :\n\n";

		std::cout << "StripMiner on BocalSteroid --> "; laser_2->mine(asteroid_2);
		std::cout << "DeepCoreMiner on BocalSteroid --> "; laser_1->mine(asteroid_2);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n<StripMiner> LASER #2:\n\n";

		std::cout << "StripMiner on AsteroBocal --> "; laser_2->mine(asteroid_1);
		std::cout << "DeepCoreMiner on AsteroBocal --> ";  laser_1->mine(asteroid_1);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\nMINING BARGE :\n\n";

		_42SiliconValley->mine(asteroid_2);
		_42SiliconValley->mine(asteroid_1);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n\n";

	return (0);
}
