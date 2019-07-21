
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   clang++
CFLAGS      =   -W -Wall -Wextra -Werror -pedantic -lncurses -std=c++98

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OPTIM_FLAGS = -O3 -march=native                                               \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEBUG_FLAGS = -O0 -g                                                          \
                                                                              \
              -fsanitize=address                                              \
              -fsanitize=undefined                                            \
              -fsanitize=bounds                                               \
              -fsanitize=nullability-arg                                      \
              -fsanitize=nullability-return                                   \
              -fsanitize=nullability-assign                                   \
              -fsanitize-address-use-after-scope                              \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

FILES     =   \
        main.cpp \
        game.cpp \

SOURCES = $(addprefix Sources/, $(FILES))

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.c=.o)

# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo && echo $(GREEN) "[√]     [$(NAME) Successfully Compiled!]"
	@echo $(WHITE)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -pipe -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na correction

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
