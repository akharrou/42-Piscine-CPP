/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:27:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 10:46:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Cure
	: public AMateria {

	public:
		Cure( void );
		Cure( const Cure & src );
		~Cure( void );

		Cure &		operator = ( const Cure & rhs );

		AMateria	*clone() const;
		void		use( ICharacter & target );

};

std::ostream & operator << ( std::ostream & out, const Cure & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* CURE_HPP */
