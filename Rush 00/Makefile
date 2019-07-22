
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   clang++ -std=c++2a
CFLAGS      =   -W -Wall -Wextra -Werror -pedantic -lncurses $(DEBUG_FLAGS)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OPTIM_FLAGS = -O3 -march=native                                               \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEBUG_FLAGS = -O0 -g                                                          \
                                                                              \
              -fsanitize=address                                              \
              -fsanitize=undefined                                            \
            #   -fsanitize=bounds                                               \
            #   -fsanitize=nullability-arg                                      \
            #   -fsanitize=nullability-return                                   \
            #   -fsanitize=nullability-assign                                   \
            #   -fsanitize-address-use-after-scope                              \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =                                                                 \
                Includes/AGame.class.hpp                                      \
                Includes/RType.class.hpp                                      \
                Includes/APawn.class.hpp                                      \
                Includes/Spaceship.class.hpp                                  \
                Includes/EnemyA.class.hpp                                     \
                Includes/Enemy.class.hpp                                      \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =                                                                 \
                Sources/main.cpp                                              \
                                                                              \
                Sources/AGame.class.cpp                                       \
                Sources/RType.class.cpp                                       \
                Sources/APawn.class.cpp                                       \
                Sources/SpaceShip.class.cpp                                   \
                Sources/EnemyA.class.cpp                                      \
                Sources/Enemy.class.cpp                                       \

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

run:
	@./$(NAME)

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

.PHONY: all clean fclean re

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
