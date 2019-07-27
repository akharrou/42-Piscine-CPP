# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 12:26:27 by akharrou          #+#    #+#              #
#    Updated: 2019/07/26 19:05:59 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   clang++ -std=c++2a
CFLAGS      =   -W -Wall -Wextra -Werror $(DEBUG_FLAGS)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OPTIM_FLAGS = -O3 -march=native                                               \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEBUG_FLAGS =   -O0 -g                                                        \
                                                                              \
                -fsanitize=address                                            \
                -fsanitize=undefined                                          \
                # -fsanitize=bounds                                           \
                # -fsanitize=nullability-arg                                  \
                # -fsanitize=nullability-return                               \
                # -fsanitize=nullability-assign                               \
                # -fsanitize-address-use-after-scope                          \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   mindopen

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =   MindOpen.hpp                                                  \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   main.cpp                                                      \
                MindOpen.cpp                                                  \
                Instructions.cpp                                              \

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
