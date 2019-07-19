/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:46:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "Enemy.hpp"
#include "AWeapon.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class Character {

	private:

		Character( void );

		std::string	_name;
		AWeapon		*_weapon;

		int			_action_points;
		int			_max_action_points;

	public:

		Character( std::string const & name );
		Character( const Character & src );
		~Character( void );

		Character &		operator = ( const Character & rhs );

		int				getAP      () const;
		std::string		getName    () const;
		AWeapon			*getWeapon () const;

		void			recoverAP( void );
		void			equip( AWeapon *weapon );
		void			attack( Enemy *target );

};

std::ostream & operator << ( std::ostream & out, const Character & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* CHARACTER_HPP */
