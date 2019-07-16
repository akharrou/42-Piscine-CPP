/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:24:41 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 16:32:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int	main(int ac, char **av) {

	Human *me = new Human;

	me->action(std::string(av[1]), std::string(av[2]));

	delete (me);

	(void)ac;
	return (0);
}
