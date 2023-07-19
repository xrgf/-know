#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int array[10];
	int  top;
	int cursize;
}Stack,*LPStack;
LPStack creatstack();
int stackTop(LPStack stack);
void pushstack(LPStack stack,int data);
void popstack(LPStack stack);
bool empty(LPStack stack);
