
#ifndef GAME_HPP
# define GAME_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <unistd.h>
# include <ncurses.h>

# include <iostream>
# include <cstdint>
# include <string>
# include <chrono>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef std::chrono::time_point<std::chrono::steady_clock> chrono_t;
typedef std::chrono::steady_clock						   steady_clock_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct s_int_coord_tinate{
	int_fast16_t x;
	int_fast16_t y;
} coord_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct s_ncurses_window
{
	WINDOW	*window;
	coord_t	top;
	coord_t	bottom;
}	screen_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct {
	coord_t	relativecoord_t;
	int		symbol;
} hitBoxUnit_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class APawn;
typedef struct {

	struct {
		int	character;
	} UserInput;

	chrono_t	time_start;
	chrono_t	time_end;

	int			score;
	int			tick;

	APawn		*pawns[4][100];

} state_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif
