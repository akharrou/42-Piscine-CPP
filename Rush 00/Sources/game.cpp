
#include "../Includes/game.hpp"
#include "../Includes/ObjectField.hpp"


int		init(void)
{
	g_window = initscr();        /* NOTE: puts us in ncurses mode                          */
	start_color();               /* NOTE: gives us ability to use curses color attributes  */

	cbreak();                    /* NOTE: removes buffering                                */
	keypad(g_window, TRUE);      /* NOTE: enables special keys                             */
	curs_set(0);                 /* NOTE: makes the cursor invisible                       */
	noecho();                    /* NOTE: doesn't print user input                         */
	nodelay(g_window, TRUE);     /* NOTE: getch becomes non-blocking (returns ERR)         */

	clear();                     /* NOTE: clears the screen                                */
	refresh();                   /* NOTE: renders the screen                               */

/*
	// init_color(9, 523, 273, 900);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	attron(A_BOLD);
    wbkgd(g_window, COLOR_PAIR(1));
*/

	/* Gets Window Boundaries */
	getmaxyx(g_window, g_yMax, g_xMax);

	/* Draw a Box Around the Window */
	box(g_window, 0, 0);

	return (0);
}

void run(void)
{
	move(5, 5);

	player_t player1;

	player1.disp_char = '@';
	player1.pos.x = 10;
	player1.pos.y = 5;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	bool exit_requested = false;
    int in_char;

    // get window boundaries
    getmaxyx(g_window, g_yMax, g_xMax);

    //initialize our rect with 0 offset
	game_area = {{0, 0}, {g_xMax, g_yMax}};

	//set our star bounds
    stars.setBounds(game_area);

	int tick = 0;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	while(1) /* GAME LOOP */
	{


	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

}

void close(void) {
	endwin();
}
