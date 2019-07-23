/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:39:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/23 11:25:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "OfficeBlock.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct {
	std::string	formName;
	std::string	formTarget;
} todo_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class CentralBureaucracy {

	private:

		static const int _maxOfficeBlocks = 20;
		OfficeBlock *_OfficeBlocks[_maxOfficeBlocks];

		static const int _maxTodos = 50;
		todo_t *_TodoList[_maxTodos];

		static const int _maxWaitingRoomCapacity = 100;
		Bureaucrat *_WaitingBureaucrats[_maxWaitingRoomCapacity];

	public:

		CentralBureaucracy( void );
		CentralBureaucracy( const CentralBureaucracy & src );
		~CentralBureaucracy( void );

		CentralBureaucracy &	operator = ( const CentralBureaucracy & rhs );

		void	doBureaucracy();
		bool	recruitBureaucrat( Bureaucrat * );
		bool	queueUp( std::string formName, std::string formTarget );

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* CENTRALBUREAUCRACY_HPP */
