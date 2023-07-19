#include"stack.h"
LPStack creatstack()
{
	LPStack stack = (LPStack)malloc(sizeof(Stack));
	stack->top = -1;
	
	return stack;
}
int stackTop(LPStack stack)
{
	return stack->array[stack->top];
}
void pushstack(LPStack stack,int data)
{
	stack->array[++stack->top] = data;
}
void popstack(LPStack stack)
{
	printf("%d", stack->array[stack->top--]);
}
bool empty(LPStack stack)
{
	return stack->top == -1;
}
