
#include "../Includes/RType.class.hpp"
#include "../Includes/Spaceship.class.hpp"
#include "../Includes/Enemy.class.hpp"
#include "../Includes/EnemyA.class.hpp"

/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

RType::RType( void ) :
	AGame("RType") {
	initialize();
}

RType::RType( const RType & src ) {
	*this = src;
}

RType::~RType( void ) {}


/* OPERATOR OVERLOAD(S) - - - - - - - - - - - - - - - - - - - - - - - - - - */

RType &			RType::operator = ( const RType & rhs ) {
	if (this != &rhs)
	{
		m_GameState.tick = rhs.m_GameState.tick;
		m_mainScreen = rhs.m_mainScreen;
		m_gameScreen = rhs.m_gameScreen;
		m_infoScreen = rhs.m_infoScreen;
	}
	return (*this);
}


/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

int		RType::initialize  ( void )
{

    m_mainScreen.window = initscr();        /* NOTE : puts us in ncurses mode                          */
    start_color();               			/* NOTE : gives us ability to use curses color attributes  */

    cbreak();                    			/* NOTE : removes buffering                                */
    curs_set(0);                 			/* NOTE : makes the cursor invisible                       */
    noecho();                    			/* NOTE : doesn't print user input                         */
    nodelay(m_mainScreen.window, TRUE);     /* NOTE : getch becomes non-blocking (returns ERR)         */
    keypad(m_mainScreen.window, TRUE);      /* NOTE : enables special keys                             */

    clear();                     			/* NOTE : clears the screen                                */
    refresh();                   			/* NOTE : renders the screen                               */

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* Set Main Screen Dimensions */
	m_mainScreen.top = { 0, 0 };
	getmaxyx(m_mainScreen.window, m_mainScreen.bottom.y, m_mainScreen.bottom.x);

	/* Set Game Screen Dimensions */
	m_gameScreen.top = {
		(int_fast16_t)( m_mainScreen.top.x + 3 ),        /* BEGIN_X */
		(int_fast16_t)( m_mainScreen.top.y + 1 )         /* BEGIN_Y */
	};

	m_gameScreen.bottom = {
		(int_fast16_t)( m_mainScreen.bottom.x - 3    ),  /* END_X */
		(int_fast16_t)( m_mainScreen.bottom.y * 0.85 )   /* END_Y */
	};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* Set Info Screen Dimensions */
	m_infoScreen.top = {
		(int_fast16_t)(3),                               /* BEGIN_X */
		(int_fast16_t)(m_mainScreen.bottom.y * 0.85)     /* BEGIN_Y */
	};

	m_infoScreen.bottom = {
		(int_fast16_t)(m_mainScreen.bottom.x - 3),       /* END_X */
		(int_fast16_t)(m_mainScreen.bottom.y - 1)        /* END_Y */
	};

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* Setting Screen Color Pairs */
	init_pair( 1, COLOR_WHITE, COLOR_BLACK  );
	init_pair( 2, COLOR_RED,   COLOR_CYAN   );
	init_pair( 3, COLOR_BLUE,  COLOR_YELLOW );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* Create Game Window */
	m_gameScreen.window = newwin(

		m_gameScreen.bottom.y - m_gameScreen.top.y,  /* nlines   */
		m_gameScreen.bottom.x - m_gameScreen.top.x,  /* ncolumns */
		m_gameScreen.top.y,                          /* begin_y  */
		m_gameScreen.top.x                           /* begin_x  */
	);

	/* Set Game Window Settings */
	nodelay ( m_gameScreen.window, TRUE );
	keypad  ( m_gameScreen.window, TRUE );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* Create Info Window */
	m_infoScreen.window = newwin(

		m_infoScreen.bottom.y - m_infoScreen.top.y,
		m_infoScreen.bottom.x - m_infoScreen.top.x,
		m_infoScreen.top.y,
		m_infoScreen.top.x
	);

	/* Set Info Window Settings */
	nodelay ( m_infoScreen.window, TRUE );
	keypad  ( m_infoScreen.window, TRUE );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	// wbkgd( m_mainScreen.window, COLOR_PAIR(1) );
	// wbkgd( m_gameScreen.window, COLOR_PAIR(2) );
	// wbkgd( m_infoScreen.window, COLOR_PAIR(3) );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	m_GameState.score      = 0;
	m_GameState.tick       = 0;
	m_GameState.time_start = std::chrono::steady_clock::now();

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	bzero(m_GameState.pawns, sizeof(m_GameState.pawns));
	bzero(m_GameState.pawns, sizeof(m_GameState.pawns[ENEMIES]));

	m_GameState.pawns[SPACESHIPS][0] = new SpaceShip();
	// m_GameState.pawns[SPACESHIPS][0] = new SpaceShip( 3, 100, m_gameScreen );
	bzero(m_GameState.pawns[ENEMIES], sizeof(*m_GameState.pawns[ENEMIES]) * (100));

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		return (1);
}

void	RType::exit        ( void ) const {

	delete (m_GameState.pawns[SPACESHIPS][0]);
	// delete (m_GameState.pawns[ENEMIES][0]);

	endwin();
}

void	RType::updateGameState ( void ) {

	++m_GameState.tick;
	m_GameState.time_end = std::chrono::steady_clock::now();

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	/* GAME LOGIC */ {

		// for (int i = 0; i++)

		m_GameState.UserInput.character = wgetch(m_gameScreen.window);

		for ( int i = 0; i < 4; ++i )
		{
			for ( int j = 0; j < 100; ++j )
			{
				if (m_GameState.pawns[i][j] != NULL)
					m_GameState.pawns[i][j]->update( m_GameState, m_gameScreen );
			}
		}

		if (m_GameState.tick % 30 == 0)
		{
			for ( int j = 0; j < 100; ++j )
			{
				if (m_GameState.pawns[ENEMIES][j] == NULL)
				{
					m_GameState.pawns[ENEMIES][j] = new EnemyA();
					mvwprintw(m_gameScreen.window, j, 10, "Making enemies");
				}
			}
		}

	}

	// wrefresh( m_gameScreen.window );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	/* INFO LOGIC */ {

	}
}

void	RType::renderGameFrame ( void ) const
{
	werase( m_infoScreen.window );
	werase( m_gameScreen.window );

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	/* GAME SCREEN */ { box( m_gameScreen.window, 0, 0 );

		// mvwprintw(m_gameScreen.window, 10, 10, "Making enemies");

		for ( int i = 0; i < 4; ++i )
		{
			for ( int j = 0; j < 100; ++j )
			{
				if (m_GameState.pawns[i][j])
					m_GameState.pawns[i][j]->draw(m_gameScreen.window);
			}
		}

	}


	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	/* INFO SCREEN */ { box( m_infoScreen.window, 0, 0 );

		wattron(m_infoScreen.window, A_BOLD);

		mvwprintw( m_infoScreen.window,
					1, (m_infoScreen.bottom.x - m_infoScreen.top.x) * .01,
					"Score : %d", m_GameState.score
		);

		steady_clock_t::duration time_elapsed = m_GameState.time_end - m_GameState.time_start;
		double seconds = double(time_elapsed.count()) * steady_clock_t::period::num / steady_clock_t::period::den;

		mvwprintw( m_infoScreen.window,
					2, (m_infoScreen.bottom.x - m_infoScreen.top.x) * .01,
					"Time  : %.2f", seconds
		);

		mvwprintw( m_infoScreen.window,
					3, (m_infoScreen.bottom.x - m_infoScreen.top.x) * .01,
					"Lives : <O> <O> <O>"
		);

		wattroff(m_infoScreen.window, A_BOLD);
	}


	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	wrefresh( m_gameScreen.window );
	wrefresh( m_infoScreen.window );
}

void	RType::getUserInput    ( void )
{

}
