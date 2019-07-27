/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Graphical.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:38:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 16:48:26 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_GRAPICAL
# define GKRELLM_GRAPICAL

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define TOTAL_MODULES (4)

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class GKrellM_Graphical :
	public IMonitorDisplay {

	private:
		GKrellM_Graphical &  operator = ( const GKrellM_Graphical & rhs );

	private:
		IMonitorModule *_modules[TOTAL_MODULES];

	public:

		GKrellM_Graphical( void );
		GKrellM_Graphical( const GKrellM_Graphical & src );
		~GKrellM_Graphical( void );

		void	run           ();
		void	updateModules ();
		void	renderModules ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_GRAPICAL */
