/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electricity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:27:43 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 12:10:52 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELECTRICITY_HPP
# define ELECTRICITY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Electricity
	: public AMateria {

	public:
		Electricity( void );
		Electricity( const Electricity & src );
		~Electricity( void );

		Electricity &		operator = ( const Electricity & rhs );

		AMateria	*clone() const;
		void		use( ICharacter & target );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ELECTRICITY_HPP */
