/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:23:34 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/20 11:49:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

MateriaSource::MateriaSource( void ) {
	for (int i = 0; i < _maxLearnedMaterias; ++i)
		_learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src ) {
	*this = src;
}

MateriaSource::~MateriaSource( void ) { }


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

MateriaSource &			MateriaSource::operator = ( const MateriaSource & rhs ) {

	if (this != &rhs) {

		for (int i = 0; i < _maxLearnedMaterias; ++i) {

			if (_learnedMaterias[i] != NULL)
				delete (_learnedMaterias[i]);
			_learnedMaterias[i] = rhs._learnedMaterias[i]->clone();
		}
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const MateriaSource & in ) {

	(void)in;
	out << "<MateriaSource>" << std::endl;
	return (out);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void		MateriaSource::learnMateria( AMateria *m ) {

	if (!m)
		return ;

	for (int i = 0; i < _maxLearnedMaterias; ++i) {

		if (_learnedMaterias[i] == NULL) {
			_learnedMaterias[i] = m;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria( const std::string & type ) {

	for (int i = 0; i < _maxLearnedMaterias; ++i) {

		if (_learnedMaterias[i] != NULL)
			if (_learnedMaterias[i]->getType() == type)
				return (_learnedMaterias[i]->clone());
	}
	return (0);
}
