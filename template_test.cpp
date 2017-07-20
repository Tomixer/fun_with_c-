#include <iostream>

using namespace std;

class A
{
    int a;

    int get() const {return a;}
public:
    A(int aa= int()) : a(aa){}
    A& operator+=(const A& rhs){
        a += rhs.get();
        return *this;
    }

    operator double(){
        return (double)a;
    }
};

template<typename T>
double GetAverage(T tArray[], int nElements)
{
   T tSum = T(); // tSum = 0
   for (int nIndex = 0; nIndex < nElements; ++nIndex)
   {
     tSum += tArray[nIndex];
   }

   // Whatever type of T is, convert to double
   return double(tSum) / nElements;
}

int main()
{
    constexpr int SIZE = 5;
    A a[SIZE] = {0, 1, 2, 4 ,3};
    cout << GetAverage(a, SIZE) << endl;

    return 0;
}
