

#include <iostream>
#include <string>
#include <typeinfo>

class Base {

	protected:
		std::string className;

	public:
		Base(void) : className("Base") {}
		~Base(void) {}

		virtual void	sayHi() { std::cout << "Base Say's Hi" << std::endl; }

};

class Derived_0 : public Base {

	public:
		Derived_0(void) { className = "Derived_0"; }
		~Derived_0(void) {}

		void	sayHi() { std::cout << "Derived_0 Say's Hi" << std::endl; }

};

class Derived_1 : public Base {

	public:
		Derived_1(void) { className = "Derived_1"; }
		~Derived_1(void) {}

		void	sayHi() { std::cout << "Derived_1 Say's Hi" << std::endl; }

};

class Derived_2 : public Base {

	public:
		Derived_2(void) { className = "Derived_2"; }
		~Derived_2(void) {}

		void	sayHi() { std::cout << "Derived_2 Say's Hi" << std::endl; }

};

class Derived_3 : public Base {

	public:
		Derived_3(void) { className = "Derived_3"; }
		~Derived_3(void) {}

		void	sayHi() { std::cout << "Derived_3 Say's Hi" << std::endl; }

};

class Derived_4 : public Base {

	public:
		Derived_4(void) { className = "Derived_4"; }
		~Derived_4(void) {}

		void	sayHi() { std::cout << "Derived_4 Say's Hi" << std::endl; }

};

void	sayType( Base & instance ) {

	instance.sayHi();
}

int	main() {

	Base		instBase(void);

	Derived_0	instDerived_0;
	Derived_1	instDerived_1;
	Derived_2	instDerived_2;
	Derived_3	instDerived_3;
	Derived_4	instDerived_4;

	// std::cout << std::string(typeid(instBase).name()) << std::endl;
	// std::cout << std::string(typeid(instDerived_0).name()) << std::endl;
	// std::cout << std::string(typeid(instDerived_1).name()) << std::endl;
	// std::cout << std::string(typeid(instDerived_2).name()) << std::endl;
	// std::cout << std::string(typeid(instDerived_3).name()) << std::endl;
	// std::cout << std::string(typeid(instDerived_4).name()) << std::endl;

	Base &instRef0 = instDerived_0;
	Base &instRef1 = instDerived_1;
	Base &instRef2 = instDerived_2;
	Base &instRef3 = instDerived_3;
	Base &instRef4 = instDerived_4;

	sayType(instRef0);
	sayType(instRef1);
	sayType(instRef2);
	sayType(instRef3);
	sayType(instRef4);

	return (0);
}

