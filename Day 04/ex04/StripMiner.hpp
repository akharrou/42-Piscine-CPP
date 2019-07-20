/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:39:09 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:27:32 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class StripMiner :
	public IMiningLaser {

	private:
		const std::string _type;

	public:
		StripMiner( void );
		StripMiner( const StripMiner & src );
		~StripMiner( void );

		StripMiner &			operator = ( const StripMiner & rhs );

		const std::string &		getType() const;
		void					mine( IAsteroid *target );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* STRIPMINER_HPP */
