/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:40:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 17:41:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

ScavTrap::ScavTrap( void )
	: ClapTrap () {

	std::cout << "ScavTrap Default constructor called" << std::endl;

    _hit_points             = 100;
    _energy_points          = 50;
    _max_hit_points         = 100;
    _max_energy_points      = 50;
    _ranged_attack_damage   = 15;
    _melee_attack_damage    = 20;
    _feather_attack_damage  = 8;
    _stealth_attack_damage  = 10;
    _ultimate_attack_damage = 75;
    _armor_damage_reduction = 3;
}

ScavTrap::ScavTrap( std::string name )
	: ClapTrap ( name ) {

	std::cout << "ScavTrap Regular constructor called" << std::endl;

    _hit_points             = 100;
    _energy_points          = 50;
    _max_hit_points         = 100;
    _max_energy_points      = 50;
    _ranged_attack_damage   = 15;
    _melee_attack_damage    = 20;
    _feather_attack_damage  = 8;
    _stealth_attack_damage  = 10;
    _ultimate_attack_damage = 75;
    _armor_damage_reduction = 3;
}

ScavTrap::ScavTrap( const ScavTrap & src ) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

ScavTrap &		ScavTrap::operator = ( const ScavTrap & rhs ) {

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

std::ostream &	operator << ( std::ostream& out, const ScavTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void			ScavTrap::rangedAttack ( std::string const & target ) const {
	std::cout << "SCAV-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ranged_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			ScavTrap::meleeAttack  ( std::string const & target ) const {
	std::cout << "SCAV-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _melee_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			ScavTrap::featherAttack  ( std::string const & target ) const {
	std::cout << "SCAV-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _feather_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			ScavTrap::stealthAttack    ( std::string const & target ) const {
	std::cout << "SCAV-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _stealth_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			ScavTrap::ultimateAttack   ( std::string const & target ) const {
	std::cout << "SCAV-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ultimate_attack_damage
	          << "> points of damage !"
	          << std::endl;
}


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string	g_challenges_table[] = {
	"* challenge 1 *",
	"* challenge 2 *",
	"* challenge 3 *",
	"* challenge 4 *",
	"* challenge 5 *"
};

void			ScavTrap::challengeNewcomer( std::string const & target ) const {

	int i = (_energy_points * _hit_points - _level) % NUMBER_OF_CHALLENGES;
	std::cout << "challenge's " << target << " with " << g_challenges_table[i] << std::endl;
}
