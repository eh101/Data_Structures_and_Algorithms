#include<iostream>
#include"..\Table\Table.h"
using namespace std;

#define MAX 65536

typedef char VexTyoe;
typedef int AdjType;

class Edge{
public:
	int start_vex, stop_vex;
	AdjType weight;
	//重载输出
	friend ostream &operator<<(ostream &out, const Edge &Edge);
};

ostream &operator<<(ostream &out, const Edge &Edge){
	return out << "(" << Edge.start_vex << "," << Edge.stop_vex << "," << Edge.weight << ")";
}

class GraphMatrix{
	int VN;  //顶点数
	VexTyoe *vexs;
	Table<AdjType> arcs;
public:
	GraphMatrix();
	GraphMatrix(const int, AdjType *);
	int getVN(){ return VN; }
	AdjType getArcs(int _row, int _column){ return arcs.get(_row, _column); }
	void setArcs(int _row, int _column, AdjType adj){ arcs.set(_row, _column, adj); }
};

GraphMatrix::GraphMatrix(){
	VN = 0;
	vexs = NULL;
}

GraphMatrix::GraphMatrix(const int _VN, AdjType *_AdjType){
	VN = _VN;
	vexs = new VexTyoe[_VN];
	arcs.set(_VN, _VN);
	arcs.set(_AdjType);
}

//prim求MST
void prim(GraphMatrix *pgraph, Edge mst[]){
	AdjType weight;
	Edge edge;

	for (int i = 0; i < (*pgraph).getVN() - 1; i++)
	{
		mst[i].start_vex = 0;
		mst[i].stop_vex = i + 1;
		mst[i].weight = (*pgraph).getArcs(1, i + 2);
	}

	for (int i = 0; i < (*pgraph).getVN() - 1; i++)
	{
		weight = MAX;
		int min = i;
		for (int j = i; j < (*pgraph).getVN() - 1; j++)

			if (mst[j].weight < weight)
			{
			weight = mst[j].weight;
			min = j;
			}
		edge = mst[min];
		mst[min] = mst[i];
		mst[i] = edge;
		int vx = mst[i].stop_vex;
		for (int j = i + 1; j < (*pgraph).getVN() - 1; j++)
		{
			int vy = mst[j].stop_vex;
			weight = (*pgraph).getArcs(vx + 1, vy + 1);
			if (weight < mst[j].weight)
			{
				mst[j].weight = weight;
				mst[j].start_vex = vx;
			}
		}
	}
}
//kruskal求MST
bool kruskal(GraphMatrix *pgraph, Edge mst[]){
	AdjType minweight;
	int VN = (*pgraph).getVN();
	int num = 0;
	int *status = new int[VN];
	for (int i = 0; i < VN; i++)
		status[i] = i;
	while (num < VN - 1){
		minweight = MAX;
		int start, stop;
		for (int i = 0; i < VN - 1; i++){
			for (int j = i + 1; j < VN; j++){
				if ((*pgraph).getArcs(i + 1, j + 1) < minweight){
					start = i;
					stop = j;
					minweight = (*pgraph).getArcs(i + 1, j + 1);
				}
			}
		}
		if (minweight == MAX)
			return false;  //无法生成MST
		if (status[start] != status[stop]){
			mst[num].start_vex = start;
			mst[num].stop_vex = stop;
			mst[num].weight = (*pgraph).getArcs(start + 1, stop + 1);
			num++;
			int j = status[stop];
			for (int i = 0; i < VN; i++)
				if (status[i] == j)
					status[i] = status[start];
		}
		(*pgraph).setArcs(start + 1, stop + 1, MAX);
	}
	return true;
}

int main()
{
	AdjType ad[] = {
		0, 10, MAX, MAX, 19, 21,
		10, 0, 5, 6, MAX, 11,
		MAX, 5, 0, 6, MAX, MAX,
		MAX, 6, 6, 0, 18, 14,
		19, MAX, MAX, 18, 0, 33,
		21, 11, MAX, 14, 33, 0
	};
	GraphMatrix gm(6, ad);
	int VN = gm.getVN();
	Edge *mst = new Edge[VN - 1];
	prim(&gm, mst);
	for (int i = 0; i < VN - 1; i++){
		cout << mst[i];
		if (i < VN - 2)
			cout << ",";
	}
	cout << endl;

	if (kruskal(&gm, mst)){
		for (int i = 0; i < VN - 1; i++){
			cout << mst[i];
			if (i < VN - 2)
				cout << ",";
		}
		cout << endl;
	}
		
	return 0;
}