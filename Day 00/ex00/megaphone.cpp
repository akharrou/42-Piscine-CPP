/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymenkh <aymenkh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 21:20:01 by aymenkh           #+#    #+#             */
/*   Updated: 2019/06/29 22:03:42 by aymenkh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      Displays to stdout command the command line arguments
**      passed in uppercase.
*/

#include <iostream>

int		main(int ac, char *av[])
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			for (size_t j = 0; j < strlen(av[i]); ++j)
			{
				av[i][j] = toupper(av[i][j]);
			}
			std::cout << av[i];
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
