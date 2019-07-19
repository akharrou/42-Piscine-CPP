/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:58:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 12:48:17 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <string>
#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class AWeapon {

	protected:

		AWeapon( void );

		std::string		_name;
		int				_damage_points;
		int				_action_points;

	public:

		AWeapon( std::string const & name, int apcost, int damage );
		AWeapon( const AWeapon & src );
		virtual ~AWeapon( void );

		AWeapon &		operator = ( const AWeapon & rhs );

		std::string		getName   () const;
		int				getAPCost () const;
		int				getDamage () const;

		virtual void	attack() const = 0;

};

std::ostream & operator << ( std::ostream & out, const AWeapon & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* AWEAPON_HPP */
