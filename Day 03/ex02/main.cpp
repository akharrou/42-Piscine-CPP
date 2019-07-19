/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:14:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main() {

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "# ============================================================= #\n";
	std::cout << "#                        FR4G-TP TESTS                          #\n";
	std::cout << "# ============================================================= #\n\n";

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FragTrap	FR4G_TP_instance_1 ("Mark");
	FragTrap	FR4G_TP_instance_2 ("Koby");
	FragTrap	FR4G_TP_instance_3 ("Brian");
	FragTrap	FR4G_TP_instance_4 ("Albert");
	FragTrap	FR4G_TP_instance_5 ("Susie");
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << FR4G_TP_instance_1 << std::endl;
	std::cout << FR4G_TP_instance_2 << std::endl;
	std::cout << FR4G_TP_instance_3 << std::endl;
	std::cout << FR4G_TP_instance_4 << std::endl;
	std::cout << FR4G_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FR4G_TP_instance_1.vaulthunter_dot_exe( FR4G_TP_instance_3.getName() );
	FR4G_TP_instance_3.takeDamage( 70 );
	std::cout << std::endl;

	FR4G_TP_instance_1.vaulthunter_dot_exe( FR4G_TP_instance_4.getName() );
	FR4G_TP_instance_4.takeDamage( 70 );
	std::cout << std::endl;

	FR4G_TP_instance_1.vaulthunter_dot_exe( FR4G_TP_instance_5.getName() );
	FR4G_TP_instance_5.takeDamage( 70 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << FR4G_TP_instance_1 << std::endl;
	std::cout << FR4G_TP_instance_2 << std::endl;
	std::cout << FR4G_TP_instance_3 << std::endl;
	std::cout << FR4G_TP_instance_4 << std::endl;
	std::cout << FR4G_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FR4G_TP_instance_1.beRepaired( 20 );
	FR4G_TP_instance_1.beRepaired( 20 );
	FR4G_TP_instance_1.beRepaired( 20 );
	FR4G_TP_instance_1.beRepaired( 20 );
	FR4G_TP_instance_1.beRepaired( 20 );
	FR4G_TP_instance_1.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << FR4G_TP_instance_1 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FR4G_TP_instance_3.beRepaired( 20 );
	FR4G_TP_instance_4.beRepaired( 20 );
	FR4G_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << FR4G_TP_instance_2 << std::endl;
	std::cout << FR4G_TP_instance_3 << std::endl;
	std::cout << FR4G_TP_instance_4 << std::endl;
	std::cout << FR4G_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	FR4G_TP_instance_3.beRepaired( 20 );
	FR4G_TP_instance_4.beRepaired( 20 );
	FR4G_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	FR4G_TP_instance_3.beRepaired( 20 );
	FR4G_TP_instance_4.beRepaired( 20 );
	FR4G_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	FR4G_TP_instance_3.beRepaired( 20 );
	FR4G_TP_instance_4.beRepaired( 20 );
	FR4G_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	FR4G_TP_instance_3.beRepaired( 20 );
	FR4G_TP_instance_4.beRepaired( 20 );
	FR4G_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << FR4G_TP_instance_1 << std::endl;
	std::cout << FR4G_TP_instance_2 << std::endl;
	std::cout << FR4G_TP_instance_3 << std::endl;
	std::cout << FR4G_TP_instance_4 << std::endl;
	std::cout << FR4G_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << "# ============================================================= #\n";
	std::cout << "#                        SCAV-TP TESTS                          #\n";
	std::cout << "# ============================================================= #\n\n";

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	ScavTrap	SCAV_TP_instance_1 ("Mark");
	ScavTrap	SCAV_TP_instance_2 ("Koby");
	ScavTrap	SCAV_TP_instance_3 ("Brian");
	ScavTrap	SCAV_TP_instance_4 ("Albert");
	ScavTrap	SCAV_TP_instance_5 ("Susie");
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << SCAV_TP_instance_1 << std::endl;
	std::cout << SCAV_TP_instance_2 << std::endl;
	std::cout << SCAV_TP_instance_3 << std::endl;
	std::cout << SCAV_TP_instance_4 << std::endl;
	std::cout << SCAV_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	SCAV_TP_instance_1.challengeNewcomer( SCAV_TP_instance_3.getName() );
	SCAV_TP_instance_3.takeDamage( 70 );
	std::cout << std::endl;

	SCAV_TP_instance_1.challengeNewcomer( SCAV_TP_instance_4.getName() );
	SCAV_TP_instance_4.takeDamage( 70 );
	std::cout << std::endl;

	SCAV_TP_instance_1.challengeNewcomer( SCAV_TP_instance_5.getName() );
	SCAV_TP_instance_5.takeDamage( 70 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << SCAV_TP_instance_1 << std::endl;
	std::cout << SCAV_TP_instance_2 << std::endl;
	std::cout << SCAV_TP_instance_3 << std::endl;
	std::cout << SCAV_TP_instance_4 << std::endl;
	std::cout << SCAV_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	SCAV_TP_instance_1.beRepaired( 20 );
	SCAV_TP_instance_1.beRepaired( 20 );
	SCAV_TP_instance_1.beRepaired( 20 );
	SCAV_TP_instance_1.beRepaired( 20 );
	SCAV_TP_instance_1.beRepaired( 20 );
	SCAV_TP_instance_1.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << SCAV_TP_instance_1 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	SCAV_TP_instance_3.beRepaired( 20 );
	SCAV_TP_instance_4.beRepaired( 20 );
	SCAV_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << SCAV_TP_instance_2 << std::endl;
	std::cout << SCAV_TP_instance_3 << std::endl;
	std::cout << SCAV_TP_instance_4 << std::endl;
	std::cout << SCAV_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	SCAV_TP_instance_3.beRepaired( 20 );
	SCAV_TP_instance_4.beRepaired( 20 );
	SCAV_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	SCAV_TP_instance_3.beRepaired( 20 );
	SCAV_TP_instance_4.beRepaired( 20 );
	SCAV_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	SCAV_TP_instance_3.beRepaired( 20 );
	SCAV_TP_instance_4.beRepaired( 20 );
	SCAV_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	SCAV_TP_instance_3.beRepaired( 20 );
	SCAV_TP_instance_4.beRepaired( 20 );
	SCAV_TP_instance_5.beRepaired( 20 );
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	std::cout << SCAV_TP_instance_1 << std::endl;
	std::cout << SCAV_TP_instance_2 << std::endl;
	std::cout << SCAV_TP_instance_3 << std::endl;
	std::cout << SCAV_TP_instance_4 << std::endl;
	std::cout << SCAV_TP_instance_5 << std::endl;
	std::cout << std::endl;

	/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	return (0);
}
