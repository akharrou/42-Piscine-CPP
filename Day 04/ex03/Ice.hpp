/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:27:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 10:47:03 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Ice
	: public AMateria {

	public:
		Ice( void );
		Ice( const Ice & src );
		~Ice( void );

		Ice &		operator = ( const Ice & rhs );

		AMateria	*clone() const;
		void		use( ICharacter & target );

};

std::ostream & operator << ( std::ostream & out, const Ice & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ICE_HPP */
