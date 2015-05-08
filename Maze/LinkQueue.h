#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include<iostream>
using namespace std;

//看见一大堆东西不要惊讶，类模板的实现只能写在头文件里！

//链式队列的节点
template<class T>
class Node
{
public:
	T data;
	Node *link;
	//Node的构造函数
	Node();
};

//Node的构造函数
template<class T>
Node<T>::Node(){ link = NULL; }

template<class T>
class LinkQueue
{
private:
	Node<T> *fPointer, *rPointer;
public:
	//构造函数初始化front,rear为NULL
	LinkQueue();
	//判断队列是否为空
	bool empty();
	//入队
	bool push(T);
	//将队头元素出队
	bool pop();
	//取队头元素，不改变队列
	T front();
	//取队尾元素，不改变队列
	T back();
	//计算队列的长度
	int size();
};

//构造函数初始化front,rear为NULL
template<class T>
LinkQueue<T>::LinkQueue()
{
	fPointer = NULL;
	rPointer = NULL;
}

//判空函数，为空时返回true
template<class T>
bool LinkQueue<T>::empty()
{
	return fPointer == NULL;
}

//将input入队
template<class T>
bool LinkQueue<T>::push(T input)
{
	Node<T> *node = new Node<T>();
	if (node == NULL)
		return false;
	else
	{
		node->data = input;
		if (empty())
			fPointer = node;
		else
			rPointer->link = node;
		rPointer = node;
		return true;
	}
}

//将队头元素出队
template<class T>
bool LinkQueue<T>::pop()
{
	if (empty())
		return false;
	else
	{
		Node<T> *temp = fPointer;
		fPointer = fPointer->link;
		delete temp;
		return true;
	}
}

//取队头元素，不改变队列
template<class T>
T LinkQueue<T>::front()
{
	if (!empty())
		return fPointer->data;
}

//取队尾元素，不改变队列
template<class T>
T LinkQueue<T>::back()
{
	if (!empty())
		return rPointer->data;
}

//计算队列的长度
template<class T>
int LinkQueue<T>::size()
{
	Node<T>* temp = fPointer;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->link;
	}
	return i;
}

#endif