#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<queue>
using namespace std;
//�������Ľڵ�
template <class DataType>
class Node{
public:
	DataType data;
	Node *leftLink, *rightLink;
	Node();
	Node(const DataType);
};


//��ʽ������
template<class DataType>
class BinaryTree{
private:
	//�������ĵݹ麯��
	void recursivePreOrder(Node<DataType> *, void(*)(DataType &));
	void recursiveInOrder(Node<DataType> *, void(*)(DataType &));
	void recursivePostOrder(Node<DataType> *, void(*)(DataType &));
protected:
	//����
	Node<DataType> *root;
	//����ָ��ǰ�����ĸ��ڵ�
	Node<DataType>* insertFlag;
	//��־��ǰ����������������������
	bool lrFlag;
	//���ڱ���ڵ�Ķ���
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