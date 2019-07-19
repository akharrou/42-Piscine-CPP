/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:48:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 18:53:20 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

NinjaTrap::NinjaTrap( void )
	: ClapTrap () {

	std::cout << "NinjaTrap Default constructor called" << std::endl;

    _hit_points             = 60;
    _max_hit_points         = 60;
    _energy_points          = 120;
    _max_energy_points      = 120;
    _ranged_attack_damage   = 5;
    _melee_attack_damage    = 60;
    _feather_attack_damage  = 15;
    _stealth_attack_damage  = 40;
    _ultimate_attack_damage = 60;
    _armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap( std::string name )
	: ClapTrap ( name ) {

	std::cout << "NinjaTrap Regular constructor called" << std::endl;

    _hit_points             = 60;
    _max_hit_points         = 60;
    _energy_points          = 120;
    _max_energy_points      = 120;
    _ranged_attack_damage   = 5;
    _melee_attack_damage    = 60;
    _feather_attack_damage  = 15;
    _stealth_attack_damage  = 40;
    _ultimate_attack_damage = 60;
    _armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap( const NinjaTrap & src ) {
	std::cout << "NinjaTrap Copy constructor called" << std::endl;
	*this = src;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NinjaTrap Deconstructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

NinjaTrap &		NinjaTrap::operator = ( const NinjaTrap & rhs ) {

	if (this != &rhs) {

		_hit_points             = rhs._hit_points;
		_energy_points          = rhs._energy_points;

		_max_hit_points         = rhs._max_hit_points;
		_max_energy_points      = rhs._max_energy_points;

		_name                   = rhs._name;
		_level                  = rhs._level;

		_ranged_attack_damage   = rhs._ranged_attack_damage;
		_melee_attack_damage    = rhs._melee_attack_damage;
		_feather_attack_damage  = rhs._feather_attack_damage;
		_stealth_attack_damage  = rhs._stealth_attack_damage;
		_ultimate_attack_damage = rhs._ultimate_attack_damage;

		_armor_damage_reduction = rhs._armor_damage_reduction;
	}
	return (*this);
}

std::ostream &	operator << ( std::ostream& out, const NinjaTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		NinjaTrap::getType() const {
	return ("<NinjaTrap>");
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void			NinjaTrap::rangedAttack ( std::string const & target ) const {
	std::cout << "NINJA-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ranged_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			NinjaTrap::meleeAttack  ( std::string const & target ) const {
	std::cout << "NINJA-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _melee_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			NinjaTrap::featherAttack  ( std::string const & target ) const {
	std::cout << "NINJA-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _feather_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			NinjaTrap::stealthAttack    ( std::string const & target ) const {
	std::cout << "NINJA-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _stealth_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			NinjaTrap::ultimateAttack   ( std::string const & target ) const {
	std::cout << "NINJA-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ultimate_attack_damage
	          << "> points of damage !"
	          << std::endl;
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string	g_classNames[] = {
	"ClapTrap", "FragTrap", "ScavTrap", "NinjaTrap"
};

void			NinjaTrap::ninjaShoebox( ClapTrap & target ) {

	std::cout << "* " << __func__ << "( " << target.getType() << " ) *" << std::endl;
}
