/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IAsteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:20:12 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:27:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IASTEROID_HPP
# define IASTEROID_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class StripMiner;
class DeepCoreMiner;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IAsteroid {

	public:
		virtual ~IAsteroid() {}

		virtual std::string		getName() const                        = 0;

		virtual std::string		beMined( DeepCoreMiner const * ) const = 0;
		virtual std::string		beMined( StripMiner const * )    const = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* IASTEROID_HPP */
