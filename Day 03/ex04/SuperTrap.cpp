/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:28:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 20:40:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

SuperTrap::SuperTrap( void )
	: ClapTrap() {

	std::cout << "SuperTrap Default constructor called" << std::endl;

    _hit_points             = 100;
    _energy_points          = 100;
    _max_hit_points         = 100;
    _max_energy_points      = 100;
    _ranged_attack_damage   = 20;
    _melee_attack_damage    = 30;
    _feather_attack_damage  = 3;
    _stealth_attack_damage  = 15;
    _ultimate_attack_damage = 70;
    _armor_damage_reduction = 5;
}

SuperTrap::SuperTrap( std::string name )
	: ClapTrap( name ) {

	std::cout << "SuperTrap Regular constructor called" << std::endl;

    _hit_points             = 100;
    _energy_points          = 100;
    _max_hit_points         = 100;
    _max_energy_points      = 100;
    _ranged_attack_damage   = 20;
    _melee_attack_damage    = 30;
    _feather_attack_damage  = 3;
    _stealth_attack_damage  = 15;
    _ultimate_attack_damage = 70;
    _armor_damage_reduction = 5;
}

SuperTrap::SuperTrap( const SuperTrap & src ) {
	std::cout << "SuperTrap Copy constructor called" << std::endl;
	*this = src;
}

SuperTrap::~SuperTrap( void ) {
	std::cout << "SuperTrap Deconstructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

SuperTrap &		SuperTrap::operator = ( const SuperTrap & rhs ) {

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

std::ostream &	operator << ( std::ostream& out, const SuperTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		SuperTrap::getType() const {
	return ("<SuperTrap>");
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

void			SuperTrap::rangedAttack ( std::string const & target ) const {
	std::cout << "SUPER-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ranged_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			SuperTrap::meleeAttack  ( std::string const & target ) const {
	std::cout << "SUPER-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _melee_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			SuperTrap::featherAttack  ( std::string const & target ) const {
	std::cout << "SUPER-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _feather_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			SuperTrap::stealthAttack    ( std::string const & target ) const {
	std::cout << "SUPER-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _stealth_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			SuperTrap::ultimateAttack   ( std::string const & target ) const {
	std::cout << "SUPER-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ultimate_attack_damage
	          << "> points of damage !"
	          << std::endl;
}
