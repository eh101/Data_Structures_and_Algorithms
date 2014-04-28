#include<iostream>
using namespace std;

typedef int DataType; //DataType为DataType类型
typedef struct Node *LinkList, *PNode;
struct Node
{
	DataType info;
	PNode link;
};

LinkList createNullList_link() //大家好，我是被拿来创建一个空链表的哦(oﾟωﾟo)
{
	LinkList llist = new Node();
	if (llist != NULL)
		return llist;
	else
		cout << "Out of space!! Can't create list!\n";
}

bool insertPost_link(LinkList llist, PNode p, DataType x) //在p后插入数据x
{
	PNode q = new Node();
	if (q == NULL)
	{
		cout << "Out of space!!! Can't create list!\n";
		return false;
	}
	else
	{
		q->info = x;
		q->link = p->link;
		p->link = q;
		return true;
	}
}

bool printList_link(LinkList llist) //打印llist
{
	if (llist->link == NULL)
	{
		cout << "List is null!!!\n";
		return false;
	}
	else
	{
		PNode p = llist->link;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
		return true;
	}
}

PNode findByValue_Link(LinkList llist, DataType x) //按值x查找位置（地址）
{
	PNode p = llist;
	while (p != NULL&&p->info != x) //未找到值则返回NULL
	{
		p = p->link;
	}
	return p;
}

bool deleteByValue_Link(LinkList llist, PNode p) //我可以被拿来删除llist中地址为p的节点哦╭（′▽‘）╭
{
	PNode q = llist;
	if (p == NULL)
		return false;
	while (q != NULL&&q->link != p)
	{
		q = q->link;
	}
	if (q == NULL)
		return false;
	q->link = p->link;
	delete(p);
	return true;
}

PNode findRearNode_Link(LinkList llist) //查找llist的尾节点地址
{
	PNode r = llist;
	while (r->link != NULL)
	{
		r = r->link;
	}
	return r;
}

DataType findMin_Link(LinkList llist) //找出表中最小的值
{
	PNode p = llist->link;
	DataType temp = p->info;
	while (p->link != NULL)
	{
		p = p->link;
		if (temp > p->info)
			temp = p->info;
	}
	return temp;
}

DataType findMax_Link(LinkList llist) //找出表中最大的值
{
	PNode p = llist->link;
	DataType temp = p->info;
	while (p->link != NULL)
	{
		p = p->link;
		if (temp < p->info)
			temp = p->info;
	}
	return temp;
}

int main()
{
	DataType x;
	LinkList list1 = createNullList_link();
	cout << "Enter 5 number:\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		//insertPost_link(list1, list1, x);
		insertPost_link(list1, findRearNode_Link(list1), x); //伪尾插建表，缺点是每次都要查找尾结点
	}
	printList_link(list1);
	//cout << "Address of 10 is " << findByValue_Link(list1, 10) << endl;
	//if (deleteByValue_Link(list1, findByValue_Link(list1, 10))) //删除值为10的节点
	//	cout << "Delete completed!\n";
	//else
	//	cout << "Delete failed!\n";
	//printList_link(list1);
	cout << "The min in the list is: " << findMin_Link(list1) << endl;
	cout << "The max in the list is: " << findMax_Link(list1) << endl;
	return 0;
}