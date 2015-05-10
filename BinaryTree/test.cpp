#include<iostream>
#include"BinaryTree.h"
using namespace std;

void print(char &x)
{
	cout << x;
}

int main()
{
	BinaryTree<char> bt;
	bt.insert('e');
	bt.insert('b');
	bt.insert('f');
	bt.insert('a');
	bt.insert('d');
	bt.insertNull();
	bt.insert('g');
	bt.insertNull();
	bt.insertNull();
	bt.insert('c');
	cout << "Perorder:";
	bt.perOrder(print);
	cout << endl<< "Inorder:";;
	bt.inOrder(print);
	cout << endl << "Postorder:";;
	bt.postOrder(print);
	cout << endl;
	return 0;
}