/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:01:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 14:35:37 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class Character
	: public ICharacter {

	private:
		Character( void );
		std::string	_name;

		static const int	_max_inventory = 4;

		AMateria	*inventory[_max_inventory];

	public:
		Character( std::string name );
		Character( const Character & src );
		~Character( void );

		Character &		operator = ( const Character & rhs );

		const std::string &		getName() const;

		void	equip   ( AMateria *m );
		void	unequip ( int idx );
		void	use     ( int idx, ICharacter & target );

};

std::ostream & operator << ( std::ostream & out, const Character & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* CHARACTER_HPP */
