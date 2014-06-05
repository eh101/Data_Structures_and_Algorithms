#ifndef MAZE_H
#define MAZE_H
#include"Table.h"
#include"LinkStack.h"
#include<iostream>
using namespace std;

struct Path
{
	int x, y, move=0;
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
};

#endif