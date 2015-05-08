#ifndef TABLE_H
#define TABLE_H
#include<iostream>
using namespace std;

//���ڷ���Խ��ʱ�׳�
class ArrayIndexOutOfBoundsException {};

//Tableģ����
template <class T>
class Table{
	T* head = NULL;
public:
	int row, column;
	//�޲ι��캯��,ʲô������
	Table(){};
	//���캯�����趨�������������
	Table(int, int);
	//���캯�����趨�������������������
	Table(int, int, T*);
	//�趨�������������
	void set(int, int);
	//�趨�������
	void set(T*);
	//�趨���ĳ�������
	void set(int, int, T);
	//ȡ���ĳ�������
	T get(int, int);
};

#include"Table.cpp"
#endif