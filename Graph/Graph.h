#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include"Table.h"
using namespace std;

#define MAX 65536

typedef char VexTyoe;
typedef int AdjType;

//��
class Edge{
public:
	int start_vex, stop_vex;
	AdjType weight;
	//�������
	friend ostream &operator<<(ostream &, const Edge &);
};

//ͼ���ڽӾ���
class GraphMatrix{
	VexTyoe *vexs;
	Table<AdjType> arcs;
public:
	GraphMatrix();
	GraphMatrix(const int, AdjType *);
	void set(const int, AdjType *);
	//ȡ�ڽӾ����ĳ��ֵ
	AdjType getArcs(const int, const int);
	//�����ڽӾ���Ϊĳ��ֵ
	void setArcs(const int, const int, const AdjType);
};

//ͼ
class Graph{
protected:
	GraphMatrix graphMatrix;    //�ڽӾ���
	int VN;    //����
	Edge *mst;    //��С������
public:
	Graph();
	Graph(const int _VN, AdjType *);
	int getVN();
	void set(const int _VN, AdjType *);
	//prim��MST
	void bulidMST_prim();
	//kruskal��MST
	bool bulidMST_kruskal();
	//��ӡMST
	void printMST();
};

#endif