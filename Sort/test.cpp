#include<iostream>
#include<time.h>
using namespace std;

//储存结构
typedef int KeyType;
typedef int DataType;
typedef struct{
	KeyType key;
	DataType info;
}RecordNode;
typedef struct{
	int n;
	RecordNode *recode;
}SortObject;

//两组归并
void merge(RecordNode *r, RecordNode *r1, int low, int m, int high)
{
	int i, j, k;
	i = low;
	j = m + 1;
	k = low;
	while ((i <= m) && (j <= high))
	{
		if (r[i].key <= r[j].key)
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}
	while (i <= m)
		r1[k++] = r[i++];
	while (j <= high)
		r1[k++] = r[j++];
}

//一趟归并
void mergePass(RecordNode *r, RecordNode *r1, int n, int length)
{
	int j, i = 0;
	while (i+2*length-1<n)
	{
		merge(r, r1, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}
	if (i + length - 1 < n - 1)
		merge(r, r1, i, i + length - 1, n - 1);
	else
		for (j = i; j < n; j++)
			r1[j] = r[j];
}

//二路归并
void mergeSort(SortObject *pvector)
{
	RecordNode *record = new RecordNode[pvector->n];
	int length = 1;
	while (length < pvector->n)
	{
		mergePass(pvector->recode, record, pvector->n, length);
		length *= 2;
		mergePass(record, pvector->recode, pvector->n, length);
		length *= 2;
	}
}

void printSortObject(SortObject *pvector)
{
	RecordNode *temp = pvector->recode;
	for (int i = 0; i < pvector->n; i++)
	{
		cout << temp->key << " ";
		temp++;
	}
	cout << endl;
}

int main()
{
	RecordNode reno[10];
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
	{
		reno[i].key = rand()%100;
	}
	SortObject *sb=new SortObject;
	sb->n = 10;
	sb->recode = reno;
	cout << "排序前：";
	printSortObject(sb);
	mergeSort(sb);
	cout << "排序后：";
	printSortObject(sb);
}