/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:32 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 16:11:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "MindOpen.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	MindOpen	interpreter;

	interpreter.load( "test0.mdp" );
	interpreter.load( "test1.mdp" );
	interpreter.load( "test2.mdp" );
	interpreter.load( "test3.mdp" );
	interpreter.load( "test4.mdp" );
	interpreter.load( "test5.mdp" );

	interpreter.execute( "test3.mdp" );
	interpreter.executeAll();

	return (0);
}


/*

Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a Brainfuck interpreter program.
The source code will be given as first parameter.
The code will always be valid, with no more than 4096 operations.
Brainfuck is a minimalist language. It consists of an array of bytes
(in our case, let's say 2048 bytes) initialized to zero,
and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e
$





#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_memset(char **buffer, int size)
{
	int i;

	i = 0;
	while (i < size)
		(*buffer)[i++] = 0;
}

int		ft_go_to_matching_right_bracket(char *str, int i)
{
	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	i++;
	while (brackets_to_skip != 0)
	{
		if (str[i] == ']')
		{
			brackets_to_skip--;
			if (brackets_to_skip == 0)
				return (i);
		}
		else if (str[i] == '[')
			brackets_to_skip++;
		i++;
	}
	return (i);
}

int		ft_go_to_matching_left_bracket(char *str, int i)
{
	unsigned int brackets_to_skip;

	brackets_to_skip = 1;
	i--;
	while (brackets_to_skip != 0)
	{
		if (str[i] == '[')
		{
			brackets_to_skip--;
			if (brackets_to_skip == 0)
				return (i);
		}
		else if (str[i] == ']')
			brackets_to_skip++;
		i--;
	}
	return (i);
}

int		main(int ac, char **av)
{
	int 	i;
	char	*ptr;
	char	*str;

	if (ac > 1 && av[1])
	{
		str = av[1];
		ptr = malloc(sizeof(char) * 2100);
		ft_memset(&ptr, 2100);
		i = 0;
		while (str[i])
		{
			if (str[i] == '>')
			{
				ptr++;
			}
			else if (str[i] == '<')
			{
				ptr--;
			}
			else if (str[i] == '+')
			{
				(*ptr)++;
			}
			else if (str[i] == '-')
			{
				(*ptr)--;
			}
			else if (str[i] == '.')
			{
				ft_putchar(*ptr);
			}
			else if (str[i] == '[' && *ptr == 0)
			{
				i = ft_go_to_matching_right_bracket(str, i);
			}
			else if (str[i] == ']' && *ptr != 0)
			{
				i = ft_go_to_matching_left_bracket(str, i);
			}
			i++;
		}
		return (0);
	}
	ft_putchar('\n');
	return (0);
}


*/
