
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


int	main(int ac, char **av) {

	std::ifstream		infile(av[1]);
	std::stringstream	infileString;

	if (!infile.is_open()) {
		std::cout << "Error : can't open !\n";
		return (1);
	}

	infileString << infile.rdbuf();

	std::string sourceCode (std::to_string(infileString));


	(void)ac;
	return (0);
}

(std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())
