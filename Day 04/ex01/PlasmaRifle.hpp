/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:32:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:17:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "AWeapon.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class PlasmaRifle
	: public AWeapon {

	public:

		PlasmaRifle( void );
		PlasmaRifle( const PlasmaRifle & src );
		~PlasmaRifle( void );

		PlasmaRifle &		operator = ( const PlasmaRifle & rhs );

		void	attack() const;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* PLASMARIFLE_HPP */
