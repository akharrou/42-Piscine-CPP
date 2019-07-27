/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:00:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 19:42:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <exception>
# include <queue>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef char Byte;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class MindOpen {

	public:

		struct AInstruction;
		struct Program;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		struct AInstruction {

			AInstruction() {};
			virtual ~AInstruction() {};

			virtual void execute( MindOpen::Program & ) const = 0;
		};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		struct Program {

			Program( std::string Filename );
			~Program();

			std::queue <AInstruction *> _instructionQueue;

			std::string	_filename;
			Byte *		_ptr;

			void execute();
		};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	private:
		std::vector <Program> _programs;

	public:

		MindOpen();
		~MindOpen();

		void	load       ( std::string Filename );
		void	execute    ( std::string Filename );
		void	executeAll ( void );

		struct FileNotFound :
			public std::exception {
				virtual const char * what () const throw();
		};

		struct InvalidFile :
			public std::exception {
				virtual const char * what () const throw();
		};

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct IncrementPointer :
	public MindOpen::AInstruction {

		IncrementPointer();
		~IncrementPointer();

		void execute( MindOpen::Program & ) const;
};

struct DecrementPointer :
	public MindOpen::AInstruction {

		DecrementPointer();
		~DecrementPointer();

		void execute( MindOpen::Program & ) const;
};

struct IncrementByte :
	public MindOpen::AInstruction {

		IncrementByte();
		~IncrementByte();

		void execute( MindOpen::Program & ) const;
};

struct DecrementByte :
	public MindOpen::AInstruction {

		DecrementByte();
		~DecrementByte();

		void execute( MindOpen::Program & ) const;
};

struct PrintByte :
	public MindOpen::AInstruction {

		PrintByte();
		~PrintByte();

		void execute( MindOpen::Program & ) const;
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MINDOPEN_HPP */
