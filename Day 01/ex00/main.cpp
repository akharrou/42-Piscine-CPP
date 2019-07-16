/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:42:01 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/15 16:37:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(Pony **pony1, Pony **pony2)
{
	Pony *pony3 = new Pony("Blake", "Heap");
	Pony *pony4 = new Pony("Sam", "Heap");

	(*pony1)->play();
	(*pony2)->play();
	pony3->play();
	pony4->play();

	delete (*pony1);
	delete (*pony2);
	delete pony3;
	delete pony4;

	// delete(pony3); // crashes the computer
	// delete(pony4); // crashes the computer
}

void	ponyOnTheStack()
{
	Pony pony3("Michael", "Stack");
	Pony pony4("Robert", "Stack");

	pony3.play();
	pony4.play();
}

int		main()
{
	Pony *pony1 = new Pony("James", "Heap");
	Pony *pony2 = new Pony("Tony", "Heap");

	ponyOnTheHeap(&pony1, &pony2);

	// delete pony1; // crashes the computer
	// delete pony2; // crashes the computer

	ponyOnTheStack();

	return (0);
}

/* Why is the data still accessible after deletion ?
https://stackoverflow.com/questions/1930459/c-delete-it-deletes-my-objects-but-i-can-still-access-the-data */
