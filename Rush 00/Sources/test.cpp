

















#include <iostream>

using namespace std;

template <typename T> void bar(T &b)  { cout << "bar <template> called\n" ; (void)b; }
template <typename T> void foo(T &&b) { cout << "foo <template> called\n" ; (void)b; }
void bar(string &b)                   { cout << "bar <string> called\n"   ; (void)b; }
void foo(string &b)                   { cout << "foo <string> called\n"   ; (void)b; }

int	main() {

	string msga = "hella";
	string msgb = "hellb";
	int a = 1;
	int b = 2;

	bar(a);
	bar(msga);

	bar(b);
	bar(msgb);

	cout << endl;

	foo(a);
	foo(msga);

	foo(b);
	foo(msgb);

	return (0);
}
