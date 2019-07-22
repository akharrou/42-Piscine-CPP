

#ifndef APAWN_CLASS_HPP
# define APAWN_CLASS_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "Game.hpp"
# include "AGame.class.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class APawn {

	private:
		std::string		m_type;

	protected:
		APawn( void );

		int_fast16_t	m_width;
		int_fast16_t	m_height;

		hitBoxUnit_t	*m_hitBox;
		coord_t			m_location;

	public:
		APawn( std::string type );
		APawn( std::string type , int width, int height );
		APawn( std::string type , coord_t location );
		APawn( const APawn & src );
		virtual ~APawn( void ) = 0;

		APawn &		operator = ( const APawn & rhs );

		std::string		getType() 	const;
		int				getHeight() const;
		int				getWidth()	const;

		void			draw      ( WINDOW *win ) const;
		// virtual bool	colliding ( state_t & )            = 0;
		// virtual bool	colliding ( state_t & )            = 0;
		virtual void	update    ( state_t & , screen_t ) = 0;
};

std::ostream & operator << ( std::ostream & out, const APawn & in );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* APAWN_CLASS_HPP */
