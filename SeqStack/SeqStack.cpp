#include<iostream>
#include"SeqStack.h"
using namespace std;

template <class T>
Node<T>::Node(){link = NULL;}

template <class T>
SeqStack<T>::SeqStack(){ Ptop = NULL; }

template <class T>
bool SeqStack<T>::empty()
{
	return(Ptop == NULL);
}

template <class T>
bool SeqStack<T>::push(T inputData)
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

template <class T>
bool SeqStack<T>::pop()
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

template <class T>
T SeqStack<T>::top(){
	if (empty())
		cout << "Stack is empty!!\n";
	else
		return Ptop->data;
}