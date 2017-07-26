#include <iostream>
#include <utility>

using namespace std;

template <class T1, class T2>
pair<T1, T2> multiply_my(pair<T1, T2> l, pair<T1, T2> r)
{
	return pair<T1, T2>{l.first * r.first, l.second * r.second}; 
}

int main()
{
	cout <<  multiply_my(pair<int, int>{1,2},pair<int, int>{3,4}).second << endl;
	return 0;
}