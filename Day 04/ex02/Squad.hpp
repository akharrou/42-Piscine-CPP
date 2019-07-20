/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:56:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 19:27:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

typedef struct s_unit {
	ISpaceMarine	*unit;
	s_unit			*next;
} unit_t;

class Squad
	: public ISquad {

	private:

		unit_t	*_squad;
		int		_squad_count;

	public:

		Squad( void );
		Squad( const Squad & src );
		~Squad( void );

		Squad &		operator = ( const Squad & rhs );

		int				getCount  ()      const;
		ISpaceMarine	*getUnit  ( int ) const;

		int		push( ISpaceMarine *obj );

};

std::ostream & operator << ( std::ostream & out, const Squad & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SQUAD_HPP */
