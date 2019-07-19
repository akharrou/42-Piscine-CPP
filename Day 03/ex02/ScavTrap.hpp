/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:40:20 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/18 16:44:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define NUMBER_OF_CHALLENGES (5)

class ScavTrap : public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap & src );
		~ScavTrap( void );

		ScavTrap &		operator = ( const ScavTrap & rhs );

		void			challengeNewcomer( std::string const & target ) const;

};

std::ostream & operator << ( std::ostream & out, const ScavTrap & in );

#endif /* SCAVTRAP_HPP */
