/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInstruction.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:00:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 13:23:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_CLASS_HPP
# define INSTRUCTION_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class AInstruction {

	protected:
		AInstruction( void );
		std::string _type;

	public:

		AInstruction( std::string type );
		AInstruction( const AInstruction & src );
		~AInstruction( void );

		AInstruction & operator = ( const AInstruction & rhs );

		std::string		getType() const;
		virtual void	execute() const = 0;

};

std::ostream & operator << ( std::ostream & out, const AInstruction & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IncrementPointer :
	public AInstruction {
		public: void execute() const;
};

class DecrementPointer :
	public AInstruction {
		public: void execute() const;
};

class IncrementByte :
	public AInstruction {
		public: void execute() const;
};

class DecrementByte :
	public AInstruction {
		public: void execute() const;
};

class PrintByte :
	public AInstruction {
		public: void execute() const;
};

class GotoRightBracket :
	public AInstruction {
		public: void execute() const;
};

class GotoLeftBracket :
	public AInstruction {
		public: void execute() const;
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* INSTRUCTION_CLASS_HPP */
