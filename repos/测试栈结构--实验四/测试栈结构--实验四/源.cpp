#include"stack.h"
int main()
{
	int num;
	LPStack stack = creatstack();
	scanf("%d", &num);
	while (num)
	{
		pushstack(stack, num%2);
		num /= 2;
	}
	while (!empty(stack))
	{
		popstack(stack);
	}
	


}