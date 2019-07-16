/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:42:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 16:37:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class Pony {

	public:

		Pony(std::string name, std::string from);
		~Pony();

		void	play(void);

	private:

		std::string	_name;
		std::string	_from;
		int			_age;

};

#endif /* PONY_HPP */
