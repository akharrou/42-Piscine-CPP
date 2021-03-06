/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:59:04 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 21:30:38 by akharrou         ###   ########.fr       */
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

		Zombie	*_horde;
		int		_N;

};

#endif /* ZOMBIEHORDE_HPP */
