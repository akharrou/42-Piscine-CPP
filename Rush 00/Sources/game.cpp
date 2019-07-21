
#include "../Includes/game.hpp"

WINDOW* wnd;

int		init(void)
{
	wnd = initscr();     /* NOTE: puts us in ncurses mode                  */
	start_color();       /* NOTE: gives us ability to use curses color attributes*/

	cbreak();            /* NOTE: removes buffering                        */
	keypad(wnd, TRUE);   /* NOTE: enables special keys                     */
	curs_set(0);         /* NOTE: makes the cursor invisible               */
	noecho();            /* NOTE: doesn't print user input                 */
	nodelay(wnd, TRUE);  /* NOTE: getch becomes non-blocking (returns ERR) */

	clear();             /* NOTE: clears the screen                        */
	refresh();           /* NOTE: renders the screen                       */

	// init_color(9, 523, 273, 900);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	attron(A_BOLD);
    wbkgd(wnd, COLOR_PAIR(1));

	box(wnd, 0, 0);
	return (0);
}

void run(void)
{
	move(5, 5);

	player_t player1;

	player1.disp_char = '@';
	player1.pos.x = 10;
	player1.pos.y = 5;

	bool exit_requested = false;
    int in_char;

	while(1)
	{ /* GAME LOOP */
		in_char = wgetch(wnd);

		mvaddch(player1.pos.y, player1.pos.x, ' ');
		switch(in_char)
		{
			case 'q':
				exit_requested = true;
				break;

			case KEY_UP:
			case 'w':
				player1.pos.y -= 1;
				break;

			case KEY_DOWN:
			case 's':
				player1.pos.y += 1;
				break;

			case KEY_LEFT:
			case 'a':
				player1.pos.x -= 1;
				break;

			case KEY_RIGHT:
			case 'd':
				player1.pos.x += 1;
				break;

			default:
				break;
		}

        mvaddch(player1.pos.y, player1.pos.x, player1.disp_char);
        refresh();

        if (exit_requested)
			break;
    }

}

void close(void) {
	endwin();
}
