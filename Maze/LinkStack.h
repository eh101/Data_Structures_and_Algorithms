#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<iostream>
using namespace std;

//看见一大堆东西不要惊讶，类模板的实现只能写在头文件里！

//链式栈的节点
template <class T>
class Node
{
public:
	T data;
	Node *link;
	//声明Node构造函数
	Node();
};

//定义Node的构造函数
template<class T>
Node<T>::Node(){ link = NULL; }

//链式栈
template <class T>
class LinkStack
{
private:
	Node<T> *Ptop;
public:
	//LinkStack的构造函数
	LinkStack();
	//判空函数，为空时返回true
	bool empty();
	//压栈，将inputData压入
	bool push(T inputData);
	//将Ptop指向的节点的数据出栈
	bool pop();
	//取出Ptop指向的节点的数据，不改变栈
	T top();
	//得出栈的大小
	int size();
};

//LinkStack的构造函数
template <class T>
LinkStack<T>::LinkStack(){ Ptop = NULL; }

//判空函数，为空时返回true
template <class T>
bool LinkStack<T>::empty(){ return Ptop == NULL; }

//压栈，将inputData压入
template <class T>
bool LinkStack<T>::push(T inputData)
{
	Node<T> *node = new Node<T>();
	if (node == NULL)
	{
		cout << "Out of space!!\n";
		return false;
	}
	else
	{
		node->data = inputData;
		node->link = Ptop;
		Ptop = node;
		return true;
	}
}

//将Ptop指向的节点的数据出栈
template <class T>
bool LinkStack<T>::pop()
{
	if (empty())
	{
		cout << "Stack is empty!!\n";
		return false;
	}
	else
	{
		Node<T> *p = Ptop;
		Ptop = Ptop->link;
		delete p;
		return true;
	}
}

//取出Ptop指向的节点的数据，不改变栈
template <class T>
T LinkStack<T>::top()
{
	if (empty())
		cout << "Stack is empty!!\n";
	else
		return Ptop->data;
}

//得出栈的大小
template <class T>
int LinkStack<T>::size()
{
	int i = 0;
	Node<T> *p = Ptop;
	while (p != NULL)
	{
		i++;
		p = p->link;
	}
	return i;
}

#endif