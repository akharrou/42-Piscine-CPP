
#include <iostream>

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class AHuman {

	protected:

		std::string _name;
		int _age;

	public:

		AHuman(std::string name, int age);
		virtual ~AHuman();
		virtual void	sayHi() const = 0;
};

AHuman::AHuman(std::string name, int age)
	: _name(name), _age(age) { }

AHuman::~AHuman() {}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

class Me
	: public AHuman {

	public:

		Me(std::string name, int age) : AHuman(name, age) { };
		~Me() {}

		void	sayHi() const;

};

void	Me::sayHi() const {
	std::cout << "Hello world !\nMy name is "
				<< _name << " & I am "
				<< _age << " years old.\n";
}

/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int	main() {

	Me sam("sam", 16);

	sam.sayHi();

	return (0);
}
