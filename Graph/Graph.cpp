#ifndef GRAPH_CPP
#define GRAPH_CPP
#include"Graph.h"

//�ߵķ���
ostream &operator<<(ostream &out, const Edge &Edge){
	return out << "(" << Edge.start_vex << "," << Edge.stop_vex << "," << Edge.weight << ")";
}

//�ڽӾ���ķ���
GraphMatrix::GraphMatrix(){
	vexs = NULL;
}

GraphMatrix::GraphMatrix(const int _VN, AdjType *_AdjType){
	set(_VN, _AdjType);
}

void GraphMatrix::set(const int _VN, AdjType *_AdjType){
	vexs = new VexTyoe[_VN];
	arcs.set(_VN, _VN);
	arcs.set(_AdjType);
}
//ȡ�ڽӾ����ĳ��ֵ
AdjType GraphMatrix::getArcs(int _row, int _column){ return arcs.get(_row, _column); }
//�����ڽӾ���Ϊĳ��ֵ
void GraphMatrix::setArcs(int _row, int _column, AdjType adj){ arcs.set(_row, _column, adj); }

//ͼ�ķ���
Graph::Graph(){
	VN = 0;
	mst = NULL;
}

Graph::Graph(const int _VN, AdjType *_AdjType){
	set(_VN, _AdjType);
}
//����ͼ�ı������ڽӾ���
void Graph::set(const int _VN, AdjType *_AdjType){
	VN = _VN;
	graphMatrix.set(_VN, _AdjType);
	mst = new Edge[_VN - 1];
}
//ȡ����
int Graph::getVN(){
	return VN;
}

void Graph::bulidMST_prim(){
	AdjType weight;
	Edge edge;

	for (int i = 0; i < VN - 1; i++)
	{
		mst[i].start_vex = 0;
		mst[i].stop_vex = i + 1;
		mst[i].weight = graphMatrix.getArcs(1, i + 2);
	}

	for (int i = 0; i < VN - 1; i++)
	{
		weight = MAX;
		int min = i;
		for (int j = i; j < VN - 1; j++)

			if (mst[j].weight < weight)
			{
			weight = mst[j].weight;
			min = j;
			}
		edge = mst[min];
		mst[min] = mst[i];
		mst[i] = edge;
		int vx = mst[i].stop_vex;
		for (int j = i + 1; j < VN - 1; j++)
		{
			int vy = mst[j].stop_vex;
			weight = graphMatrix.getArcs(vx + 1, vy + 1);
			if (weight < mst[j].weight)
			{
				mst[j].weight = weight;
				mst[j].start_vex = vx;
			}
		}
	}
}

bool Graph::bulidMST_kruskal(){
	AdjType minweight;
	int num = 0;
	int *status = new int[VN];
	for (int i = 0; i < VN; i++)
		status[i] = i;
	while (num < VN - 1){
		minweight = MAX;
		int start, stop;
		for (int i = 0; i < VN - 1; i++){
			for (int j = i + 1; j < VN; j++){
				if (graphMatrix.getArcs(i + 1, j + 1) < minweight){
					start = i;
					stop = j;
					minweight = graphMatrix.getArcs(i + 1, j + 1);
				}
			}
		}
		if (minweight == MAX)
			return false;  //�޷�����MST
		if (status[start] != status[stop]){
			mst[num].start_vex = start;
			mst[num].stop_vex = stop;
			mst[num].weight = graphMatrix.getArcs(start + 1, stop + 1);
			num++;
			int j = status[stop];
			for (int i = 0; i < VN; i++)
				if (status[i] == j)
					status[i] = status[start];
		}
		graphMatrix.setArcs(start + 1, stop + 1, MAX);
	}
	return true;
}

void Graph::printMST(){
	for (int i = 0; i < VN - 1; i++){
		cout << mst[i];
		if (i < VN - 2)
			cout << ",";
	}
	cout << endl;
}
#endif