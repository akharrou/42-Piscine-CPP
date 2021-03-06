/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:39:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

# define NUMBER_OF_ATTACKS (5)

class FragTrap {

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

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap & src );
		~FragTrap( void );

		FragTrap &		operator = ( const FragTrap & rhs );

		void			featherAttack  ( std::string const & target ) const;
		void			rangedAttack   ( std::string const & target ) const;
		void			meleeAttack    ( std::string const & target ) const;
		void			stealthAttack  ( std::string const & target ) const;
		void			ultimateAttack ( std::string const & target ) const;

		void			takeDamage ( unsigned int amount );
		void			beRepaired ( unsigned int amount );

		void			vaulthunter_dot_exe( std::string const & target );

		std::string		getName            () const;
		int				getLevel           () const;
		int				getHitPoints       () const;
		int				getEnergyPoints    () const;
		int				getMaxHitPoints    () const;
		int				getMaxEnergyPoints () const;

};

std::ostream & operator<<( std::ostream & out, const FragTrap & in );

#endif /* FRAGTRAP_HPP */
