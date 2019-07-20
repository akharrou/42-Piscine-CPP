/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 21:35:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 11:28:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>
#include "ICharacter.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class ICharacter;
class AMateria {

	private:
		unsigned int	xp_;
		std::string		type_;

	protected:
		AMateria( void );

	public:
		AMateria( const std::string & type );
		AMateria( const AMateria & src );
		virtual ~AMateria( void );

		AMateria &		operator = ( const AMateria & rhs );

		const std::string &	getType () const;
		unsigned int		getXP   () const;

		void				setXP ( unsigned int xp );

		virtual AMateria	*clone() const = 0;
		virtual void		use( ICharacter & target );

};

std::ostream & operator << ( std::ostream & out, const AMateria & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* AMATERIA_HPP */
