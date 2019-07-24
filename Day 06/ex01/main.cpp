/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:06:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 01:06:59 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize   ( void );
Data * deserialize ( void * raw );

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main() {

	void * raw       = serialize();
	Data * proofData = deserialize(raw);

	std::cout << proofData->s1 << "\n"
			  << proofData->n  << "\n"
			  << proofData->s2 << "\n";

	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void * serialize ( void ) {

	char	random_array_1[8] = { 'r','a','s','d','0','m','3','\0' };
	int		random_integer    = 726;
	char	random_array_2[8] = { 'o','t','h','e','r','4','r','\0' };

	char * data = new char[20];

	*reinterpret_cast <unsigned long *> (&(data[0])) = *reinterpret_cast <unsigned long *> (random_array_1);
	*reinterpret_cast <int *> (&(data[8]))           = random_integer;
	*reinterpret_cast <unsigned long *> (&data[12])  = *reinterpret_cast <unsigned long *> (random_array_2);

	return (data);
}

Data * deserialize ( void * raw ) {

	Data * cooked = new Data;

	char	cooked_array_1[8];
	int		cooked_integer;
	char	cooked_array_2[8];

	*(unsigned long *)(&cooked_array_1[0]) = *reinterpret_cast <unsigned long *> (&reinterpret_cast <char*> (raw)[0]);
	cooked_integer = *(reinterpret_cast <int *> (&reinterpret_cast <char*> (raw)[8]));
	*(unsigned long *)(&cooked_array_2[0]) = *reinterpret_cast <unsigned long *> (&reinterpret_cast <char*> (raw)[12]);

	cooked->s1 = std::string(cooked_array_1);
	cooked->n = cooked_integer;
	cooked->s2 = std::string(cooked_array_2);

	return (cooked);
}
