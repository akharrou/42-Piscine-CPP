


# include <iostream>
# include <sstream>
# include <vector>
# include <stack>
# include <algorithm>

#define ISDIGIT(c) ('0' <= c && c <= '9')

#define IS_PAROPEN(tok) (tok == "(")
#define IS_PRECEDENCE_LVL_2(tok) (tok == "+" || tok == "-")
#define IS_PRECEDENCE_LVL_3(tok) (tok == "*" || tok == "/")
#define IS_PARCLOSE(tok) (tok == ")")

std::vector <std::string>
	tokenize ( std::string infix_expression )
{
	std::vector <std::string> tokens;

    std::string expr(infix_expression);
	std::string	tmp;

	for (size_t i = 0; i < expr.length(); ++i) {

		if (ISDIGIT(expr[i])) {

			tmp = std::to_string(std::stoi(&expr[i]));
			tokens.push_back(tmp);
			i += tmp.length() - 1;

		} else if (expr[i] != ' ') {
				tokens.push_back(expr.substr(i, 1));
		}
	}

	std::cout << "Tokens: ";
	for_each(tokens.begin(), tokens.end(), [](std::string token) {

		if (token == "+")
			std::cout << "Op(+) ";
		else if (token == "-")
			std::cout << "Op(-) ";
		else if (token == "*")
			std::cout << "Op(*) ";
		else if (token == "/")
			std::cout << "Op(/) ";
		else if (token == "(")
			std::cout << "ParOpen ";
		else if (token == ")")
			std::cout << "ParClose ";
		else
			std::cout << "Num(" << token << ") ";
	});
	std::cout << std::endl;
	return (tokens);
}

std::vector <std::string>
	postfixify ( std::vector <std::string> infixTokens ) {

	std::vector <std::string> postfixVec;
	std::vector <std::string> tmpStack;

	std::vector<std::string>::iterator it;

	for (it = infixTokens.begin(); it != infixTokens.end(); ++it)
	{
		if (IS_PAROPEN(*it)) {

			tmpStack.push_back(*it);

		} else if (IS_PRECEDENCE_LVL_2(*it)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_2(tmpStack.back())) {
				postfixVec.push_back(tmpStack.back());
				tmpStack.pop_back();
			}
			tmpStack.push_back(*it);

		} else if (IS_PRECEDENCE_LVL_3(*it)) {

			while (!tmpStack.empty() && IS_PRECEDENCE_LVL_3(tmpStack.back())) {
				postfixVec.push_back(tmpStack.back());
				tmpStack.pop_back();
			}
			tmpStack.push_back(*it);

		} else if (IS_PARCLOSE(*it)) {

			if (!tmpStack.empty()) {
				while (!tmpStack.empty() && !IS_PAROPEN(tmpStack.back())) {
					postfixVec.push_back(tmpStack.back());
					tmpStack.pop_back();
				}
				tmpStack.pop_back();
			}

		} else {
			postfixVec.push_back(*it);
		}
	};

	while (!tmpStack.empty()) {
		postfixVec.push_back(tmpStack.back());
		tmpStack.pop_back();
	}

	std::cout << "Postfix : ";
	for_each(postfixVec.begin(), postfixVec.end(), [](std::string token) {

		if (token == "+")
			std::cout << "Op(+) ";
		else if (token == "-")
			std::cout << "Op(-) ";
		else if (token == "*")
			std::cout << "Op(*) ";
		else if (token == "/")
			std::cout << "Op(/) ";
		else
			std::cout << "Num(" << token << ") ";
	});
	std::cout << std::endl;
	return (postfixVec);
}

#define IS_PAROPEN(tok) (tok == "(")
#define IS_PRECEDENCE_LVL_2(tok) (tok == "+" || tok == "-")
#define IS_PRECEDENCE_LVL_3(tok) (tok == "*" || tok == "/")
#define IS_PARCLOSE(tok) (tok == ")")

int	main(int ac, char **av) {

	std::vector<std::string> infixTokens = tokenize(av[1]);
	std::vector<std::string> postfixTokens = postfixify(infixTokens);

	(void)ac;
	return (0);
}
