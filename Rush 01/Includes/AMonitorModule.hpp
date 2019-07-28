/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:29:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:26:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORMODULE_HPP
# define AMONITORMODULE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "GKrellM.hpp"
# include "IMonitorModule.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct AMonitorModule :
	public IMonitorModule {

	private:
		AMonitorModule();
		AMonitorModule( const AMonitorModule & src );
		AMonitorModule &  operator = ( const AMonitorModule & rhs );

	public:
		AMonitorModule( screen_t );
		virtual ~AMonitorModule ();

		std::string name;
		screen_t win;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AMONITORMODULE_HPP */
