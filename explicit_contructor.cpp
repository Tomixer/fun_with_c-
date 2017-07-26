#include <iostream>

using namespace std;

class A
{
public:
	/*explicit*/ A(int a) {cout << a << endl;}
};

void check_A(A a)
{
	cout << __FUNCTION__ << endl;
	return;
}

int main()
{
	int aaa =5;

	check_A(aaa);

	return 0;
}