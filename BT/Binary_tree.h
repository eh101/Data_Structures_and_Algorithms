#ifndef BINARY_TREE_H_XX
#define BINARY_TREE_H_XX
#include<queue>
using namespace std;
template<class Entry>
struct Binary_node
{
	Entry data;
	Binary_node<Entry>* left;
	Binary_node<Entry>* right;
	Binary_node();
	Binary_node(const Entry &x);
};

template<class Entry>
class Binary_tree
{
public:
	Binary_tree() :root(NULL){ lrflag = true; };
	~Binary_tree();
/*	Binary_tree();*/
	bool empty() const;
	void preorder(void (*visit)(Entry &));
	void inorder(void (*visit)(Entry &));
	void postorder(void (*visit)(Entry &));
	//Binary_tree大小
	int size() const;
	int height() const;
	void clear();
	void insert(const Entry& x);
	void insertNull();
	void reverse();
	Binary_tree(const Binary_tree<Entry>&original);
	Binary_tree & operator=(const Binary_tree<Entry>&original);
	const Binary_node<Entry>* get_root() const;
	//一些递归辅助函数
private:	
	int recursive_size(const Binary_node<Entry>*root) const;
	int recursive_height(const Binary_node<Entry>*root) const;
	void equal(Binary_node<Entry>*&sub_root,const Binary_node<Entry>*orig_node);
	void recursive_reverse(Binary_node<Entry> * & sub_root);
	void recursive_clear(Binary_node<Entry> * & sub_root);
	void recursive_insert(Binary_node<Entry> * & sub_root, const Entry& x);
	void recursive_inorder(Binary_node<Entry> * sub_root, void (*)(Entry &));
	void recursive_preorder(Binary_node<Entry> * sub_root, void (*)(Entry &));
	void recursive_postorder(Binary_node<Entry> * sub_root, void (*)(Entry &));
protected:
	Binary_node<Entry>* root;
	Binary_node<Entry>* insflag;
	bool lrflag;
	queue<Binary_node<Entry>*> nodeQueue;

};
#include "Binary_tree.cpp"
#endif