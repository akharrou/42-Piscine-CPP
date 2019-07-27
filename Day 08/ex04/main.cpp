/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:08:26 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/26 20:47:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "RPN_Calculator.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int ac, char **av) {

	RPN_Calculator inst;

	if (ac == 2)
		inst.evaluateInfix(av[1]);

	return (0);
}


/*

#include <stdio.h>
#include <stdlib.h>

#include "rpn_calc.h"

int		ft_valid_expr(char *s)
{
	while (*s)
	{
		if (!(IS_DIGIT(*s) || IS_OP(*s) || IS_SPACE(*s)))
			return (0);
		s++;
	}
	return (1);
}

void	ft_enque(t_stack **head, int data)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->data = data;
	new->next = (*head) ? *head : NULL;
	*head = new;
}

void	ft_deque(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
}

int		ft_calc(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
	{
		if (b == 0)
			return (0);
		return (a / b);
	}
	else if (op == '%')
	{
		if (b == 0)
			return (0);
		return (a % b);
	}
	else
		return (0);
}

void	ft_rpn_calc(char **strtab)
{
	int			val;
	int 		res;
	t_stack		*head;

	val = 0;
	head = NULL;
	while (*strtab)
	{
		if (IS_OP((*strtab)[0]))
		{
			if (head && head->next)
			{
				res = ft_calc((head)->next->data, (head)->data, (*strtab)[0]);
				ft_deque(&head);
				ft_deque(&head);
				ft_enque(&head, res);
			}
			else if (head)
			{
				printf("Error\n");
				return ;
			}
			else
			{
				printf("Error\n");
				return ;
			}
		}
		else
			ft_enque(&head, atoi(*strtab));
		strtab++;
	}
	if (head->next)
	{
		printf("Error\n");
		return ;
	}
	printf("%i\n", head->data);
}

int		main(int ac, char *av[])
{
	if (ac != 2 || !ft_valid_expr(av[1]))
	{
		printf("Error\n");
		return (1);
	}
	ft_rpn_calc(ft_split(av[1]));
	return (0);
}

*/
