/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:33:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:03:00 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Logger.hpp"

int	main() {

	std::string timestamp;
	time_t rawtime;

	time (&rawtime);
	timestamp = std::string(ctime(&rawtime));
	timestamp[timestamp.length() - 1] = '\0';
	std::cout << ("[" + timestamp + "] " + std::string("Some super cool and long log msg.")) << std::endl;

	return (0);
}
