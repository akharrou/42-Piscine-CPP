/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:29:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 17:47:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>
#include "ISpaceMarine.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class TacticalMarine
	: public ISpaceMarine {

	public:

		TacticalMarine( void );
		TacticalMarine( const TacticalMarine & src );
		~TacticalMarine( void );

		TacticalMarine &		operator = ( const TacticalMarine & rhs );

		ISpaceMarine	*clone () const;

		void	battleCry      () const;
		void	rangedAttack   () const;
		void	meleeAttack    () const;

};

std::ostream & operator << ( std::ostream & out, const TacticalMarine & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* TACTICALMARINE_HPP */
