#include <iostream>
#include <stack>
#include "LinkStack.h"
using namespace std;

int main()
{
	char item;
	//STLʵ��
	//stack<char> numbers;
	//�Լ�д��LinkStackģ����
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
