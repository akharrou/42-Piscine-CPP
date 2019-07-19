/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:54 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 17:38:34 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

# define NUMBER_OF_ATTACKS (5)

class FragTrap : public ClapTrap {

	public:

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap & src );
		~FragTrap( void );

		FragTrap &		operator = ( const FragTrap & rhs );

		void			featherAttack  ( std::string const & target ) const;
		void			rangedAttack   ( std::string const & target ) const;
		void			meleeAttack    ( std::string const & target ) const;
		void			stealthAttack  ( std::string const & target ) const;
		void			ultimateAttack ( std::string const & target ) const;

		void			vaulthunter_dot_exe( std::string const & target );

};

std::ostream & operator << ( std::ostream & out, const FragTrap & in );

#endif /* FRAGTRAP_HPP */
