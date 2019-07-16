/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:17:35 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/16 15:23:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  PROGRAM
**      Outputs a new file in which all occurences of s1 have been
**      replaced with s2 in the file given as input.
*/

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

#include <iostream>
#include <fstream>
#include <string>

#define UNDERLINED(str) ("\033[4m" str "\033[0m")

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —  */

int		main(int ac, char **av) {

	if (ac < 4) {
		std::cout << "Usage: ./replace "
		          << UNDERLINED("filename") << " "
		          << UNDERLINED("string1")  << " "
		          << UNDERLINED("string2")  << std::endl;
		return (1);
	}

	std::ifstream	instream(av[1]);
	std::ofstream	outstream(std::string(av[1]) + ".replace");

	std::string		s1(av[2]);
	std::string		s2(av[3]);

	if (instream.is_open()) {
		if (outstream.is_open()) {

			std::string	line;
			size_t		cur;
			size_t		occ;

			while (std::getline(instream, line))
			{
				cur = 0;
				do {
					occ = line.find(s1, cur);
					if (occ != std::string::npos)
						line.erase(occ, s1.length()).insert(occ, s2);
					cur = occ;
				} while (occ != std::string::npos);
				outstream << line << '\n';
			}

			outstream.close();
		}
		instream.close();
	}

	return (0);
}
