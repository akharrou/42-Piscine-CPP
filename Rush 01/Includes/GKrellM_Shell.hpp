/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:41:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:40:47 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_SHELL_HPP
# define GKRELLM_SHELL_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"
# include "GKrellM_Modules.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "AMonitorDisplay.hpp"
# include "AMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class GKrellM_Shell :
	public AMonitorDisplay {

	private:
		std::deque <AMonitorModule *> _modules;

	public:

		GKrellM_Shell( void );
		~GKrellM_Shell( void );

		void	run           ();
		void	updateModules ();
		void	renderModules ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_SHELL_HPP */
