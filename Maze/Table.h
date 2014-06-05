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

//构造函数，设定表行数和列数
template <class T>
Table<T>::Table(int _row, int _column)
{
	set(_row, _column);
}

//构造函数，设定表行数，列数和内容
template <class T>
Table<T>::Table(int _row, int _column, T *table)
{
	set(_row, _column);
	set(table);
}

//设定表的行数和列数
template <class T>
void Table<T>::set(int _row, int _column)
{
	if (head == NULL)
	{
		row = _row;
		column = _column;
		head = new T[_row*_column];
	}
	else
	{
		//原来的表不为空，设置时先删除释放原来的空间
		delete[] head;
		row = _row;
		column = _column;
		head = new T[_row*_column];
	}
}

//设定表的内容
template <class T>
void Table<T>::set(T *table)
{
	for (int i = 0; i < row*column; i++)
		*(head + i) = *(table + i);
}

//设定表的某格的内容
template <class T>
void Table<T>::set(int _row, int _column, T info)
{
	if (_row > row || _column > column)
		throw ArrayIndexOutOfBoundsException();
	else
		*(head + (_row - 1)*column + _column - 1) = info;
}

//取表的某格的内容
template <class	T>
T Table<T>::get(int _row, int _column)
{
	if (_row > row || _column > column)
		throw ArrayIndexOutOfBoundsException();
	else
		return *(head + (_row - 1)*column + _column - 1);
}

#endif