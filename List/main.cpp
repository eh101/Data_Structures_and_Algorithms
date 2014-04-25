#include<iostream>
using namespace std;

typedef struct Node *LinkList, *PNode;
struct Node
{
	int date;
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

bool insertPost_link(LinkList llist, PNode p, int x) //在p后插入数据x
{
	PNode q = new Node();
	if (q == NULL)
	{
		cout << "Out of space!!! Can't create list!\n";
		return false;
	}
	else
	{
		q->date = x;
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
			cout << p->date << " ";
			p = p->link;
		}
		cout << endl;
		return true;
	}
}

PNode findByValue_Link(LinkList llist, int x) //按值x查找位置（地址）
{
	PNode p = llist;
	while (p != NULL&&p->date != x) //未找到值则返回NULL
	{
		p = p->link;
	}
	return p;
}

bool deleteByValue_Link(LinkList llist, PNode p) //我可以被拿来删除llist中地址为p的节点哦╭（′▽‘）╭
{
	PNode q = llist;
	while (q != NULL&&q->link != p)
	{
		q = q->link;
	}
	if (q == NULL)
		return false;
	else
	{
		q->link = p->link;
		delete(p);
		return true;
	}
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

int main()
{
	int x;
	LinkList list1 = createNullList_link();
	cout << "Enter 5 number:\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		//insertPost_link(list1, list1, x);
		insertPost_link(list1, findRearNode_Link(list1), x); //伪尾插建表，缺点是每次都要查找尾结点
	}
	printList_link(list1);
	cout << "Address of 10 is " << findByValue_Link(list1, 10) << endl;
	if (deleteByValue_Link(list1, findByValue_Link(list1, 10))) //删除值为10的节点
		cout << "Delete completed!\n";
	else
		cout << "Delete failed!\n";
	return 0;
}