/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:56:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/19 19:53:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR — — — — — — — — — — — — — — — — — — — — */

Squad::Squad( void ) :
	_squad(NULL),
	_squad_count(0) {
}

Squad::Squad( const Squad & src ) {
	*this = src;
}

Squad::~Squad( void ) {

	unit_t	*probe;
	unit_t	*tmp;

	probe = _squad;
	while (probe) {

		tmp = probe;
		probe = probe->next;
		delete (tmp->unit);
		delete (tmp);
	}
}


/* OPERATOR OVERLOAD(S) — — — — — — — — — — — — — — — — — — — — — — — — — — */

Squad &			Squad::operator = ( const Squad & rhs ) { /* FIXME : assignation isnt deep */

	if (this != &rhs) {

		unit_t	*probe;
		unit_t	*tmp;

		if (_squad != NULL) {

			probe = _squad;
			while (probe) {
				tmp = probe;
				probe = probe->next;
				delete (tmp->unit);
				delete (tmp);
			}
		}
		if (rhs._squad == NULL) {
			_squad = NULL;
		} else {
			probe = rhs._squad;
			while (probe) {
				this->push(probe->unit->clone());
				probe = probe->next;
			}
		}
		_squad_count = rhs._squad_count;
	}
	return (*this);
}

std::ostream &		operator << ( std::ostream& out, const Squad & in ) {

	out << "SpaceMarine Squad of " << in.getCount() << " units !" << std::endl;
	return (out);
}


/* ACCESSOR(S) — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int				Squad::getCount() const {
	return (_squad_count);
}

ISpaceMarine	*Squad::getUnit( int N ) const {

	if (!_squad)
		return (0);

	unit_t	*probe;
	int		i;

	i = 0;
	probe = _squad;
	while (probe && i < _squad_count)
	{
		if (i == N)
			return (probe->unit);
		probe = probe->next;
		++i;
	}
	return (NULL);
}


/* PUBLIC MEMBER FUNCTION(S) — — — — — — — — — — — — — — — — — — — — — — — — */

int		Squad::push( ISpaceMarine *obj ) {

	unit_t	*newUnit = new unit_t;
	unit_t	*probe   = _squad;

	newUnit->unit = obj;
	newUnit->next = NULL;

	if (_squad) {

		probe = _squad;
		while (probe->next)
			probe = probe->next;

		probe->next = newUnit;

	} else {
		_squad = newUnit;
	}

	return (++_squad_count);
}
