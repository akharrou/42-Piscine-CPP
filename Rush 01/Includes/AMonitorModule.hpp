/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:29:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 17:29:45 by akharrou         ###   ########.fr       */
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
		screen_t screen;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AMONITORMODULE_HPP */
