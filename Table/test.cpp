#include<iostream>
#include"Table.h"
using namespace std;

int main()
{
	int a[3] = { 1, 2, 3 };
	Table<int> t1(3,1,a);
	t1.set(3, 1);
	t1.set(a);
	try
	{
		cout << t1.get(2, 1);
		t1.set(2, 1, 5);
		cout << t1.get(2, 1);
	}
	catch (ArrayIndexOutOfBoundsException)
	{
		cout << "下标越界";
	}
}