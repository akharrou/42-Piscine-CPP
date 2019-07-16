/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:59:04 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 20:22:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

	public:

		ZombieHorde( int N );
		~ZombieHorde();

		void	announce();

		static std::string	zombieNames[];
		static std::string	zombieTypes[];

		static int			nZombieNames;
		static int			nZombieTypes;

	private:

		int		_N;
		Zombie	*_horde;

};

#endif /* ZOMBIEHORDE_HPP */
