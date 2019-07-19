/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:32:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 16:17:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "AWeapon.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class PowerFist
	: public AWeapon {

	public:

		PowerFist( void );
		PowerFist( const PowerFist & src );
		~PowerFist( void );

		PowerFist &		operator = ( const PowerFist & rhs );

		void	attack() const;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* POWERFIST_HPP */
