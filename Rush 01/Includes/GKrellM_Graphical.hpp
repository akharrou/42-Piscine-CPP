/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Graphical.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:38:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:41:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_GRAPICAL
# define GKRELLM_GRAPICAL

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AMonitorDisplay.hpp"
# include "AMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define TOTAL_MODULES (4)

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class GKrellM_Graphical :
	public AMonitorDisplay {

	private:
		std::deque <AMonitorModule *> _modules;

	public:

		GKrellM_Graphical( void );
		~GKrellM_Graphical( void );

		void	run           ();
		void	updateModules ();
		void	renderModules ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_GRAPICAL */
