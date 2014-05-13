#ifndef SEQSTACK_H
#define SEQSTACK_H

//����һ��Ѷ�����Ҫ���ȣ���ģ���ʵ��ֻ��д��ͷ�ļ��

//��ʽջ�Ľڵ�
template <class T>
class Node
{
public:
	T data;
	Node *link;
	//Node�Ĺ��캯��
	Node(){ link = NULL; }
};

//��ʽջ
template <class T>
class SeqStack
{
private:
	Node<T> *Ptop;
public:
	//SeqStack�Ĺ��캯��
	SeqStack<T>(){ Ptop = NULL; }
	//�пպ�����Ϊ��ʱ����true
	bool empty(){ return(Ptop == NULL); }
	//ѹջ����inputDataѹ��
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
	//��Ptopָ��Ľڵ�����ݳ�ջ
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
	//ȡ��Ptopָ��Ľڵ�����ݣ����ı�ջ
	T top()
	{
		if (empty())
			cout << "Stack is empty!!\n";
		else
			return Ptop->data;
	}
	//�ó�ջ�Ĵ�С
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