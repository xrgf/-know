#include<iostream>
#include<ctime>
using namespace std;
typedef struct heap
{
	int* headnum;
	int cursize;
}Heap,*IPHeap;
IPHeap creatheap(int max)
{
	IPHeap heap = new Heap;
	heap->cursize = 0;//大顶堆中下标为0的不存储数据
	heap->headnum = new int[max + 1];
	return heap;
}
void adjustheap(IPHeap heap, int cursize)
{
	int max = heap->headnum[cursize];
	
	while (cursize >1)
	{
		if (max > heap->headnum[cursize / 2])
		{
			int temp = heap->headnum[cursize];
			heap->headnum[cursize]=heap->headnum[cursize / 2];
			heap->headnum[cursize / 2] = temp;
			cursize /= 2;
		}
		else
		{
			break;
		}
	}
	
}
void insertbyheap(IPHeap heap,int data)
{
	heap->headnum[++heap->cursize] = data;
	//插入数据后向上调整 
	adjustheap(heap, heap->cursize);
}
int popheap(IPHeap heap)
{

	int max = heap->headnum[1];
	int parent = 1;
	int child = parent * 2;
	while (child <= heap->cursize)
	{
		int temp = heap->headnum[child];
		if (child + 1 < heap->cursize && heap->headnum[child] < heap->headnum[child + 1])
		{
			temp = heap->headnum[++child];
		}
		heap->headnum[parent] = temp;
		parent = child;
		child *= 2;
	}
	heap->headnum[parent] = heap->headnum[heap->cursize];
	while (parent>1)
	{
		if (heap->headnum[parent] > heap->headnum[parent / 2])
		{
			int temp = heap->headnum[parent];
			heap->headnum[parent] = heap->headnum[parent / 2];
			heap->headnum[parent / 2] = temp;
		}
		parent /= 2;
	}
	 heap->cursize--;
	return max;
}
void printfheap(IPHeap heap)
{
	for (int i = 1; i < heap->cursize + 1; i++)
	{
		cout << heap->headnum[i] << "\t";
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	IPHeap heap = creatheap(10);
	for (int i = 1; i <11; i++)
	{
		insertbyheap(heap, rand() % 100);
	}
	printfheap(heap);
	cout << endl;
	while(heap->cursize!=0)
	cout << popheap(heap)<<"\t";
	return 0;
}