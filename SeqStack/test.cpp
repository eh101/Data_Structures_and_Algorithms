#include<iostream>
#include"SeqStack.h"
#include"SeqStack.cpp"
using namespace std;

int main()
{
	SeqStack <int> st1;
	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		st1.push(x);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << st1.top()<<"\t";
		st1.pop();
	}
	cout << endl;
	return 0;
}