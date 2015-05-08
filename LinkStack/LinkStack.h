#ifndef LINKSTACK_H
#define LINKSTACK_H

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

#include "LinkStack.cpp"
#endif