/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:29:10 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 17:49:05 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <iostream>
#include "ISpaceMarine.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class AssaultTerminator
	: public ISpaceMarine {

	public:

		AssaultTerminator( void );
		AssaultTerminator( const AssaultTerminator & src );
		~AssaultTerminator( void );

		AssaultTerminator &		operator = ( const AssaultTerminator & rhs );

		ISpaceMarine	*clone () const;

		void	battleCry      () const;
		void	rangedAttack   () const;
		void	meleeAttack    () const;

};

std::ostream & operator << ( std::ostream & out, const AssaultTerminator & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* ASSAULTTERMINATOR_HPP */
