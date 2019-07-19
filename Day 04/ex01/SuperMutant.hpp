/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:05:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:13:42 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "Enemy.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class SuperMutant
	: public Enemy {

	public:

		SuperMutant( void );
		SuperMutant( const SuperMutant & src );
		~SuperMutant( void );

		SuperMutant &		operator = ( const SuperMutant & rhs );

		void	takeDamage( int amount );

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SUPERMUTANT_HPP */
