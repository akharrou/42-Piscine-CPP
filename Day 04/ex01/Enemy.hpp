/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:50:42 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 13:07:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class Enemy {

	protected:

		Enemy( void );

		std::string		_type;

		int				_hit_points;
		int				_max_hit_points;

	public:

		Enemy( int hp, std::string const & type );
		Enemy( const Enemy & src );
		virtual ~Enemy( void );

		Enemy &		operator = ( const Enemy & rhs );

		std::string		getType  () const;
		int				getHP    () const;
		int				getMaxHP () const;

		virtual void	takeDamage( int amount );

};

std::ostream & operator << ( std::ostream & out, const Enemy & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* ENEMY_HPP */
