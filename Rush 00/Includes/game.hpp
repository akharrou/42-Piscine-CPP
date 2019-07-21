
#ifndef GAME_H
# define GAME_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <iostream>
# include <string>
# include <ncurses.h>
# include <unistd.h>


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define WIN_WIDTH 50
# define WIN_HEIGHT 50

# define COLOR_GOLD 8


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** STRUCTS
*/

typedef struct
{
	uint_fast8_t x;
	uint_fast8_t y;
} vec2ui;

typedef struct
{
	int_fast8_t x;
	int_fast8_t y;
} vec2i;

typedef struct {
	vec2i pos;
	char disp_char;
} player_t;


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: main.cpp
*/

int		init(void);
void	run(void);
void	close(void);

#endif
