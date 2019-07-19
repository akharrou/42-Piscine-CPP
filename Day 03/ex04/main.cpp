/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 23:14:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main() {

	{
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
	}

	{
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		std::cout << "\n\n# ============================================================= #\n";
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
	}

	{
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		std::cout << "\n\n# ============================================================= #\n";
		std::cout << "#                        NINJA-TP TESTS                         #\n";
		std::cout << "# ============================================================= #\n\n";

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		{
			NinjaTrap	NINJA_TP_instance_1 ("Mark");
			NinjaTrap	NINJA_TP_instance_2 ("Koby");
			NinjaTrap	NINJA_TP_instance_3 ("Brian");
			NinjaTrap	NINJA_TP_instance_4 ("Albert");
			NinjaTrap	NINJA_TP_instance_5 ("Susie");
			std::cout << std::endl;

			/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

			NINJA_TP_instance_1.featherAttack( "Xaiver Niel" );
			NINJA_TP_instance_2.rangedAttack( "Xaiver Niel" );
			NINJA_TP_instance_3.meleeAttack( "Xaiver Niel" );
			NINJA_TP_instance_4.stealthAttack( "Xaiver Niel" );
			NINJA_TP_instance_5.ultimateAttack( "Xaiver Niel" );
			std::cout << std::endl;
		}

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		{
			ClapTrap	ClapTrap_dummy  ("Clap");
			FragTrap	FragTrap_dummy  ("Frag");
			ScavTrap	ScavTrap_dummy  ("Scav");
			NinjaTrap	NinjaTrap_dummy ("Ninja");
			SuperTrap	SuperTrap_dummy ("Super");

			NinjaTrap	NinjaPro("Pro");

			std::cout << std::endl;

			NinjaPro.ninjaShoebox(ClapTrap_dummy);
			NinjaPro.ninjaShoebox(FragTrap_dummy);
			NinjaPro.ninjaShoebox(ScavTrap_dummy);
			NinjaPro.ninjaShoebox(NinjaTrap_dummy);
			NinjaPro.ninjaShoebox(SuperTrap_dummy);
			std::cout << std::endl;
		}

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	}

	{
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		std::cout << "\n\n# ============================================================= #\n";
		std::cout << "#                        SUPER-TP TESTS                         #\n";
		std::cout << "# ============================================================= #\n\n";

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */
		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

		{
			SuperTrap	Super ("Mark");
			std::cout << std::endl;

			std::cout << Super << std::endl;

			std::cout << std::endl;
		}

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		{
			SuperTrap	SUPER_TP_instance_1 ("Mark");
			SuperTrap	SUPER_TP_instance_2 ("Koby");
			SuperTrap	SUPER_TP_instance_3 ("Brian");
			SuperTrap	SUPER_TP_instance_4 ("Albert");
			SuperTrap	SUPER_TP_instance_5 ("Susie");
			std::cout << std::endl;

			/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

			SUPER_TP_instance_1.featherAttack( "Xaiver Niel" );
			SUPER_TP_instance_2.rangedAttack( "Xaiver Niel" );
			SUPER_TP_instance_3.meleeAttack( "Xaiver Niel" );
			SUPER_TP_instance_4.stealthAttack( "Xaiver Niel" );
			SUPER_TP_instance_5.ultimateAttack( "Xaiver Niel" );
			std::cout << std::endl;
		}

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		{
			ClapTrap	ClapTrap_dummy  ("Clap");
			FragTrap	FragTrap_dummy  ("Frag");
			ScavTrap	ScavTrap_dummy  ("Scav");
			NinjaTrap	NinjaTrap_dummy ("Ninja");
			SuperTrap	SuperTrap_dummy ("Super");

			SuperTrap	SuperPro ("Pro");

			std::cout << std::endl;

			SuperPro.ninjaShoebox(ClapTrap_dummy);
			SuperPro.ninjaShoebox(FragTrap_dummy);
			SuperPro.ninjaShoebox(ScavTrap_dummy);
			SuperPro.ninjaShoebox(NinjaTrap_dummy);
			SuperPro.ninjaShoebox(SuperTrap_dummy);
			std::cout << std::endl;
		}

		std::cout << "\n/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */\n\n";

		{
			ClapTrap	ClapTrap_dummy  ("Clap");
			FragTrap	FragTrap_dummy  ("Frag");
			ScavTrap	ScavTrap_dummy  ("Scav");
			NinjaTrap	NinjaTrap_dummy ("Ninja");
			SuperTrap	SuperTrap_dummy ("Super");

			SuperTrap	SuperPro ("Pro");

			std::cout << std::endl;

			SuperPro.vaulthunter_dot_exe( ClapTrap_dummy.getName() );
			SuperPro.vaulthunter_dot_exe( FragTrap_dummy.getName() );
			SuperPro.vaulthunter_dot_exe( ScavTrap_dummy.getName() );
			SuperPro.vaulthunter_dot_exe( NinjaTrap_dummy.getName() );
			SuperPro.vaulthunter_dot_exe( SuperTrap_dummy.getName() );
			std::cout << std::endl;
		}

		/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

	}

	return (0);
}
