/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:40:17 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:17:01 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

ScavTrap::ScavTrap( void ) :
	_hit_points(100),
	_energy_points(50),
	_level(1),
	_name("none"),
	_ranged_attack_damage(15),
	_melee_attack_damage(20),
	_feather_attack_damage(8),
	_stealth_attack_damage(10),
	_ultimate_attack_damage(75),
	_armor_damage_reduction(3) {

		std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) :
	_hit_points(100),
	_energy_points(50),
	_level(1),
	_name(name),
	_ranged_attack_damage(15),
	_melee_attack_damage(20),
	_feather_attack_damage(8),
	_stealth_attack_damage(10),
	_ultimate_attack_damage(75),
	_armor_damage_reduction(3) {

	std::cout << "ScavTrap Regular constructor called" << std::endl;
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

std::ostream &	operator<<( std::ostream& out, const ScavTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		ScavTrap::getName() const {
	return (_name);
}

int				ScavTrap::getLevel() const {
	return (_level);
}

int				ScavTrap::getHitPoints() const {
	return (_hit_points);
}
int				ScavTrap::getEnergyPoints() const {
	return (_energy_points);
}

int				ScavTrap::getMaxHitPoints() const {
	return (_max_hit_points);
}
int				ScavTrap::getMaxEnergyPoints() const {
	return (_max_energy_points);
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

void			ScavTrap::takeDamage   ( unsigned int amount ) {

	amount = amount - _armor_damage_reduction;

	std::cout << "<" << _name
	          << "> * takes damage for "<< amount
			  << " hit points *"
			  << std::endl;

	_hit_points = (_hit_points - amount > 0) ?
		(_hit_points - amount) : 0;
}

void			ScavTrap::beRepaired   ( unsigned int amount ) {

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
