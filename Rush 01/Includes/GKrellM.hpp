
#ifndef GKRELLM_HPP
# define GKRELLM_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <stdlib.h>
# include <unistd.h>
# include <ncurses.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <sys/syslimits.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysctl.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <iostream>
# include <fstream>
# include <sstream>
# include <thread>

# include <chrono>
# include <ctime>
# include <istream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <array>
# include <vector>
# include <deque>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct coordinate {
	int_fast16_t y;
	int_fast16_t x;
} coord_t;

typedef struct windowScreen {
	WINDOW *win;
	coord_t min;
	coord_t max;
} screen_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define ITALIC(str)     "\033[3m" str "\033[0m"
# define UNDERLINED(str) "\033[4m" str "\033[0m"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define CPU_USAGE_FILENAME           "/tmp/cpu_usage.txt"
# define RAM_USAGE_FILENAME           "/tmp/ram_usage.txt"
# define PROCESSES_ACTIVITY_FILENAME  "/tmp/processes_activity.txt"
# define NETWORK_ACTIVITY_FILENAME    "/tmp/newtork_activity.txt"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define EXIT(err_func)          \
	{                            \
        err_func;                \
		std::exit(EXIT_FAILURE); \
	}                            \

void usage(void);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* GKRELLM_HPP */
