#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct node
{
	int data;
	int height;
	struct node* Rchild;
	struct node* Lchild;
}NODE,*LPNODE;
LPNODE creatnode(int data)
{
	LPNODE newnode = (LPNODE)malloc(sizeof(NODE));
	assert(newnode);
	newnode->data = data;
	newnode->height = 1;
	newnode->Lchild = newnode->Rchild = NULL;
	return newnode;
}

int getheight(LPNODE root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}
int updataheight(LPNODE root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	int r, l, max;
	r = getheight(root->Rchild);
	l = getheight(root->Lchild);
	max = r > l ? r : l;
	return max+1;
}
void RR(LPNODE &root)//ÓÒÐý
{
	LPNODE temp = AVT->root->Lchild;
	AVT->root->Lchild = temp->Rchild;
	temp->Rchild = AVT->root;
	updataheight(AVT->root);
	updataheight(temp);
}
void LL(LPNODE &root)//×óÐý
{
	LPNODE temp = root->Rchild;
	root->Rchild = temp->Lchild;
	temp->Lchild =root;
	updataheight(root);
	updataheight(temp);
}
void RL(LPNODE &root)
{
	LL(root->Lchild);
	RR(root);
}
void LR(LPNODE &root)
{
	RR(root->Rchild);
	LL(root);
}
void insertnode(LPNODE root,int data)
{
	LPNODE newnode = creatnode(data);
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		LPNODE pmove = root;
		LPNODE pmoveparent = NULL;
		while (pmove)
		{
			pmoveparent = pmove;
			if (data > pmove->data)
			{
				pmove = pmove->Rchild;
			}
			else
			{
				pmove = pmove->Lchild;
			}
		}
		if (data < pmoveparent->data)
		{
			pmoveparent->Lchild = newnode;
		}
		else
		{
			pmoveparent->Rchild = newnode;
		}
		updataheight(root);
		if (getheight(root->Lchild) - getheight(root->Rchild) > 1 )
		{
			if (pmoveparent->data > data)
			{
				RR(root);
			}
			else
			{
				RL(root);
			}
		}
		if (getheight(root->Rchild) - getheight(root->Lchild) > 1)
		{
			if (pmoveparent->data > data)
			{
				LR(root);
			}
			else
			{
				RR(root);
			}
		}
	}
}
void minorder(LPNODE root)
{
	if (root)
	{
		minorder(root->Lchild);
		printf("%d\t%d\n", root->data,root->height);
		
		minorder(root->Rchild);
	}
	return;
}
int main()
{
	struct tree* newtree = creattree();
	for (int i = 0; i < 10; i++)
	{
		insertnode(newtree->root, i);
	}
	minorder(newtree->root);
	while (1);



	return 0;
}