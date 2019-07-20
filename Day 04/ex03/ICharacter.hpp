/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:54:38 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 11:28:11 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AMateria;
class ICharacter {

	public:
		virtual ~ICharacter() {}

		virtual const std::string &		getName() const        = 0;

		virtual void equip   ( AMateria *m )                   = 0;
		virtual void unequip ( int idx )                       = 0;
		virtual void use     ( int idx, ICharacter & target )  = 0;

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* ICHARACTER_HPP */
