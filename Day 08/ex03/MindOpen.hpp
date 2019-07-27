/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:00:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 18:51:48 by akharrou         ###   ########.fr       */
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
			virtual ~AInstruction();
			virtual void execute( MindOpen::Program & ) const = 0;
		};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		struct Program {

			std::queue <AInstruction *> _instructionQueue;

			std::string			_sourceCode;
			std::string			_filename;
			Byte *				_ptr;
			size_t				_idx;

			Program( std::string Filename );
			~Program();

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
		void execute( MindOpen::Program & ) const;
};

struct DecrementPointer :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

struct IncrementByte :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

struct DecrementByte :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

struct PrintByte :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

struct GotoRightBracket :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

struct GotoLeftBracket :
	public MindOpen::AInstruction {
		void execute( MindOpen::Program & ) const;
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MINDOPEN_HPP */
