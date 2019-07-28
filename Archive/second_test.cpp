
// #include <unistd.h>
// #include <iostream>

// #include <thread>

// void sayhi()
// {
// 	for (int i = 0; i < 3; ++i) {
// 		std::cout << "hello world !\n";
// 		sleep(1);
// 	}
// }

// void saybye()
// {
// 	for (int i = 0; i < 4; ++i) {
// 		std::cout << "bye world !\n";
// 		sleep(1);
// 	}
// }

// void saynothing()
// {
// 	for (int i = 0; i < 5; ++i) {
// 		std::cout << "nothing world !\n";
// 		sleep(1);
// 	}
// }

// using namespace std::chrono;

// int	main() {

// 	high_resolution_clock::time_point t1 = high_resolution_clock::now();

// 	std::thread thread_1(sayhi);
// 	std::thread thread_2(saybye);
// 	std::thread thread_3(saynothing);

// 	thread_1.join();
// 	thread_2.join();
// 	thread_3.join();

// 	// sayhi();
// 	// saybye();
// 	// saynothing();

// 	std::cout << "done!\n";

// 	high_resolution_clock::time_point t2 = high_resolution_clock::now();
// 	duration<double> timeSpan;

// 	timeSpan = duration_cast<microseconds>(t2 - t1);

// 	std::cout << timeSpan.count() << " seconds\n";

// 	return (0);
// }


#include <iostream>

struct Base {

	std::string _name;

	Base();
	Base(std::string name);
	Base(const Base &src);
	virtual ~Base();

	Base &operator=(const Base &rhs);

};

Base::Base() {}
Base::Base(std::string name) : _name(name) {}
Base::Base( const Base & src ) { *this = src; }
Base::~Base() {}

Base &Base::operator=(const Base &rhs) {
	_name = rhs._name;
	return (*this);
}

struct A :
	public Base {

	A();
	A(std::string name);
	~A();

};

A::A(){};
A::A(std::string name) : Base(name) {};
A::~A(){};

int	main() {

	A dude;
	A dude2("Jake");
	A dude3 = dude2;
	A dude4(dude3);

	std::cout << "dude2 : " << dude2._name << '\n';
	std::cout << "dude3 : " << dude3._name << '\n';
	std::cout << "dude4 : " << dude4._name << '\n';

	return (0);
}
