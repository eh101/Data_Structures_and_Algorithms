#ifndef SEQSTACK_H
#define SEQSTACK_H

//typedef int T;

//链式栈的节点
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

//链式栈
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