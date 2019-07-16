/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:59 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 12:16:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

	public:

		HumanB( std::string name );
		~HumanB();

		void	attack() const;
		void	setWeapon( Weapon& weapon );

	private:

		Weapon		*_wep;
		std::string	_name;

};

#endif /* HUMANB_HPP */
