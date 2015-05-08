#ifndef BINARY_TREE_CPP_X
#define BINARY_TREE_CPP_X
#include "Binary_tree.h"

//节点函数
//结点无参构造函数
template<class Entry>
Binary_node<Entry>::Binary_node()
{
	left = right = NULL;
}

//初始化为x的构造函数
template<class Entry>
Binary_node<Entry>::Binary_node(const Entry &x)
{
	left = right = NULL;
	data = x;
}

//二叉树函数
//拷贝构造函数
template<class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry>&original)
{
	root = original.get_root();
}


//中序遍历的递归函数
template<class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry>*sub_root, void(*visit)(Entry&))
{
	if(sub_root!=NULL)
	{
		recursive_inorder(sub_root->left, visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right, visit);
	}
}

//中序遍历
template<class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry&))
{
	recursive_inorder(root, visit);
}

//后序遍历的递归函数
template<class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry>*sub_root, void (*visit)(Entry&))
{
	if (sub_root!=NULL)
	{
		recursive_postorder(sub_root->left, visit);
		recursive_postorder(sub_root->right, visit);
		(*visit)(sub_root->data);
	}
}

//后序遍历
template<class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry&))
{
	recursive_postorder(root, visit);
}

//先序遍历的递归函数
template<class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry>*sub_root, void (*visit)(Entry&))
{
	if (sub_root!=NULL)
	{
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left, visit);
		recursive_preorder(sub_root->right, visit);
	}
}

//先序遍历
template<class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry&))
{
	recursive_preorder(root, visit);
}

//树的高度，
template<class Entry>
int Binary_tree<Entry>::height() const
{
	return recursive_height(root);
}

//取两者中最大，辅助函数
#define max MAX
template<class Comparable>
Comparable MAX(const Comparable& a, const Comparable& b)
{
	return a > b ? a : b;
}

//求树高的递归函数
template<class Entry>
int Binary_tree<Entry>::recursive_height(const Binary_node<Entry>*root) const
{
	if(root == NULL)
		return 0;
	else
		return 1 + max(recursive_height(root->left) , recursive_height(root->right)) ;
}
#undef max

//树的大小，即树的节点
template<class Entry>
int Binary_tree<Entry>::size() const
{
	return recursive_size(root);
}

//求树大小的递归函数
template<class Entry>
int Binary_tree<Entry>::recursive_size(const Binary_node<Entry>*root) const
{
	if(root == NULL)
		return 0;
	else
		return 1 + recursive_size(root->left) + recursive_size(root->right) ;
}

//判空
template<class Entry>
bool Binary_tree<Entry>::empty() const
{
	return root == NULL;
}

//insert x to the tree
template<class Entry>
void Binary_tree<Entry>::insert(const Entry& x)
{
#if 0
	recursive_insert(root, x);
#else
	if (root == NULL)
	{
		Binary_node<Entry>* ins_data = new Binary_node<Entry>(x);
		root = insflag = ins_data;
		return;
	}
	else
	{
		if (lrflag)
		{
			Binary_node<Entry>* ins_data = new Binary_node<Entry>(x);
			nodeQueue.push(ins_data);
			insflag->left = ins_data;
			lrflag = false;
		}
		else
		{
			Binary_node<Entry>* ins_data = new Binary_node<Entry>(x);
			nodeQueue.push(ins_data);
			insflag->right = ins_data;
			insflag = nodeQueue.front();
			nodeQueue.pop();
			lrflag = true;
		}
	}

#endif
}
template<class Entry>
void Binary_tree<Entry>::insertNull()
{
	if (root == NULL)
		return;
	else
	{
		if (lrflag)
			lrflag = false;
		else
		{
			insflag = nodeQueue.front();
			nodeQueue.pop();
			lrflag = true;
		}
	}
}

//the recursive function of insert, 
//insert x in the less height side, 
//if both sides are same height then insert to the left
//第一个参数必须使用引用否则插入失败,而其他不涉及数据改动的函数则不需要
//引用传参时不会发生值拷贝,如果不加引用,会先在函数的栈空间拷贝一个root,但当函数
//结束时这个拷贝就会被销毁,所以会导致插入失败
template<class Entry>
void Binary_tree<Entry>::recursive_insert(Binary_node<Entry>*&sub_root, const Entry& x)
{
	if(sub_root == NULL)
	{
		Binary_node<Entry>* ins_data = new Binary_node<Entry>(x);
		sub_root = ins_data;
		return;
	}
	else
	{
		if(recursive_height(sub_root->left) > recursive_height(sub_root->right))
			recursive_insert(sub_root->right, x);
		else
			recursive_insert(sub_root->left, x);
	}
}

//析构函数
template<class Entry>
Binary_tree<Entry>::~Binary_tree()
{
 	clear();
}

template<class Entry>
void Binary_tree<Entry>::clear()
{
	recursive_clear(root);
}
//recursive function for destroy tree
template<class Entry>
void Binary_tree<Entry>::recursive_clear(Binary_node<Entry>*&sub_root)
{//两个版本都OK
#if 0
	if(sub_root != NULL)
	{
		recursive_clear(sub_root->left);
		recursive_clear(sub_root->right);
		delete sub_root;
		sub_root = NULL;
	}
#else
	if(sub_root->left!=NULL)
		recursive_clear(sub_root->left);
	if(sub_root->right!=NULL)
		recursive_clear(sub_root->right);
	delete sub_root;
	sub_root = NULL;
#endif
}

//取树根
template<class Entry>
const Binary_node<Entry>* Binary_tree<Entry>::get_root() const
{
	return root;
}

//深度拷贝
template<class Entry>
Binary_tree<Entry>& Binary_tree<Entry>::operator =(const Binary_tree<Entry>&original)
{
	equal(root, original.get_root());
	return *this;
}

//判读两棵树是否相等
template<class Entry>
void Binary_tree<Entry>::equal(Binary_node<Entry>*&sub_root,const Binary_node<Entry>*orig_node)
{
	if(empty())
		sub_root = new Binary_node<Entry>(orig_node->data);
	if(orig_node->left!=NULL)
	{
		sub_root->left = new Binary_node<Entry>(orig_node->left->data);
		equal(root->left, orig_node->left);
	}
	if(orig_node->right!=NULL)
	{
		sub_root->right = new Binary_node<Entry>(orig_node->right->data);
		equal(root->right, orig_node->right);
	}
}

//reverse the binary tree,  exchange left and right
template<class Entry>
void Binary_tree<Entry>::reverse()
{
	recursive_reverse(root);
}

template<class Entry>
void Binary_tree<Entry>::recursive_reverse(Binary_node<Entry> * & sub_root)
{
	if(sub_root!=NULL)
	{
		Binary_node<Entry>* temp = NULL;
		temp = sub_root->left;
		sub_root->left = sub_root->right;
		sub_root->right = temp;
		recursive_reverse(sub_root->left);
		recursive_reverse(sub_root->right);
	}
}
#endif