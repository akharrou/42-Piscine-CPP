/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:00:33 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 16:52:32 by akharrou         ###   ########.fr       */
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

		class AInstruction {

			protected:
				AInstruction( void );
				std::string _type;

			public:

				AInstruction( std::string type );
				AInstruction( const AInstruction & src );
				virtual ~AInstruction( void );

				AInstruction &	operator = ( const AInstruction & rhs );

				std::string		getType() const;

				virtual void	execute( Byte * )                           const = 0;
				virtual void	execute( std::string Source, size_t & idx ) const = 0;

		};

		struct Program {

			std::queue <AInstruction *> _instructionQueue;

			std::string			_sourceCode;
			std::string			_filename;
			std::deque<Byte>	_memory;
			size_t				_idx;

			Program( std::string Filename );
			~Program();

			void execute();

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

		private:
			Byte * _byte;

		public:
			IncrementPointer();
			~IncrementPointer();

			void execute();
};

class DecrementPointer :
	public MindOpen::AInstruction {

		private:
			Byte * _byte;

		public:
			DecrementPointer();
			~DecrementPointer();

			void execute();
};

class IncrementByte :
	public MindOpen::AInstruction {

		private:
			Byte * _byte;

		public:
			IncrementByte();
			~IncrementByte();

			void execute();
};

class DecrementByte :
	public MindOpen::AInstruction {

		private:
			Byte * _byte;

		public:
			DecrementByte();
			~DecrementByte();

			void execute();
};

class PrintByte :
	public MindOpen::AInstruction {

		private:
			Byte * _byte;

		public:
			PrintByte();
			~PrintByte();

			void execute();
};

class GotoRightBracket :
	public MindOpen::AInstruction {

		public:
			GotoRightBracket();
			~GotoRightBracket();

			void execute( std::string Source, size_t & idx ) const;
};

class GotoLeftBracket :
	public MindOpen::AInstruction {

		public:
			GotoLeftBracket();
			~GotoLeftBracket();

			void execute( std::string Source, size_t & idx ) const;
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* MINDOPEN_HPP */
