# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 12:26:27 by akharrou          #+#    #+#              #
#    Updated: 2019/07/28 13:58:12 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   clang++ -std=c++2a
CFLAGS      =   -W -Wall -Wextra -Werror $(OPTIM_FLAGS)

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

NAME        =   ft_gkrellm

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =                                                                 \
                Includes/IMonitorModule.hpp                                   \
                Includes/IMonitorDisplay.hpp                                  \
                                                                              \
                Includes/GKrellM.hpp                                          \
                Includes/GKrellM_Modules.hpp                                  \
                Includes/GKrellM_Shell.hpp                                    \
                Includes/GKrellM_Graphical.hpp                                \
                                                                              \
                # Includes/_______.hpp                                        \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =                                                                 \
                Sources/main.cpp                                              \
                                                                              \
                Sources/GKrellM.cpp                                           \
                Sources/GKrellM_Shell.cpp                                     \
                Sources/GKrellM_Modules.cpp                                   \
                Sources/GKrellM_Graphical.cpp                                 \
                                                                              \
                Sources/Errors.cpp                                            \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.cpp=.o)

# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -pedantic -lncurses -o $@
	@echo && echo $(GREEN) "  [√]\t[$(NAME) Successfully Compiled!]"
	@echo $(WHITE)

%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -pipe -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

run: $(NAME)
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
