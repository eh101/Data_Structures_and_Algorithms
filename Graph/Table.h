#ifndef TABLE_H
#define TABLE_H
#include<iostream>
using namespace std;

//用于访问越界时抛出
class ArrayIndexOutOfBoundsException {};

//Table模板类
template <class T>
class Table{
	T* head = NULL;
public:
	int row, column;
	//无参构造函数,什么都不做
	Table(){};
	//构造函数，设定表的行数和列数
	Table(int, int);
	//构造函数，设定表的行数，列数和内容
	Table(int, int, T*);
	//设定表的行数和列数
	void set(int, int);
	//设定表的内容
	void set(T*);
	//设定表的某格的内容
	void set(int, int, T);
	//取表的某格的内容
	T get(int, int);
};

#include"Table.cpp"
#endif