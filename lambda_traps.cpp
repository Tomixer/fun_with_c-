#include <iostream>
#include <vector>
#include <functional>

using namespace std;


using FilterContainer = vector<function<bool(int)>>;

class A
{
    FilterContainer * _fc;
    int _divisor;
    static int s;
    public:
    A(FilterContainer* fc, int d) : _fc(fc), _divisor(d){}
// ERROR: trying to chatch this of A object, because it is this->_divisor
//    void addLambda()
//    {
//        _fc->emplace_back([_divisor](int val) {return val % _divisor == 0;});
//    }


    // s caught by reference!!!!!!!!!!!!
    void addLambda1()
    {
        _fc->emplace_back([s](int val) {
            cout << s << endl;
            return true;
        });
        s++;
    }
    void addLambda2()
    {
        _fc->emplace_back([=](int val) {
            // actually dangling reference to [this] , because this->_divisor is what happens
            return val % _divisor == 0;
        });
        s++;
    }

    // make a local copy of class member, to avoid this reference
    void addLambda3()
    {
        auto copy = _divisor;
        _fc->emplace_back([=](int val) {
            return val % copy == 0;
        });
    }

};

int A::s = 0;


int main()
{
    FilterContainer fc;

    A * a = new A(&fc, 3);
    a->addLambda1();
    a->addLambda2();
    a->addLambda3();

    delete a;
    // replacing object pointed to by lambda using the same memory
    //   !!!!!!!!ERROR!!!!!!!!!!!
    a = new A(&fc, 4);

    // static changed because it's a reference
    fc.at(0)(3);

    // divisor should be 3, so call should be true, but divisor is 4 => 3%4 => false
    if(fc.at(1)(3))
        cout <<  "true" << endl;
    else
        cout <<  "false" << endl;

    // works fine with local copy
    if(fc.at(2)(3))
        cout <<  "true" << endl;
    else
        cout <<  "false" << endl;

    return 0;
}
