#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
    {
        cout << __FUNCTION__ << a << endl;
    }
};

class B
{
public:
    B(){}
    B(int b) : a(b){}
private:
    A a{7};
};

int main()
{
    B b(5);
    B b1;
    return 0;
}
