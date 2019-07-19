/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:18:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 17:42:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

ClapTrap::ClapTrap( void ) :
	_name("none"), _level(1) {

	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :
	_name(name), _level(1) {

	std::cout << "ClapTrap Regular constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Deconstructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

ClapTrap &		ClapTrap::operator = ( const ClapTrap & rhs ) {

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

std::ostream &	operator << ( std::ostream& out, const ClapTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		ClapTrap::getName() const {
	return (_name);
}

int				ClapTrap::getLevel() const {
	return (_level);
}

int				ClapTrap::getHitPoints() const {
	return (_hit_points);
}
int				ClapTrap::getEnergyPoints() const {
	return (_energy_points);
}

int				ClapTrap::getMaxHitPoints() const {
	return (_max_hit_points);
}
int				ClapTrap::getMaxEnergyPoints() const {
	return (_max_energy_points);
}


/* PRIVATE MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — */

void			ClapTrap::takeDamage   ( unsigned int amount ) {

	amount = amount - _armor_damage_reduction;

	std::cout << "<" << _name
	          << "> * takes damage for "<< amount
			  << " hit points *"
			  << std::endl;

	_hit_points = (_hit_points - amount > 0) ?
		(_hit_points - amount) : 0;
}

void			ClapTrap::beRepaired   ( unsigned int amount ) {

    int	repair_hit_pts    = amount;
    int	repair_energy_pts = amount;

	if (_hit_points != _max_hit_points) {

		repair_hit_pts = (_hit_points + repair_hit_pts > _max_hit_points) ?
			 _max_hit_points - _hit_points : repair_hit_pts;
		_hit_points += repair_hit_pts;

	} else {
		repair_hit_pts = 0;
	}

	if (_energy_points != _max_energy_points) {

		repair_energy_pts = (_energy_points + repair_energy_pts > _max_energy_points) ?
			 _max_energy_points - _energy_points : repair_energy_pts;
		_energy_points += repair_energy_pts;

	} else {
		repair_energy_pts = 0;
	}

	std::cout << "<" << _name
	          << "> * gets repaired for "<< repair_hit_pts
			  << " hit points and " << repair_energy_pts
			  << " energy points *"
			  << std::endl;
}
