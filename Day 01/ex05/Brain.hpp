/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:39:02 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 23:27:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

	public:

		Brain( int intel_lvl );
		~Brain();

		std::string	identify();

	private:

		int _intelligence_lvl;

};

#endif /* BRAIN_HPP */
