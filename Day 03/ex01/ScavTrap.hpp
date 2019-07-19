/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:40:20 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:40:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

# define NUMBER_OF_CHALLENGES (5)

class ScavTrap {

	private:

		int					_hit_points;
		int					_max_hit_points;

		int					_energy_points;
		int					_max_energy_points;

		std::string			_name;
		int					_level;

		int					_ranged_attack_damage;
		int					_melee_attack_damage;
		int					_feather_attack_damage;
		int					_stealth_attack_damage;
		int					_ultimate_attack_damage;

		int					_armor_damage_reduction;

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap & src );
		~ScavTrap( void );

		ScavTrap &		operator = ( const ScavTrap & rhs );

		void			featherAttack  ( std::string const & target ) const;
		void			rangedAttack   ( std::string const & target ) const;
		void			meleeAttack    ( std::string const & target ) const;
		void			stealthAttack  ( std::string const & target ) const;
		void			ultimateAttack ( std::string const & target ) const;

		void			takeDamage ( unsigned int amount );
		void			beRepaired ( unsigned int amount );

		void			challengeNewcomer( std::string const & target ) const;

		std::string		getName            () const;
		int				getLevel           () const;
		int				getHitPoints       () const;
		int				getEnergyPoints    () const;
		int				getMaxHitPoints    () const;
		int				getMaxEnergyPoints () const;

};

std::ostream & operator<<( std::ostream & out, const ScavTrap & in );

#endif /* SCAVTRAP_HPP */
