/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:55:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:28:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class MiningBarge {

	private:

		static const int	_max_lasers = 4;
		IMiningLaser		*_lasers[_max_lasers];

	public:

		MiningBarge( void );
		MiningBarge( const MiningBarge & src );
		~MiningBarge( void );

		MiningBarge &	operator = ( const MiningBarge & rhs );

		void	equip ( IMiningLaser * );
		void	mine  ( IAsteroid * ) const;

};

std::ostream & operator << ( std::ostream & out, const MiningBarge & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MININGBARGE_HPP */
