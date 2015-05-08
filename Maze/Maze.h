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
	//起点和终点
	Path start, end;
public:
	//构造函数，初始化迷宫
	Maze();
	//设置迷宫地图
	void setMap(int,int,bool*);
	//取迷宫地图
	//Table<bool> getMap();
	//取迷宫中走过的地方的标记
	//Table<bool> getMark();
	//设置迷宫的搜索策略
	void setDirection(int*);
	//取迷宫的搜索策略
	//设置起点
	void setStart(int, int);
	//设置终点
	void setEnd(int, int);
	//Table<int> getDirection();
	//取走迷宫的路径
	LinkStack<Path> getPath();
	//打印迷宫路径
	void printPath();
	//开始走迷宫（主要算法）
	bool run();

	void testDirection();
};

#endif