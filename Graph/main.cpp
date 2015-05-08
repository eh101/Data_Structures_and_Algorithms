#include<iostream>
#include"Graph.h"
using namespace std;

int main(){
	AdjType ad[] = {
		0, 10, MAX, MAX, 19, 21,
		10, 0, 5, 6, MAX, 11,
		MAX, 5, 0, 6, MAX, MAX,
		MAX, 6, 6, 0, 18, 14,
		19, MAX, MAX, 18, 0, 33,
		21, 11, MAX, 14, 33, 0
	};
	Graph g(6, ad);
	g.bulidMST_prim();
	cout << "prim算法生成的MST:\n";
	g.printMST();
	g.bulidMST_kruskal();
	cout << "kruskal算法生成的MST:\n";
	g.printMST();
	return 0;
}