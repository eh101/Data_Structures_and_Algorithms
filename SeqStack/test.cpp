#include<iostream>
#include"SeqStack.h"
using namespace std;


//just÷ª «
int main()
{
	SeqStack <float> st1;
	for (int i = 0; i < 5; i++)
	{
		float x;
		cin >> x;
		st1.push(x);
	}
	cout << st1.size() << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << st1.top() << "\t";
		st1.pop();
	}
	cout << endl << st1.size() << endl;;
	return 0;
}
