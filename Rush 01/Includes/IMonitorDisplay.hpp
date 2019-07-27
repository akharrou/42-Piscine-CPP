/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:29:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/27 13:38:27 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IMonitorDisplay {

	public:
		virtual void	run           ()       = 0;
		virtual void	initDisplay   ()       = 0;
		virtual void	updateModules ()       = 0;
		virtual void	renderModules () const = 0;
		virtual void	exit          ()       = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* IMONITORDISPLAY_HPP */
