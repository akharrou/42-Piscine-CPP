/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:29:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 14:07:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <string>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IMonitorModule {

	public:
		virtual ~IMonitorModule() {}

		virtual void update ()    = 0;
		virtual void render ()    = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* IMONITORMODULE_HPP */
