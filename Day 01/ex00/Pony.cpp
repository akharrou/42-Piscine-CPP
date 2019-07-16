/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:06:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 16:38:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony( std::string name, std::string from ) :
	_name(name),
	_age(1),
	_from(from)
{
	std::cout << _name << " from the " << _from << " is born." << std::endl;
}

Pony::~Pony()
{
	std::cout << _name << " from the " << _from << " died at " << _age << " years old." << std::endl;
}

void	Pony::play(void)
{
	std::cout << "[" << _name << " from the " << _from << "] *plays*" << std::endl;
}
