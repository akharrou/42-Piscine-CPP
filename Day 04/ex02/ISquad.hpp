/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:47:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 21:08:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "ISpaceMarine.hpp"
#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class ISquad {

	public:

		virtual	~ISquad() {}

		virtual	int				getCount ()      const = 0;
		virtual	ISpaceMarine	*getUnit ( int ) const = 0;

		virtual	int		push( ISpaceMarine *obj ) = 0;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* ISQUAD_HPP */
