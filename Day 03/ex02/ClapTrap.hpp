/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:18:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 17:01:46 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <string>
#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class ClapTrap {

	protected:

		int					_hit_points;
		int					_energy_points;

		int					_max_hit_points;
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

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap & src );
		~ClapTrap( void );

		ClapTrap &		operator = ( const ClapTrap & rhs );

		std::string		getName            () const;
		int				getLevel           () const;
		int				getHitPoints       () const;
		int				getEnergyPoints    () const;
		int				getMaxHitPoints    () const;
		int				getMaxEnergyPoints () const;

		virtual void	featherAttack  ( std::string const & target ) const = 0;
		virtual void	rangedAttack   ( std::string const & target ) const = 0;
		virtual void	meleeAttack    ( std::string const & target ) const = 0;
		virtual void	stealthAttack  ( std::string const & target ) const = 0;
		virtual void	ultimateAttack ( std::string const & target ) const = 0;

		void			takeDamage ( unsigned int amount );
		void			beRepaired ( unsigned int amount );

};

std::ostream & operator << ( std::ostream & out, const ClapTrap & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* CLAPTRAP_HPP */
