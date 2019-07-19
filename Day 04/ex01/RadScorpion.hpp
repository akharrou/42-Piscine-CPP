/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:05:37 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 15:13:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "Enemy.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class RadScorpion
	: public Enemy {

	public:

		RadScorpion( void );
		RadScorpion( const RadScorpion & src );
		~RadScorpion( void );

		RadScorpion &		operator = ( const RadScorpion & rhs );

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* RADSCORPION_HPP */
