/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:48:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 18:51:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#include <typeinfo>
#include "ClapTrap.hpp"

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class NinjaTrap : public ClapTrap {

	public:

		NinjaTrap( void );
		NinjaTrap( std::string name );
		NinjaTrap( const NinjaTrap & src );
		virtual ~NinjaTrap( void );

		NinjaTrap &		operator = ( const NinjaTrap & rhs );

		std::string		getType() const;

		virtual void	featherAttack  ( std::string const & target ) const;
		virtual void	rangedAttack   ( std::string const & target ) const;
		virtual void	meleeAttack    ( std::string const & target ) const;
		virtual void	stealthAttack  ( std::string const & target ) const;
		virtual void	ultimateAttack ( std::string const & target ) const;

		void			ninjaShoebox( ClapTrap & target );

};

std::ostream & operator << ( std::ostream & out, const NinjaTrap & in );

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

#endif /* NINJATRAP_HPP */
