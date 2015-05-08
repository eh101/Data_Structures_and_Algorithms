#ifndef LINKSTACK_CPP
#define LINKSTACK_CPP
#include "LinkStack.h"

//����Node�Ĺ��캯��
template<class T>
Node<T>::Node(){ link = NULL; }

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