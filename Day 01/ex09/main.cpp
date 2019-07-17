/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:33:00 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 17:34:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Logger.hpp"

int	main() {

	Logger	logger("log.txt");

	logger.log("logToFile", "[WARNING] : * msg *\n");
	logger.log("logToConsole", "[WARNING] : * msg *\n");

	return (0);
}
