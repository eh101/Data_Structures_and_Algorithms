#ifndef LINKSTACK_H
#define LINKSTACK_H

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

#include "LinkStack.cpp"
#endif