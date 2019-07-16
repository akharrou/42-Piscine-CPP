/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:31:06 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 21:38:12 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main() {

	std::string		s = "HI THIS IS BRAIN";

	std::string		*sPtr = &s;
	std::string&	sRef = s;

	std::cout << *sPtr << std::endl << sRef << std::endl;

	return (0);
}
