
#ifndef SERVER_HPP
# define SERVER_HPP

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define MAX_CONNECTIONS 5
# define LOCAL_HOST "127.0.0.1"
# define END_OF_COMMUNICATION (strcmp(buf, END_MSG) == 0 || buf[0] == '\n')

# define SERVER_PORT 18000
# define SERVER_IP LOCAL_HOST
# define END_MSG "exit\n"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# define STDIN 0
# define BUFF_SIZE 1024
# define CHECK(expr) if ((expr) == -1) { perror(NULL); exit(EXIT_FAILURE); }

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* SERVER_HPP */
