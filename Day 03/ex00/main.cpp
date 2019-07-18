/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 15:39:02 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main() {

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FragTrap	instance_1 ("Mark");
	FragTrap	instance_2 ("Koby");
	FragTrap	instance_3 ("Brian");
	FragTrap	instance_4 ("Albert");
	FragTrap	instance_5 ("Susie");
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << instance_1 << std::endl;
	std::cout << instance_2 << std::endl;
	std::cout << instance_3 << std::endl;
	std::cout << instance_4 << std::endl;
	std::cout << instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	instance_1.vaulthunter_dot_exe( instance_3.getName() );
	instance_3.takeDamage( 70 );
	std::cout << std::endl;

	instance_1.vaulthunter_dot_exe( instance_4.getName() );
	instance_4.takeDamage( 70 );
	std::cout << std::endl;

	instance_1.vaulthunter_dot_exe( instance_5.getName() );
	instance_5.takeDamage( 70 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << instance_1 << std::endl;
	std::cout << instance_2 << std::endl;
	std::cout << instance_3 << std::endl;
	std::cout << instance_4 << std::endl;
	std::cout << instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	instance_1.beRepaired( 20 );
	instance_1.beRepaired( 20 );
	instance_1.beRepaired( 20 );
	instance_1.beRepaired( 20 );
	instance_1.beRepaired( 20 );
	instance_1.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << instance_1 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	instance_3.beRepaired( 20 );
	instance_4.beRepaired( 20 );
	instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << instance_2 << std::endl;
	std::cout << instance_3 << std::endl;
	std::cout << instance_4 << std::endl;
	std::cout << instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	instance_3.beRepaired( 20 );
	instance_4.beRepaired( 20 );
	instance_5.beRepaired( 20 );
	std::cout << std::endl;

	instance_3.beRepaired( 20 );
	instance_4.beRepaired( 20 );
	instance_5.beRepaired( 20 );
	std::cout << std::endl;

	instance_3.beRepaired( 20 );
	instance_4.beRepaired( 20 );
	instance_5.beRepaired( 20 );
	std::cout << std::endl;

	instance_3.beRepaired( 20 );
	instance_4.beRepaired( 20 );
	instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << instance_1 << std::endl;
	std::cout << instance_2 << std::endl;
	std::cout << instance_3 << std::endl;
	std::cout << instance_4 << std::endl;
	std::cout << instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}
