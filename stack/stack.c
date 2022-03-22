#include"Stack.h"


void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	if (ps->a == NULL)
	{
		printf("malloc fill");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(Stack* ps, STDataType Data)
{
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fill");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = Data;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;
}