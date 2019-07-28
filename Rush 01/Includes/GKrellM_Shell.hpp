/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM_Shell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:41:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 13:59:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_SHELL_HPP
# define GKRELLM_SHELL_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM_Modules.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class GKrellM_Shell :
	public IMonitorDisplay {

	private:
		GKrellM_Shell( const GKrellM_Shell & src );
		GKrellM_Shell &  operator = ( const GKrellM_Shell & rhs );

		std::deque <IMonitorModule *> _modules;

	public:

		GKrellM_Shell( void );
		~GKrellM_Shell( void );

		void	run           ();
		void	updateModules ();
		void	renderModules ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_SHELL_HPP */
