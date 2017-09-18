#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Node
{
public:
	Node(int d) : left(nullptr), right(nullptr), data(d) {}
	Node<T> * left, * right;
	T data;
};

void makeTree(vector<int>& ints, int from, int to, Node<int> * pNode)
{
	int range  = to - from;
	int middle = from + range/2;
	if(range > 0)
	{
		//cout << ints[middle] << endl;
		pNode = new Node<int>(ints[middle]);

		makeTree(ints, from, middle, pNode->left);
		makeTree(ints, middle+1, to, pNode->right);
	}
}

int main(int , char **)
{
	vector<int> ints = {1, 2, 4, 5, 9, 11, 123, 377};
	Node<int> * root = nullptr;
	makeTree(ints, 0, ints.size(), root);
	return 0;
}