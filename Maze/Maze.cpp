#include"Maze.h"
#include<iostream>
using namespace std;

//���캯������ʼ���Թ�ΪĬ��ֵ
Maze::Maze()
{
	//����Ĭ�ϵ��Թ���ͼ
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
	map.set(12, 12);     //���õ�ͼ��С
	map.set(m);          //���õ�ͼ����
	//���õ�ͼ��ǵĴ�СΪ��ͼ��С
	mark.set(12, 12);
	//���õ�ͼ���λ��Ϊ0
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 12; j++)
			mark.set(i, j, 0);
	//�����Թ���Ĭ����������
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
	//����Ĭ�����
	start.x = 2;
	start.y = 2;
	//����Ĭ���յ�
	end.x = map.column - 1;
	end.y = map.row - 1;
}

//�����Թ���ͼ
void Maze::setMap(int _row, int _column, bool *_map)
{
	map.set(_row, _column);
	map.set(_map);
	//���õ�ͼ��ǵĴ�СΪ��ͼ��С
	mark.set(_row, _column);
	//���õ�ͼ���λ��Ϊ0
	for (int i = 1; i <= _row; i++)
		for (int j = 1; j <= _column; j++)
			mark.set(i, j, 0);
}

//�����Թ�����������
void Maze::setDirection(int* _direction)
{
	direction.set(_direction);
}

//�������
void Maze::setStart(int _x, int _y)
{
	start.x = _x;
	start.y = _y;
}

//�����յ�
void Maze::setEnd(int _x, int _y)
{
	end.x = _x;
	end.y = _y;
}

//��ʼ���Թ�����Ҫ�㷨��
bool Maze::run()
{
	mark.set(start.x, start.y, 1);  //�����Ϊ�߹�
	path.push(start);				   //�����ջ
	while (!path.empty())
	{
		Path temp = path.top();
		path.pop();
		temp.move++;
		while (temp.move<=8)    //����̽��8������
		{
			int x = temp.x + direction.get(temp.move, 1);
			int y = temp.y + direction.get(temp.move, 2);
			if (x == end.x&&y == end.y&&mark.get(x, y) == 0)  //�ߵ�����
			{
				//printPath();
				mark.set(x, y, 1);  //���Ϊ�߹�
				return true;
			}
			if (map.get(x, y) == 0&&mark.get(x, y) == 0)  //���������û��̽����
			{
				mark.set(x, y, 1);  //���Ϊ�߹�
				path.push(temp);    //�����õ���ջ
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

//��ӡ�Թ�·��
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