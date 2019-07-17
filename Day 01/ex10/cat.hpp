/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cato9tails.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:16:51 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/17 10:09:38 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATO9TAILS_HPP
# define CATO9TAILS_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>

#include <sys/stat.h>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void	catStream( std::istream & Stream );
void	catFile( std::string file );
void	catFiles( char **av );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* CATO9TAILS_HPP */
