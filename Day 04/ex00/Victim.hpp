/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:19:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 09:59:04 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <string>
#include <iostream>

class Victim {

	protected:

		Victim( void );

		std::string	_name;

	public:

		Victim( std::string name );
		Victim( const Victim & src );
		virtual ~Victim( void );

		Victim &		operator = ( const Victim & rhs );

		std::string		getName() const;

		virtual void	getPolymorphed() const;

};

std::ostream & operator << ( std::ostream & out, const Victim & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* VICTIM_HPP */
