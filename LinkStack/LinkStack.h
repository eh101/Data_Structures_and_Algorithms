#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<iostream>
using namespace std;

//����һ��Ѷ�����Ҫ���ȣ���ģ���ʵ��ֻ��д��ͷ�ļ��

//��ʽջ�Ľڵ�
template <class T>
class Node
{
public:
	T data;
	Node *link;
	//����Node���캯��
	Node();
};

//����Node�Ĺ��캯��
template<class T>
Node<T>::Node(){ link = NULL; }

//��ʽջ
template <class T>
class LinkStack
{
private:
	Node<T> *Ptop;
public:
	//LinkStack�Ĺ��캯��
	LinkStack();
	//�пպ�����Ϊ��ʱ����true
	bool empty();
	//ѹջ����inputDataѹ��
	bool push(T inputData);
	//��Ptopָ��Ľڵ�����ݳ�ջ
	bool pop();
	//ȡ��Ptopָ��Ľڵ�����ݣ����ı�ջ
	T top();
	//�ó�ջ�Ĵ�С
	int size();
};

//LinkStack�Ĺ��캯��
template <class T>
LinkStack<T>::LinkStack(){ Ptop = NULL; }

//�пպ�����Ϊ��ʱ����true
template <class T>
bool LinkStack<T>::empty(){ return Ptop == NULL; }

//ѹջ����inputDataѹ��
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

//��Ptopָ��Ľڵ�����ݳ�ջ
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

//ȡ��Ptopָ��Ľڵ�����ݣ����ı�ջ
template <class T>
T LinkStack<T>::top()
{
	if (empty())
		cout << "Stack is empty!!\n";
	else
		return Ptop->data;
}

//�ó�ջ�Ĵ�С
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