#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<math.h>
#define MAX 5
typedef struct node
{
	int data;
	int height;
	struct node* Lchild;
	struct node* Rchild;
}Node,*LPNode;
typedef struct heap
{
	int* headnum;
	int cursize;
}Heap, * IPHeap;
//大顶堆
IPHeap creatheap(int max)//表示要存储的数据总个数
{
	IPHeap heap = (IPHeap)malloc(sizeof(Heap));
	heap->cursize = 0;//大顶堆中下标为0的不存储数据
	heap->headnum = (int*)malloc(sizeof(int) * (max + 1));
	return heap;
}
void adjustheap(IPHeap heap, int cursize)
{
	int max = heap->headnum[cursize];

	while (cursize > 1)
	{
		if (max > heap->headnum[cursize / 2])
		{
			int temp = heap->headnum[cursize];
			heap->headnum[cursize] = heap->headnum[cursize / 2];
			heap->headnum[cursize / 2] = temp;
			cursize /= 2;
		}
		else
		{
			break;
		}
	}

}
void insertbyheap(IPHeap heap, int data)
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
	while (parent > 1)
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
	
		printf("%d\t", heap->headnum[i]);
	}
}
//平衡二叉树
LPNode*  creatnode(int data)
{
	LPNode newnode = (LPNode)malloc(sizeof(Node));
	assert(newnode);
	newnode->data = data;
	newnode->height = 1;
	newnode->Lchild = newnode->Rchild = NULL;
	return &newnode;
}

int getheight(LPNode *root)
{
	if (root== NULL)
	{
		return 0;
	}
	return (*root)->height;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
 void updataheight(LPNode *root)
{
	 (*root)->height = max(getheight(&(*root)->Lchild), getheight(&(*root)->Rchild)) + 1;

}
int getblance_factor(LPNode* root)
{
	return getheight(&(*root)->Lchild) - getheight(&(*root)->Rchild);
}
void LL(Node ** root)
{
	LPNode temp = ((*root)->Lchild);
	(*root)->Rchild = temp->Rchild;
	temp->Rchild = *root;
	updataheight(root);
	updataheight(&temp);
	*root = temp;
	
}//右旋
void RR(Node **root)
{
	LPNode temp = ((*root)->Rchild);
	(*root)->Rchild = temp->Lchild;
	temp->Lchild = *root;
	updataheight(root);
	updataheight(&temp);
	*root = temp;
}//左旋
void LR(Node **root)
{
	LL(&((*root)->Lchild));
	RR(root);
	
}//传引用不然后面赋值没用
void RL(Node **root)
{
	RR(&((*root)->Rchild));
	LL(root);
}
void insertnode(LPNode* root, int data)
{
	LPNode* newnode = creatnode(data);
	if (root == NULL)
	{
		(root) = newnode;
		return;
	}
	else
	{
		if ((*root)->data > data)
		{
			insertnode((&(*root)->Lchild), data);

		}
		else
		{
			insertnode(&((*root)->Rchild), data);

		}
		updataheight(root);
		if (getblance_factor(root) == 2 && (*root)->data > data)
		{
			LL(root);
		}
		else if (getblance_factor(root) == 2 && (*root)->data < data)
		{
			LR(root);
		}
		else if (getblance_factor(root) == -2 && (*root)->data < data)
		{
			RR(root);
		}
		else if (getblance_factor(root) == -2 && (*root)->data > data)
		{
			RL(root);
		}
	}
}
void minorder(LPNode* root)
{
	if (root != NULL)
	{
		minorder(&(*root)->Lchild);
		printf("值：%d\t高度：%d\n", (*root)->data, (*root)->height);
		minorder(&(*root)->Rchild);
	}
}
//判断自己的树 是不是平衡树
int JudgeTree(LPNode* root)
{
	if (root == NULL)
	{
		return  1;
	}
	if (getblance_factor(root) > 1 || getblance_factor(root) < -1)
	{
		return 0;
	}
	return JudgeTree(&((*root)->Lchild)) && JudgeTree(&(*root)->Rchild);

}

int main()
{
	Node* root = NULL;
	IPHeap heap = creatheap(MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		insertbyheap(heap, i);
		insertnode(&root, popheap(heap));
	}
	//中序遍历树 看结果 
	minorder(&root);
	if (JudgeTree(&root))
	{
		printf("是平衡二叉树");
	}
	else
	{
		printf("不是平衡二叉树");
	}
	return 0;
}