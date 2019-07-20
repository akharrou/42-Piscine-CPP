/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:16:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:27:51 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class DeepCoreMiner :
	public IMiningLaser {

	private:
		const std::string _type;

	public:
		DeepCoreMiner( void );
		DeepCoreMiner( const DeepCoreMiner & src );
		~DeepCoreMiner( void );

		DeepCoreMiner &			operator = ( const DeepCoreMiner & rhs );

		const std::string &		getType() const;
		void					mine( IAsteroid *target );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* DEEPCOREMINER_HPP */
