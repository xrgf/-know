#include<iostream>
using namespace std;
typedef struct data
{
	int first;
	char name[20];
}Data,*IPData;
typedef struct tree
{
	Data count;
	tree* Lchild;
	tree* Rchild;

}Tree,*IPTree;
typedef struct bst
{
	IPTree root;
	int size;
}BTS,*IPBST;
IPTree creattree(Data count)
{
	IPTree node = new Tree;
	node->count = count;
	node->Lchild = node->Rchild = nullptr;
	return node;
}
IPBST creatBST()
{
	IPBST Bts = new BTS;
	Bts->root = nullptr;
	Bts->size = 0;
	return  Bts;
	
}
void printfcount(Data count)
{
	cout << count.first << "  " << count.name << endl;
}
void minorder(IPTree tree)
{
	if (tree != nullptr)
	{
		minorder(tree->Lchild);
		printfcount(tree->count);
		minorder(tree->Rchild);
	}
	return;
}
void insertBST(IPBST Bst,Data count)
{
	IPTree node = new Tree;
	node->count = count;
	if (Bst->root == nullptr)
	{
		Bst->root = node;
	}
	else
	{
		IPTree pmove = Bst->root;
		IPTree pmoveparent = nullptr;
		while (pmove != nullptr)
		{
			pmoveparent = pmove;
			if (pmove->count.first > count.first)
			{
				pmove = pmove->Lchild;
			}
			else if()
		}
	}

}
int main()
{

}