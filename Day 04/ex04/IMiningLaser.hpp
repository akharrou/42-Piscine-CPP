/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:57:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 16:28:13 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMININGLASER_HPP
# define IMININGLASER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IAsteroid;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IMiningLaser {

	public:
		virtual ~IMiningLaser() {}

		virtual const std::string &		getType() const           = 0;
		virtual void					mine( IAsteroid *target ) = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* IMININGLASER_HPP */
