#include"Maze.h"
#include<iostream>
using namespace std;

//构造函数，初始化迷宫为默认值
Maze::Maze()
{
	//设置默认的迷宫地图
	bool m[144] =
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
			mark.set(i, j, 0);
	//设置迷宫的默认搜索策略
	int d[16] =
	{
		 1,  0,
		 1, -1,
		 0, -1,
		-1, -1,
		-1,  0,
		-1,  1,
		 0,  1,
		 1,  1
	};
	direction.set(8, 2);
	direction.set(d);
	//cout << direction.get(2, 1) << direction.get(2, 2);
	//设置默认起点
	start.x = 2;
	start.y = 2;
	//设置默认终点
	end.x = map.column - 1;
	end.y = map.row - 1;
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
void Maze::setStart(int _x, int _y)
{
	start.x = _x;
	start.y = _y;
}

//设置终点
void Maze::setEnd(int _x, int _y)
{
	end.x = _x;
	end.y = _y;
}

//开始走迷宫（主要算法）
bool Maze::run()
{
	mark.set(start.x, start.y, 1);  //起点标记为走过
	path.push(start);				   //起点入栈
	while (!path.empty())
	{
		Path temp = path.top();
		path.pop();
		temp.move++;
		while (temp.move<=8)    //依次探索8个方向
		{
			int x = temp.x + direction.get(temp.move, 1);
			int y = temp.y + direction.get(temp.move, 2);
			if (x == end.x&&y == end.y&&mark.get(x, y) == 0)  //走到出口
			{
				//printPath();
				mark.set(x, y, 1);  //标记为走过
				return true;
			}
			if (map.get(x, y) == 0&&mark.get(x, y) == 0)  //点可以走且没有探索过
			{
				mark.set(x, y, 1);  //标记为走过
				path.push(temp);    //并将该点入栈
				temp.x = x;
				temp.y = y;
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
	for (int i = 1; i <= map.row; i++)
	{
		for (int j = 1; j <= map.row; j++)
		{
			if (mark.get(i, j) == 1)
				cout << "X";
			else
				cout << map.get(i, j);
			cout << " ";
		}
		cout << endl;
	}
}