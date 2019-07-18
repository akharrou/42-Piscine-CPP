/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:04:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — — — — */

FragTrap::FragTrap( void ) :
	_hit_points(100),
	_energy_points(100),
	_level(1),
	_name("none"),
	_ranged_attack_damage(20),
	_melee_attack_damage(30),
	_feather_attack_damage(3),
	_stealth_attack_damage(15),
	_ultimate_attack_damage(70),
	_armor_damage_reduction(5)
{
		std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) :
	_hit_points(100),
	_energy_points(100),
	_level(1),
	_name(name),
	_ranged_attack_damage(20),
	_melee_attack_damage(30),
	_feather_attack_damage(3),
	_stealth_attack_damage(15),
	_ultimate_attack_damage(70),
	_armor_damage_reduction(5)
{
	std::cout << "FragTrap Regular constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap Deconstructor called" << std::endl;
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

FragTrap &		FragTrap::operator = ( const FragTrap & rhs ) {

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

std::ostream &	operator<<( std::ostream& out, const FragTrap & in ) {

	out << in.getName()
		<< " <Level " << in.getLevel() << ">"
		<< " <Hit Points: " << in.getHitPoints() << "/" << in.getMaxHitPoints() << ">"
		<< " <Energy Points: " << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints() << ">";
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

std::string		FragTrap::getName() const {
	return (_name);
}

int				FragTrap::getLevel() const {
	return (_level);
}

int				FragTrap::getHitPoints() const {
	return (_hit_points);
}
int				FragTrap::getEnergyPoints() const {
	return (_energy_points);
}

int				FragTrap::getMaxHitPoints() const {
	return (_max_hit_points);
}
int				FragTrap::getMaxEnergyPoints() const {
	return (_max_energy_points);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

void			FragTrap::rangedAttack ( std::string const & target ) const {
	std::cout << "FR4G-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ranged_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			FragTrap::meleeAttack  ( std::string const & target ) const {
	std::cout << "FR4G-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _melee_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			FragTrap::featherAttack  ( std::string const & target ) const {
	std::cout << "FR4G-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _feather_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			FragTrap::stealthAttack    ( std::string const & target ) const {
	std::cout << "FR4G-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _stealth_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

void			FragTrap::ultimateAttack   ( std::string const & target ) const {
	std::cout << "FR4G-TP <" << _name
	          << "> attacks <" << target
	          << "> with " << __func__
			  << ", causing <" << _ultimate_attack_damage
	          << "> points of damage !"
	          << std::endl;
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void			FragTrap::takeDamage   ( unsigned int amount ) {

	amount = amount - _armor_damage_reduction;

	std::cout << "<" << _name
	          << "> * takes damage for "<< amount
			  << " hit points *"
			  << std::endl;

	_hit_points = (_hit_points - amount > 0) ?
		(_hit_points - amount) : 0;
}

void			FragTrap::beRepaired   ( unsigned int amount ) {

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

typedef struct {
	void (FragTrap::*func)(std::string const &target) const;
} attack_t;

attack_t	g_attacks_table[] = {
	{ &FragTrap::featherAttack  },
	{ &FragTrap::rangedAttack   },
	{ &FragTrap::meleeAttack    },
	{ &FragTrap::stealthAttack  },
	{ &FragTrap::ultimateAttack }
};

void			FragTrap::vaulthunter_dot_exe( std::string const & target ) {

	if (_energy_points < 25) {
		std::cout << "* Out of energy for an attack *" << std::endl;
		return ;
	}

	int i = (_energy_points * _hit_points - _level) % NUMBER_OF_ATTACKS;

	(*this.*g_attacks_table[i].func)(target);
	_energy_points -= 25;
}
