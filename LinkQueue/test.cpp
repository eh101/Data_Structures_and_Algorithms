#include<iostream>
#include<queue>
#include"LinkQueue.h"
using namespace std;


int main()
{
	//queue<int> q1;
	LinkQueue<int> lq1;
	int x;
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		lq1.push(x);
	}
	cout << lq1.size() << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << lq1.front();
		lq1.pop();
	}
	cout << endl;
	cout << lq1.size() << endl;
	return 0;
}