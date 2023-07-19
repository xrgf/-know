#include<iostream>
#include<assert.h>
#include<ctime>
using namespace std;
#define MAX 10
typedef struct heap
{
	int *data;
	int cursize;
}Heap,*LPHeap;
LPHeap creatheap()
{
	LPHeap heap = (LPHeap)malloc(sizeof(Heap));
	assert(heap);
	heap->cursize = 0;
	heap->data = (int*)malloc(sizeof(int) * MAX);
	assert(heap->data);
	return heap;
}
void adjuseheap(LPHeap heap, int cursize)
{
	int min = heap->data[cursize];

	while (cursize > 1)
	{
		if (min < heap->data[cursize / 2])
		{
			int temp = heap->data[cursize];
			heap->data[cursize] = heap->data[cursize / 2];
			heap->data[cursize / 2] = temp;
			cursize /= 2;
		}
		else
		{
			break;
		}
	}
}
void insertdata(LPHeap heap, int data)
{
	heap->data[++heap->cursize] = data;
	adjuseheap(heap, heap->cursize);
}
int  popheap(LPHeap heap)
{
	int min = heap->data[1];
	int parent = 1;
	int child = 2 * parent;

	while (heap->cursize >= child)
	{
		int temp = heap->data[child];
		if (child + 1 <= heap->cursize && heap->data[child] > heap->data[child + 1])
		{
			temp = heap->data[++child];
		}
		heap->data[parent] = temp;
		parent = child;
		child *= 2;
	}
	heap->data[parent] = heap->data[heap->cursize];
	heap->cursize--;
	while (parent > 1)
	{
		if (heap->data[parent] < heap->data[parent / 2])
		{
			int temp = heap->data[parent];
			heap->data[parent] = heap->data[parent / 2];
			heap->data[parent / 2] = temp;

		}
		else
		{
			break;
		}
		parent /= 2;
		
		
	}
	return min;

  	
}
int main()
{

	srand((unsigned int)time(NULL));
	LPHeap heap = creatheap();
	for (int i = 1; i < 11; i++)
	{
		insertdata(heap, rand() % 100);
	}
	cout << endl;
	for (int i = 1; i < 11; i++)
	{
		cout << heap->data[i]<<"\t";
	}
	cout << endl;
	while (heap->cursize != 0)
		cout << popheap(heap) << "\t";



	return 0;
}
