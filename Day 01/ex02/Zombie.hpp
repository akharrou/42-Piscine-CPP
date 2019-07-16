/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:49 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 19:54:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

	public:

		Zombie(std::string name, std::string type);
		~Zombie();

		void	announce();
		void	setType(std::string new_type);

	private:

		std::string _name;
		std::string _type;

};

#endif /* ZOMBIE_HPP */
