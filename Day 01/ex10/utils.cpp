/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:34:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 10:10:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

static bool	isdir(char *file) {

	struct stat	filestat;

	if (stat(file, &filestat) == 0) {
		if( filestat.st_mode & S_IFDIR ) {
			return (true);
		}
	}
	return (false);
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void		catStream(std::istream & Stream) {
	std::cout << Stream.rdbuf();
}

void		catFile(char *file)
{
	std::ifstream	infile(file);

	if (infile.is_open()) {

		if (isdir(file)) {
			std::cout << "cat: " << file << ": "
					<< "Is a directory" << std::endl;
		} else {
			catStream(infile);
		}

	} else {
		std::cout << "cat: " << file << ": "
		          << strerror(errno) << std::endl;
	}
}

void		catFiles(char **av)
{
	if (av)
		while (*av != NULL)
			catFile(*av++);
}
