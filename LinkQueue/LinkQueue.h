#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include<iostream>
using namespace std;

//����һ��Ѷ�����Ҫ���ȣ���ģ���ʵ��ֻ��д��ͷ�ļ��

//��ʽ���еĽڵ�
template<class T>
class Node
{
public:
	T data;
	Node *link;
	//Node�Ĺ��캯��
	Node();
};

//Node�Ĺ��캯��
template<class T>
Node<T>::Node(){ link = NULL; }

template<class T>
class LinkQueue
{
private:
	Node<T> *fPointer, *rPointer;
public:
	//���캯����ʼ��front,rearΪNULL
	LinkQueue();
	//�ж϶����Ƿ�Ϊ��
	bool empty();
	//���
	bool push(T);
	//����ͷԪ�س���
	bool pop();
	//ȡ��ͷԪ�أ����ı����
	T front();
	//ȡ��βԪ�أ����ı����
	T back();
	//������еĳ���
	int size();
};

//���캯����ʼ��front,rearΪNULL
template<class T>
LinkQueue<T>::LinkQueue()
{
	fPointer = NULL;
	rPointer = NULL;
}

//�пպ�����Ϊ��ʱ����true
template<class T>
bool LinkQueue<T>::empty()
{
	return fPointer == NULL;
}

//��input���
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

//����ͷԪ�س���
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

//ȡ��ͷԪ�أ����ı����
template<class T>
T LinkQueue<T>::front()
{
	if (!empty())
		return fPointer->data;
}

//ȡ��βԪ�أ����ı����
template<class T>
T LinkQueue<T>::back()
{
	if (!empty())
		return rPointer->data;
}

//������еĳ���
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