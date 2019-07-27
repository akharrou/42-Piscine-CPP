/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:00:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 18:16:35 by akharrou         ###   ########.fr       */
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

class AInstruction;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class MindOpen {

	public:

		struct Program {

			std::queue <AInstruction *> _instructionQueue;

			std::string			_sourceCode;
			std::string			_filename;
			Byte *				_ptr;
			size_t				_idx;

			Program( std::string Filename );
			~Program();

			void execute( MindOpen::Program );

		};

		class AInstruction {

			public:

				AInstruction( void );
				AInstruction( const AInstruction & src );
				virtual ~AInstruction( void );

				AInstruction &	operator = ( const AInstruction & rhs );

				virtual void	execute( Program & ) const = 0;

		};

	private:

		std::vector <Program> _programs;

	public:

		MindOpen(void);
		~MindOpen(void);

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

std::ostream & operator << ( std::ostream & out, const MindOpen::AInstruction & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class IncrementPointer :
	public MindOpen::AInstruction {

		public:
			IncrementPointer();
			~IncrementPointer();

			void execute( MindOpen::Program & ) const;
};

class DecrementPointer :
	public MindOpen::AInstruction {

		public:
			DecrementPointer();
			~DecrementPointer();

			void execute( MindOpen::Program & ) const;
};

class IncrementByte :
	public MindOpen::AInstruction {

		public:
			IncrementByte();
			~IncrementByte();

			void execute( MindOpen::Program & ) const;
};

class DecrementByte :
	public MindOpen::AInstruction {

		public:
			DecrementByte();
			~DecrementByte();

			void execute( MindOpen::Program & ) const;
};

class PrintByte :
	public MindOpen::AInstruction {

		public:
			PrintByte();
			~PrintByte();

			void execute( MindOpen::Program & ) const;
};

class GotoRightBracket :
	public MindOpen::AInstruction {

		public:
			GotoRightBracket();
			~GotoRightBracket();

			void execute( MindOpen::Program & ) const;
};

class GotoLeftBracket :
	public MindOpen::AInstruction {

		public:
			GotoLeftBracket();
			~GotoLeftBracket();

			void execute( MindOpen::Program & ) const;
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MINDOPEN_HPP */
