#ifndef TABLE_CPP
#define TABLE_CPP
#include"Table.h"
//���캯�����趨������������
template <class T>
Table<T>::Table(int _row, int _column)
{
	set(_row, _column);
}

//���캯�����趨������������������
template <class T>
Table<T>::Table(int _row, int _column, T *table)
{
	set(_row, _column);
	set(table);
}

//�趨�������������
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
		//ԭ���ı�Ϊ�գ�����ʱ��ɾ���ͷ�ԭ���Ŀռ�
		delete[] head;
		row = _row;
		column = _column;
		head = new T[_row*_column];
	}
}

//�趨�������
template <class T>
void Table<T>::set(T *table)
{
	for (int i = 0; i < row*column; i++)
		*(head + i) = *(table + i);
}

//�趨���ĳ�������
template <class T>
void Table<T>::set(int _row, int _column, T info)
{
	if (_row > row || _column > column)
		throw ArrayIndexOutOfBoundsException();
	else
		*(head + (_row - 1)*column + _column - 1) = info;
}

//ȡ���ĳ�������
template <class	T>
T Table<T>::get(int _row, int _column)
{
	if (_row > row || _column > column)
		throw ArrayIndexOutOfBoundsException();
	else
		return *(head + (_row - 1)*column + _column - 1);
}

#endif