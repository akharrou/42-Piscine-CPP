/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:34:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 23:08:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

# define __SUPERTRAP__ (0)

class SuperTrap
	: public NinjaTrap, public FragTrap {

	public:

		SuperTrap( void );
		SuperTrap( std::string name );
		SuperTrap( const SuperTrap & src );
		~SuperTrap( void );

		SuperTrap &		operator = ( const SuperTrap & rhs );

		void	featherAttack  ( std::string const & target ) const;
		void	rangedAttack   ( std::string const & target ) const;
		void	meleeAttack    ( std::string const & target ) const;
		void	stealthAttack  ( std::string const & target ) const;
		void	ultimateAttack ( std::string const & target ) const;

		std::string		getType() const;

};

std::ostream & operator << ( std::ostream & out, const SuperTrap & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* SUPERTRAP_HPP */
