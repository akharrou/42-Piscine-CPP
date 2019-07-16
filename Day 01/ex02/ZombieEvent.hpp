/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:43:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 19:24:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {

	public:

		ZombieEvent(std::string type);
		~ZombieEvent();

		void				setZombieType(std::string type);

		Zombie				*newZombie(std::string name);
		Zombie				*randomChump();

		static std::string	zombieNames[];
		static int			nZombieNames;


	private:

		std::string		_type;

};

#endif /* ZOMBIEEVENT_HPP */
