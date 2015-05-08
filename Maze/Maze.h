#ifndef MAZE_H
#define MAZE_H
#include"Table.h"
#include"LinkStack.h"
#include<iostream>
using namespace std;

class Path
{
public:
	int row, column, move;

	Path(int _row = 0, int _column = 0, int _move = 0)
	{
		row = _row;
		column = _column;
		move = _move;
	}
};

class Maze
{
	Table<bool> map;
	Table<bool> mark;
	Table<int> direction;
	LinkStack<Path> path;
	//�����յ�
	Path start, end;
public:
	//���캯������ʼ���Թ�
	Maze();
	//�����Թ���ͼ
	void setMap(int,int,bool*);
	//ȡ�Թ���ͼ
	//Table<bool> getMap();
	//ȡ�Թ����߹��ĵط��ı��
	//Table<bool> getMark();
	//�����Թ�����������
	void setDirection(int*);
	//ȡ�Թ�����������
	//�������
	void setStart(int, int);
	//�����յ�
	void setEnd(int, int);
	//Table<int> getDirection();
	//ȡ���Թ���·��
	LinkStack<Path> getPath();
	//��ӡ�Թ�·��
	void printPath();
	//��ʼ���Թ�����Ҫ�㷨��
	bool run();

	void testDirection();
};

#endif