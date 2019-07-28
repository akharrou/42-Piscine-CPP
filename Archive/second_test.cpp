
#include <unistd.h>
#include <iostream>

#include <thread>

void sayhi()
{
	for (int i = 0; i < 3; ++i) {
		std::cout << "hello world !\n";
		sleep(1);
	}
}

void saybye()
{
	for (int i = 0; i < 4; ++i) {
		std::cout << "bye world !\n";
		sleep(1);
	}
}

void saynothing()
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "nothing world !\n";
		sleep(1);
	}
}

using namespace std::chrono;

int	main() {

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	std::thread thread_1(sayhi);
	std::thread thread_2(saybye);
	std::thread thread_3(saynothing);

	thread_1.join();
	thread_2.join();
	thread_3.join();

	// sayhi();
	// saybye();
	// saynothing();

	std::cout << "done!\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> timeSpan;

	timeSpan = duration_cast<microseconds>(t2 - t1);

	std::cout << timeSpan.count() << " seconds\n";

	return (0);
}
