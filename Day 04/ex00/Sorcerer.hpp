/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:21:21 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 09:41:41 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {

	private:

		Sorcerer( void );

		std::string	_name;
		std::string _title;

	public:

		Sorcerer( std::string name, std::string title );
		Sorcerer( const Sorcerer & src );
		~Sorcerer( void );

		Sorcerer &		operator = ( const Sorcerer & rhs );

		std::string		getName  () const;
		std::string		getTitle () const;

		void	polymorph( const Victim & target ) const;

};

std::ostream & operator << ( std::ostream & out, const Sorcerer & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SORCERER_HPP */
