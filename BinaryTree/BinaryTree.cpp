#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include"BinaryTree.h"

//节点函数
template<class DataType>
Node<DataType>::Node()
{
	rightLink = leftLink = NULL;
}

template<class DataType>
Node<DataType>::Node(const DataType _data)
{
	data = _data;
	rightLink = leftLink = NULL;
}

//二叉树函数
//无参构造函数
template<class DataType>
BinaryTree<DataType>::BinaryTree()
{
	root = NULL;
	insertFlag = NULL;
	lrFlag = true;
}
//插入数值
template<class DataType>
void BinaryTree<DataType>::insert(const DataType &_data)
{
	if (root == NULL)
	{
		Node<DataType>* insertData = new Node<DataType>(_data);
		root = insertFlag = insertData;
		return;
	}
	else
	{
		if (lrFlag)
		{
			Node<DataType>* insertData = new Node<DataType>(_data);
			nodeQueue.push(insertData);
			insertFlag->leftLink = insertData;
			lrFlag = false;
		}
		else
		{
			Node<DataType>* insertData = new Node<DataType>(_data);
			nodeQueue.push(insertData);
			insertFlag->rightLink = insertData;
			insertFlag = nodeQueue.front();
			nodeQueue.pop();
			lrFlag = true;
		}
	}
}
//插入空值
template<class DataType>
void BinaryTree<DataType>::insertNull()
{
	if (root == NULL)
		return;
	else
	{
		if (lrFlag)
			lrFlag = false;
		else
		{
			insertFlag = nodeQueue.front();
			nodeQueue.pop();
			lrFlag = true;
		}
	}
}

//先序遍历递归函数
template<class DataType>
void BinaryTree<DataType>::recursivePreOrder(Node<DataType> *_root, void(*visit)(DataType &_data))
{
	if (_root != NULL)
	{
		(*visit)(_root->data);
		recursivePreOrder(_root->leftLink, visit);
		recursivePreOrder(_root->rightLink, visit);
	}
}

//中序遍历递归函数
template<class DataType>
void BinaryTree<DataType>::recursiveInOrder(Node<DataType> *_root, void(*visit)(DataType &_data))
{
	if (_root != NULL)
	{
		recursiveInOrder(_root->leftLink, visit);
		(*visit)(_root->data);
		recursiveInOrder(_root->rightLink, visit);
	}
}

//后序遍历递归函数
template<class DataType>
void BinaryTree<DataType>::recursivePostOrder(Node<DataType> *_root, void(*visit)(DataType &_data))
{
	if (_root != NULL)
	{
		recursivePostOrder(_root->leftLink, visit);
		recursivePostOrder(_root->rightLink, visit);
		(*visit)(_root->data);
	}
}
//先序遍历
template<class DataType>
void BinaryTree<DataType>::perOrder(void(*visit)(DataType &_data))
{
	recursivePreOrder(root, visit);
}
//中序遍历
template<class DataType>
void BinaryTree<DataType>::inOrder(void(*visit)(DataType &_data))
{
	recursiveInOrder(root, visit);
}
//后序遍历
template<class DataType>
void BinaryTree<DataType>::postOrder(void(*visit)(DataType &_data))
{
	recursivePostOrder(root, visit);
}
#endif