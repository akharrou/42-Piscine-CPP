/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:35:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/28 16:35:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORDISPLAY_HPP
# define AMONITORDISPLAY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "IMonitorDisplay.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct AMonitorDisplay :
	public IMonitorDisplay {

	private:
		AMonitorDisplay( const AMonitorDisplay & src );
		AMonitorDisplay &  operator = ( const AMonitorDisplay & rhs );

	public:
		AMonitorDisplay( void );
		virtual ~AMonitorDisplay ();

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AMONITORDISPLAY_HPP */
