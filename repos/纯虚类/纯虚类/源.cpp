#include<iostream>
#include<assert.h>
using namespace std;
class A
{
public:
	virtual void printff()
	{
		cout << "A::printf" << endl;
	}
protected:
	int a;
};
class B :public A
{
public:
	void printff()
	{
		cout << "B::printff" << endl;
	}
protected:
};
int max(int i, int j)
{
	return i > j ? i : j;
}
struct STACK
{
	char num[10];
	int top;
};
struct STACK* creatstack()
{
	struct STACK* stack = new struct STACK;
	assert(stack);
	stack->top = -1;
	return stack;
}
void push(struct STACK* stack,char ch)
{
	stack->num[++stack->top] = ch;

}
void pop(struct STACK* stack)
{
	stack->top--;
}
bool  empty(struct STACK* stack)
{

	return stack->top != -1;
}
bool Match(struct STACK* stack, char* match)
{
	int len = strlen(match);
	for (int i = 0; i < len; ++i)
	{
		if (match[i] == '{' || match[i] == '[' || match[i] == '(')
		{
			push(stack, match[i]);
		}

		if (match[i] == '}' && empty(stack))
		{
			if (stack->num[stack->top] == '{')
			{
				pop(stack);
				
			}
			else
			{
				return false;
			}
		}
		if (match[i] == ')' && empty(stack))
		{
			if (stack->num[stack->top] == '(')
			{
				pop(stack);
				
			}
			else
			{
				return false;
			}

		}

		if (match[i] == ']' && empty(stack))
		{
			if (stack->num[stack->top] == '[')
			{
				pop(stack);
				
			}
			else
			{
				return false;
			}
		}
	}
	
	if (stack->top!=-1)
		return false;
}
int main()
{
		struct STACK* stack = creatstack();
		char str[10] = "()[[]]}";
		int i= Match(stack, str);
		cout << i << endl;
}
	
	

	/*}*/
	//括号匹配
	/*typedef int ARRAY[3][2];
	ARRAY array;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
			array[i][j] = i;
	}
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << array[i][j]<<"\t";
		}
		cout << endl;
	}
	*/

	//typedef int (*p)(int, int);
	//p p1 = max;
	//cout << max(1, 2) << endl;
	//cout << p1(1, 2);
	/*typedef int Array[3];
	Array num[2];
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			num[i][j] = i;
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << num[i][j] << "\t";
		}
		cout << endl;
	}*/

	
	//typedef int(*p)[5];
	//int a[6][5];
	//p p1 = a;
	//for (int i = 0; i < 6; ++i)
	//{
	//	for(int j=0;j<5;++j)
	//	 p1[i][j]=i;
	//}
	//for (int i = 0; i < 6; ++i)
	//{
	//	for (int j = 0; j < 5; ++j)
	//		cout << p1[i][j] << "\t";
	//	cout << endl;
	//}
	//A* a = new A;
	//a->printff();
	//A* a1 = new B;
	//a1->printff();
	////父类可以用子类new 子类不可以用父类new
	//B* b = dynamic_cast<B*>(new A);
	//if(b!=nullptr)
	//b->printff();

