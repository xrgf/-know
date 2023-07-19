#include<iostream>
using namespace std;
typedef struct tree
{
	char data;
	struct tree* lchild;
	struct tree* rchild;
}Tree ,*IPTree;
IPTree CreatTree(char data)
{
	IPTree newtree = new Tree;
	newtree->data = data;
	newtree->lchild = newtree->rchild = nullptr;
	return newtree;
}
void insertbytree(IPTree parent, IPTree lchild, IPTree rchild)
{
	parent->lchild = lchild;
	parent->rchild = rchild;
}
void minorder(IPTree root)
{
	if (root != nullptr)
	{
		minorder(root->lchild);
		cout << root->data << "  ";
		minorder(root->rchild);
	}
	else
	{
		return;
	}
}
void proorder(IPTree root)
{
	if (root != nullptr)
	{
		cout << root->data << "  ";
		proorder(root->lchild);
		proorder(root->rchild);
		
	}
	else
	{
		return;
	}
}
void lastorder(IPTree root)
{
	if (root != nullptr)
	{
		lastorder(root->lchild);
		lastorder(root->rchild);
		cout << root->data << "  ";
		
	}
	else
	{
		return;
		
	}
}
void recursive_proorder(IPTree root)
{
	IPTree pmove = root;
	IPTree stack[10];
	int top = -1;
	if (pmove == nullptr)
	{
		return;
	}
	while (top != -1 || pmove)
	{
		while (pmove != nullptr)
		{
			cout << pmove->data << "  ";
			stack[++top] = pmove;
			pmove = pmove->lchild;
			
		}
		if (top!=-1)
		{
			pmove = stack[top--];
			pmove = pmove->rchild;
		}
	}
	

}
void recursive_midorder(IPTree root)
{
	IPTree pmove = root;
	IPTree stack[10];
	int top = -1;
	if (pmove == nullptr)
	{
		return;
	}
	while (top != -1 || pmove)
	{
		while (pmove != nullptr)
		{
			stack[++top] = pmove;
			pmove = pmove->lchild;
		}
	
		if (top != -1)
		{		
			pmove = stack[top--];
			cout << pmove->data << "  ";
			pmove = pmove->rchild;
		}
	}
}
void recursive_lastorder(IPTree root)
{
	IPTree pmove = root;
	IPTree stack[10];
	int top = -1;
	IPTree plastvisit = nullptr;
	if (pmove == nullptr)
	{
		return;
	}
	else
	{
		while (pmove)
		{
			stack[++top] = pmove;
			pmove = pmove->lchild;
		}
		while (top != -1)
		{
			pmove = stack[top--];
			if (pmove->rchild == nullptr || pmove->rchild==plastvisit)
			{
				cout << pmove->data << "  ";
				plastvisit = pmove;
			}
			else
			{
				stack[++top] = pmove;
				pmove = pmove->rchild;
				while (pmove)
				{
					stack[++top] = pmove;
					pmove = pmove->lchild;
				}
				
			}
		}

	}

}
int main()
{

	IPTree A = CreatTree('A');
	IPTree B = CreatTree('B');
	IPTree C = CreatTree('C');
	IPTree D = CreatTree('D');
	IPTree E = CreatTree('E');
	IPTree F = CreatTree('F');
	IPTree G = CreatTree('G');
	IPTree H = CreatTree('H');
	insertbytree(A, B, C);
	insertbytree(B, D, E);
	insertbytree(C, F, G);
	insertbytree(D, H, nullptr);
	cout << "先序遍历" << endl;
	proorder(A);
	cout << endl;
	recursive_proorder(A);
	cout << endl;
	cout << "中序遍历" << endl;
	minorder(A);
	cout << endl;
	recursive_midorder(A);
	cout << endl;
	cout << "后序遍历" << endl;
	lastorder(A);
	cout << endl;
	recursive_lastorder(A);
	cout << endl;



	return 0;
}