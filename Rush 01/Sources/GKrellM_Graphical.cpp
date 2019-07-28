/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Graphical.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:38:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:44:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/GKrellM_Graphical.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

GKrellM_Graphical::GKrellM_Graphical( void ) {

	(void)_modules;
	/* init graphical mode */
	/* init graphical window(s) */
}

GKrellM_Graphical::~GKrellM_Graphical( void ) {

	/* exit graphical mode */
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	GKrellM_Graphical::run() {
	std::cout << "GKrellM Graphical Run" << std::endl;
}

void	GKrellM_Graphical::updateModules() {

}

void	GKrellM_Graphical::renderModules() {

}


/* EXCEPTION(S) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
