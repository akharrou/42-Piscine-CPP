/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:07:03 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 14:35:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class MateriaSource
	: public IMateriaSource {

	private:
		static const int	_maxLearnedMaterias = 4;
		AMateria			*_learnedMaterias[_maxLearnedMaterias];

	public:

		MateriaSource( void );
		MateriaSource( const MateriaSource & src );
		~MateriaSource( void );

		MateriaSource &		operator = ( const MateriaSource & rhs );

		void		learnMateria   ( AMateria *m );
		AMateria	*createMateria ( const std::string & type );

};

std::ostream & operator << ( std::ostream & out, const MateriaSource & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MATERIASOURCE_HPP */
