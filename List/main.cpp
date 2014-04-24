#include<iostream>
using namespace std;

struct Node;
typedef struct Node *PNode;
struct Node
{
	int date;
	PNode link;
};
typedef struct Node *LinkList;

LinkList createNullList_link()
{
	LinkList llist = new Node();
	if (llist != NULL)
		return llist;
	else
		cout << "Out of space!! Can't create list!\n";
}

bool insertPost_link(LinkList llist, PNode p, int x)
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

bool printList_link(LinkList llist)
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

int main()
{
	int x;
	LinkList list1 = createNullList_link();
	cout << "Enter 5 number:\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		insertPost_link(list1, list1, x);
	}
	printList_link(list1);
	return 0;
}