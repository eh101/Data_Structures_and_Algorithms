#include <iostream>
#include <stack>
#include "LinkStack.h"
using namespace std;

int main()
{
	char item;
	//STL实现
	//stack<char> numbers;
	//自己写的LinkStack模板类
	LinkStack<char> numbers;
	cout << "Please enter the string sequence.\nIf you want to quit, Please enter #\n";
	item = cin.get();
	while (item != '#')
	{
		numbers.push(item);
		item = cin.get();
	}
	cout << endl;
	while (!numbers.empty()) {
		cout << numbers.top();
		numbers.pop();
	}
	cout << endl;
}
