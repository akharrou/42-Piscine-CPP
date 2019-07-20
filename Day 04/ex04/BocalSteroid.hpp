/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BocalSteroid.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:30:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:28:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOCALSTEROID_HPP
# define BOCALSTEROID_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IAsteroid.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class BocalSteroid :
	public IAsteroid {

	private:
		std::string _name;

	public:

		BocalSteroid( void );
		BocalSteroid( const BocalSteroid & src );
		~BocalSteroid( void );

		BocalSteroid &	operator = ( const BocalSteroid & rhs );

		std::string		getName() const;

		std::string		beMined ( StripMiner const * )    const;
		std::string		beMined ( DeepCoreMiner const * ) const;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* BOCALSTEROID_HPP */
