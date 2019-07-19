/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:45:52 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 10:15:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <string>
#include "Victim.hpp"

class Peon
	: public Victim {

	public:

		Peon( void );
		Peon( std::string name );
		Peon( const Peon & src );
		~Peon( void );

		Peon &		operator = ( const Peon & rhs );

		void		getPolymorphed() const;

};

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* PEON_HPP */
