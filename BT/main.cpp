#include <iostream>
#include "Binary_tree.h"
using namespace std;
void print(char& x);
void add(int &);
int main()
{
	Binary_tree<char> dd;
	dd.insert('e');
	dd.insert('b');
	dd.insert('f');
	dd.insert('a');
	dd.insert('d');
	dd.insertNull();
	dd.insert('g');
	dd.insertNull();
	dd.insertNull();
	dd.insert('c');
	/*Binary_tree<int> ww;
	ww = dd;
	ww.insert(10);
	ww.insert(7);
	cout<<"preorder:";
	dd.preorder(print);
	cout << endl;
	dd.inorder(print);
	cout << endl;
	dd.postorder(print);
	cout<<endl;
	cout<<"preorder:";
	ww.preorder(print);
	cout<<endl;
	dd.reverse();
	cout<<"preorder:";
	dd.preorder(print);
	cout<<endl;	
	system("pause");*/
	dd.preorder(print);
	cout << endl;
	dd.inorder(print);
	cout << endl;
	dd.postorder(print);
	cout << endl;
	return 0;
}
void print(char& x)
{
	cout<<x<<" ";
}
void add(int &x)
{
	x++;
}



