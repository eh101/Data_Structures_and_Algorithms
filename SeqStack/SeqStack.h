#ifndef SEQSTACK_H
#define SEQSTACK_H

//typedef int T;

//��ʽջ�Ľڵ�
//template<template T>
//typedef class Node *PNode;
template <class T>
class Node
{
public:
	T data;
	Node *link;
	Node();
};

//��ʽջ
template <class T>
class SeqStack
{
private:
	Node<T> *Ptop;
public:
	SeqStack<T>();
	bool empty();
	bool push(T);
	bool pop();
	T top();
	int size();
};
#endif