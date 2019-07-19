/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:48:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 20:35:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <typeinfo>
#include "ClapTrap.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class NinjaTrap : public virtual ClapTrap {

	public:

		NinjaTrap( void );
		NinjaTrap( std::string name );
		NinjaTrap( const NinjaTrap & src );
		virtual ~NinjaTrap( void );

		NinjaTrap &		operator = ( const NinjaTrap & rhs );

		std::string		getType() const;

		void	featherAttack  ( std::string const & target ) const;
		void	rangedAttack   ( std::string const & target ) const;
		void	meleeAttack    ( std::string const & target ) const;
		void	stealthAttack  ( std::string const & target ) const;
		void	ultimateAttack ( std::string const & target ) const;

		void	ninjaShoebox( ClapTrap & target );

};

std::ostream & operator << ( std::ostream & out, const NinjaTrap & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* NINJATRAP_HPP */
