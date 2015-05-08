#include"Maze.h"
#include<iostream>
using namespace std;

//���캯������ʼ���Թ�ΪĬ��ֵ
Maze::Maze()
{
	//����Ĭ�ϵ��Թ���ͼ
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
	map.set(12, 12);     //���õ�ͼ��С
	map.set(m);          //���õ�ͼ����
	//���õ�ͼ��ǵĴ�СΪ��ͼ��С
	mark.set(12, 12);
	//���õ�ͼ���λ��Ϊ0
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 12; j++)
			mark.set(i, j, 0);*/
	//�����Թ���Ĭ����������
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
	/*//����Ĭ�����
	start.row = 2;
	start.column = 2;
	//����Ĭ���յ�
	end.row = map.row - 1;
	end.column = map.column - 1;*/
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
void Maze::setStart(int _row, int _column)
{
	start.row = _row;
	start.column = _column;
}

//�����յ�
void Maze::setEnd(int _row, int _column)
{
	end.row = _row;
	end.column = _column;
}

//��ʼ���Թ�����Ҫ�㷨��
bool Maze::run()
{
	mark.set(start.row, start.column, 1);  //�����Ϊ�߹�
	path.push(start);				   //�����ջ
	while (!path.empty())
	{
		Path temp = path.top();
		path.pop();
		temp.move++;
		while (temp.move <= 8)    //����̽��8������
		{
			int row = temp.row + direction.get(temp.move, 1);
			int column = temp.column + direction.get(temp.move, 2);
			if (row == end.row&&column == end.column&&mark.get(row, column) == 0)  //�ߵ�����
			{
				//printPath();
				mark.set(row, column, 1);  //���Ϊ�߹�
				Path end(row, column, temp.move);
				path.push(end);
				return true;
			}
			if (map.get(row, column) == 0 && mark.get(row, column) == 0)  //���������û��̽����
			{
				mark.set(row, column, 1);  //���Ϊ�߹�
				path.push(temp);    //�����õ���ջ
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

//��ӡ�Թ�·��
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

//����Direction
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