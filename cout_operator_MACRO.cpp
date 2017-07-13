#include <iostream>

#define COUT_OPERATOR(MY_TYPE, WHAT) ostream& operator<<( ostream &output, MY_TYPE) { \
    output << WHAT; \
    return output; \
}

using namespace std;

class Human
{
public:
    string name;
    int age;
};

COUT_OPERATOR(const Human &h, "Name: " << h.name << ", age: " << h.age)

//ostream& operator<<( ostream &output,
//   const Human &h ) {
//   output << "Name: " << h.name << ", age: " << h.age;
//   return output;
//}

int main(int , char **)
{
    Human T{"Tomi", 16};
    cout << T << endl;
    return 0;
}
