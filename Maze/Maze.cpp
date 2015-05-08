#include"Maze.h"
#include<iostream>
using namespace std;

//构造函数，初始化迷宫为默认值
Maze::Maze()
{
	//设置默认的迷宫地图
	/*bool m[144] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1,
		1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};
	map.set(12, 12);     //设置地图大小
	map.set(m);          //设置地图内容
	//设置地图标记的大小为地图大小
	mark.set(12, 12);
	//设置地图标记位都为0
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 12; j++)
			mark.set(i, j, 0);*/
	//设置迷宫的默认搜索策略
	int d[16] =
	{
		1, 0,
		1, -1,
		0, -1,
		-1, -1,
		-1, 0,
		-1, 1,
		0, 1,
		1, 1
	};
	direction.set(8, 2);
	direction.set(d);
	//cout << direction.get(2, 1) << direction.get(2, 2);
	/*//设置默认起点
	start.row = 2;
	start.column = 2;
	//设置默认终点
	end.row = map.row - 1;
	end.column = map.column - 1;*/
}

//设置迷宫地图
void Maze::setMap(int _row, int _column, bool *_map)
{
	map.set(_row, _column);
	map.set(_map);
	//设置地图标记的大小为地图大小
	mark.set(_row, _column);
	//设置地图标记位都为0
	for (int i = 1; i <= _row; i++)
		for (int j = 1; j <= _column; j++)
			mark.set(i, j, 0);
}

//设置迷宫的搜索策略
void Maze::setDirection(int* _direction)
{

	direction.set(_direction);
}

//设置起点
void Maze::setStart(int _row, int _column)
{
	start.row = _row;
	start.column = _column;
}

//设置终点
void Maze::setEnd(int _row, int _column)
{
	end.row = _row;
	end.column = _column;
}

//开始走迷宫（主要算法）
bool Maze::run()
{
	mark.set(start.row, start.column, 1);  //起点标记为走过
	path.push(start);				   //起点入栈
	while (!path.empty())
	{
		Path temp = path.top();
		path.pop();
		temp.move++;
		while (temp.move <= 8)    //依次探索8个方向
		{
			int row = temp.row + direction.get(temp.move, 1);
			int column = temp.column + direction.get(temp.move, 2);
			if (row == end.row&&column == end.column&&mark.get(row, column) == 0)  //走到出口
			{
				//printPath();
				mark.set(row, column, 1);  //标记为走过
				Path end(row, column, temp.move);
				path.push(end);
				return true;
			}
			if (map.get(row, column) == 0 && mark.get(row, column) == 0)  //点可以走且没有探索过
			{
				mark.set(row, column, 1);  //标记为走过
				path.push(temp);    //并将该点入栈
				temp.row = row;
				temp.column = column;
				temp.move = 1;
			}
			else
				temp.move++;
		}
	}
	return false;
}

//打印迷宫路径
void Maze::printPath()
{
	Table<bool> pathMark(map.row,map.column);
	for (int i = 1; i <= pathMark.row; i++)
		for (int j = 1; j <= pathMark.column; j++)
			pathMark.set(i, j, 0);
	int size = path.size();
	for (; size > 1; size--){
		Path temp = path.top();
		path.pop();
		pathMark.set(temp.row, temp.column, 1);
	}

	for (int i = 1; i <= map.row; i++)
	{
		for (int j = 1; j <= map.row; j++)
		{
			if (pathMark.get(i, j) == 1)
				cout << "X";
			else
				cout << map.get(i, j);
			if (pathMark.get(i, j) == 1 && pathMark.get(i, j + 1) == 1)
				cout << "-";
			else
				cout << " ";
		}
		cout << endl;
	}
}

//测试Direction
void Maze::testDirection()
{
	Table<int> test(3, 3);
	Path p(2, 2);
	test.set(2, 2, 0);
	for (int i = 1; i <= 8; i++){
		test.set(p.row + direction.get(i, 1), p.column + direction.get(i, 2), i);
	}

	for (int i = 1; i <= test.row; i++)
	{
		for (int j = 1; j <= test.row; j++)
		{
			cout << test.get(i, j) << " ";
		}
		cout << endl;
	}
}