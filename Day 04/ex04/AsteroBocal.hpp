/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsteroBocal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:30:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 15:45:31 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROBOCAL_HPP
# define ASTEROBOCAL_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "IAsteroid.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AsteroBocal :
	public IAsteroid {

	private:
		std::string _name;

	public:

		AsteroBocal( void );
		AsteroBocal( const AsteroBocal & src );
		~AsteroBocal( void );

		AsteroBocal &	operator = ( const AsteroBocal & rhs );

		std::string		getName() const;

		std::string		beMined ( StripMiner const * )    const;
		std::string		beMined ( DeepCoreMiner const * ) const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ASTEROBOCAL_HPP */
