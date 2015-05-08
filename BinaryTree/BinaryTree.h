#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<queue>
using namespace std;
//二叉树的节点
template <class DataType>
class Node{
public:
	DataType data;
	Node *leftLink, *rightLink;
	Node();
	Node(const DataType);
};


//链式二叉树
template<class DataType>
class BinaryTree{
private:
	//遍历树的递归函数
	void recursivePreOrder(Node<DataType> *, void(*)(DataType &));
	void recursiveInOrder(Node<DataType> *, void(*)(DataType &));
	void recursivePostOrder(Node<DataType> *, void(*)(DataType &));
protected:
	//树根
	Node<DataType> *root;
	//总是指向当前插入点的父节点
	Node<DataType>* insertFlag;
	//标志当前插入是左子树还是右子树
	bool lrFlag;
	//用于保存节点的队列
	queue<Node<DataType>*> nodeQueue;
public:
	BinaryTree();
	void insert(const DataType &);
	void insertNull();
	void perOrder(void(*)(DataType &));
	void inOrder(void(*)(DataType &));
	void postOrder(void(*)(DataType &));
};

#include"BinaryTree.cpp"
#endif