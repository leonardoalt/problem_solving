#include <iostream>

using namespace std;

int
main()
{
	int a = 2;
	int& b = a;
	b = 7;
	a = b;
	cout << "A = " << a << " | B = " << b << endl;
	return 0;
}

