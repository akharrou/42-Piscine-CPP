/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:06:47 by akharrou          #+#    #+#             */
/*   Updated: 2019/07/24 23:31:17 by akharrou         ###   ########.fr       */
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

	srand(time(0));

	void * raw       = serialize();
	Data * proofData = deserialize(raw);

	std::cout << "\n/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
	std::cout << "After Deserialization :\n\n";
	std::cout << proofData->s1 << "\n"
			  << proofData->n  << "\n"
			  << proofData->s2 << "\n\n";

	return (0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

char * generateRandom8CharacterString ( void ) {

	std::string chars =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
		"abcdefghijklmnopqrstuvwxyz"\
		"0123456789";

	char * randomArray = new char [8];

	for ( size_t i = 0; i < 7; ++i )
		randomArray[i] = chars[rand() % chars.size()];
	randomArray[7] = '\0';

	return (randomArray);
}

void * serialize ( void ) {

	char * random_array_1 = generateRandom8CharacterString();
	int    random_integer = rand() % 1000;
	char * random_array_2 = generateRandom8CharacterString();

	std::cout << "/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */\n";
	std::cout << "Pre-Serialization :\n\n";
	std::cout << random_array_1 << std::endl;
	std::cout << random_integer << std::endl;
	std::cout << random_array_2 << std::endl;

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

	*reinterpret_cast <unsigned long *>(&cooked_array_1[0]) = *reinterpret_cast <unsigned long *> (&reinterpret_cast <char*> (raw)[0]);
	cooked_integer                                          = *(reinterpret_cast <int *> (&reinterpret_cast <char*> (raw)[8]));
	*reinterpret_cast <unsigned long *>(&cooked_array_2[0]) = *reinterpret_cast <unsigned long *> (&reinterpret_cast <char*> (raw)[12]);

	cooked->s1 = std::string(cooked_array_1);
	cooked->n = cooked_integer;
	cooked->s2 = std::string(cooked_array_2);

	return (cooked);
}
