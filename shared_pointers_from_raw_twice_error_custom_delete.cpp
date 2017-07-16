#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A
{
public:
    A(int aa) : a(aa){}
    int getA() {return a;}
private:
    int a;
};

auto deleter1 = [](A * pA)
{
    cout << "deleter1, a=" << pA->getA() << endl;
    delete pA;
};
auto deleter2 = [](A * pA)
{
    cout << "deleter2, a=" << pA->getA() << endl;
    delete pA;
};

int main()
{
    A * pA = new A(7);

    vector<shared_ptr<A>> v;
    v.push_back(shared_ptr<A>(pA, deleter1));
    v.push_back(v[0]);

    // NEVER PASS RAW POINTER MORE THAN ONCE!!
    v.push_back(shared_ptr<A>(pA, deleter2)); // NEVER PASS RAW POINTER MORE THAN ONCE!!
    // NEVER PASS RAW POINTER MORE THAN ONCE!!

    return 0;
}
//deleter1, a=7
//deleter2, a=9527376
//*** Error in `./a.out': double free or corruption
