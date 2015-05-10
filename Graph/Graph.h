#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include"Table.h"
using namespace std;

#define MAX 65536

typedef char VexTyoe;
typedef int AdjType;

//边
class Edge{
public:
	int start_vex, stop_vex;
	AdjType weight;
	//重载输出
	friend ostream &operator<<(ostream &, const Edge &);
};

//图的邻接矩阵
class GraphMatrix{
	VexTyoe *vexs;
	Table<AdjType> arcs;
public:
	GraphMatrix();
	GraphMatrix(const int, AdjType *);
	void set(const int, AdjType *);
	//取邻接矩阵的某个值
	AdjType getArcs(const int, const int);
	//设置邻接矩阵为某个值
	void setArcs(const int, const int, const AdjType);
};

//图
class Graph{
protected:
	GraphMatrix graphMatrix;    //邻接矩阵
	int VN;    //边数
	Edge *mst;    //最小生成树
public:
	Graph();
	Graph(const int _VN, AdjType *);
	int getVN();
	void set(const int _VN, AdjType *);
	//prim求MST
	void bulidMST_prim();
	//kruskal求MST
	bool bulidMST_kruskal();
	//打印MST
	void printMST();
};

#endif