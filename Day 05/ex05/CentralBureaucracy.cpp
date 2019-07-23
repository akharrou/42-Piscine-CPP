/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:22:57 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 11:41:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

CentralBureaucracy::CentralBureaucracy( void ) {

	for ( int i = 0; i < _maxOfficeBlocks; ++i )
		_OfficeBlocks[i] = new OfficeBlock;
	for ( int i = 0; i < _maxTodos; ++i )
		_TodoList[i] = NULL;
	for ( int i = 0; i < _maxWaitingRoomCapacity; ++i )
		_WaitingBureaucrats[i] = NULL;
}

CentralBureaucracy::CentralBureaucracy( const CentralBureaucracy & src ) {
	*this = src;
}

CentralBureaucracy::~CentralBureaucracy( void ) {

	for ( int i = 0; i < _maxOfficeBlocks; ++i ) {
		if (_OfficeBlocks[i] != NULL) {
			delete _OfficeBlocks[i];
		}
	}
	for ( int i = 0; i < _maxTodos; ++i ) {
		if (_TodoList[i] != NULL)
			delete _TodoList[i];
	}
}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

CentralBureaucracy &	CentralBureaucracy::operator = ( const CentralBureaucracy & rhs ) {

	if (this != &rhs) {

		for ( int i = 0; i < _maxOfficeBlocks; ++i ) {

			if (_OfficeBlocks[i] != NULL)
				delete _OfficeBlocks[i];
			_OfficeBlocks[i] = rhs._OfficeBlocks[i];
		}
		for ( int i = 0; i < _maxTodos; ++i ) {

			if (_TodoList[i] != NULL)
				delete _TodoList[i];
			_TodoList[i] = rhs._TodoList[i];
		}
		for ( int i = 0; i < _maxWaitingRoomCapacity; ++i )
			_WaitingBureaucrats[i] = rhs._WaitingBureaucrats[i];
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

bool	CentralBureaucracy::recruitBureaucrat( Bureaucrat *recruit ) {

	Bureaucrat *chosen = NULL;
	int j = 0;

	for (int i = 0; i < _maxOfficeBlocks; ++i) {

		if ( _OfficeBlocks[i]->isActive() == false ) {

			/* Choose From Waiting Room */
			for (; j < _maxWaitingRoomCapacity; ++j) {

				if (_WaitingBureaucrats[j] != NULL) {
					chosen = _WaitingBureaucrats[j];
				}
			}

			/* Else Choose Recruit */
			if (j == _maxWaitingRoomCapacity)
				chosen = recruit;

			/* No Waiting Bureaucrats & Recruit points to NULL */
			if (chosen == NULL)
				return (false) ;

			/* Place in an Office Seat */
			if (_OfficeBlocks[i]->getIntern() == NULL) {
				_OfficeBlocks[i]->setIntern( new Intern );
			}
			if (_OfficeBlocks[i]->getSigningBureaucrat() == NULL) {
				_OfficeBlocks[i]->setSigningBureaucrat( chosen );
				if (j != _maxWaitingRoomCapacity)
					_WaitingBureaucrats[j++] = NULL;
				else
					return (true);
			}
			else if (_OfficeBlocks[i]->getExecutingBureaucrat() == NULL) {
				_OfficeBlocks[i]->setExecutingBureaucrat( chosen );
				if (j != _maxWaitingRoomCapacity)
					_WaitingBureaucrats[j++] = NULL;
				else
					return (true);
			}
		}
	}

	/* Else Place Recruit in Waiting List */
	for ( int i = 0; i < _maxWaitingRoomCapacity; ++i ) {

		if (_WaitingBureaucrats[i] == NULL) {
			_WaitingBureaucrats[i] = recruit;
			return (true);
		}
	}

	return (false);
}

bool	CentralBureaucracy::queueUp( std::string formName, std::string formTarget ) {

	for (int i = 0; i < _maxTodos; ++i) {

		if ( _TodoList[i] == NULL ) {

			todo_t *newTodo = new todo_t;

			((*newTodo) = { formName, formTarget });
			_TodoList[i] = newTodo;

			return (true);
		}
	}
	return (false);
}

void	CentralBureaucracy::doBureaucracy() {

	int i = 0;

	for ( int j = 0; j < _maxTodos; ++j ) {

		if ( _TodoList[j] != NULL ) {
			if (_OfficeBlocks[i % _maxOfficeBlocks]->isActive()) {

				_OfficeBlocks[i % _maxOfficeBlocks]->doBureaucracy(
						_TodoList[j]->formName,
						_TodoList[j]->formTarget
				);
				++i;
			}
		}
	}
}
