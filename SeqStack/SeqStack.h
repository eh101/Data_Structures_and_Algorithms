#ifndef SEQSTACK_H
#define SEQSTACK_H

//看见一大堆东西不要惊讶，类模板的实现只能写在头文件里！

//链式栈的节点
template <class T>
class Node
{
public:
	T data;
	Node *link;
	//Node的构造函数
	Node(){ link = NULL; }
};

//链式栈
template <class T>
class SeqStack
{
private:
	Node<T> *Ptop;
public:
	//SeqStack的构造函数
	SeqStack<T>(){ Ptop = NULL; }
	//判空函数，为空时返回true
	bool empty(){ return(Ptop == NULL); }
	//压栈，将inputData压入
	bool push(T inputData)
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
	bool pop()
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
	T top()
	{
		if (empty())
			cout << "Stack is empty!!\n";
		else
			return Ptop->data;
	}
	//得出栈的大小
	int size()
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
};
#endif