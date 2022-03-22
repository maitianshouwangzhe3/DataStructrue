#include"Stack.h"
typedef struct {
	Stack q1;
	Stack q2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
	if (ps == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	StackInit(&ps->q1);
	StackInit(&ps->q2);
	return ps;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->q2, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	Stack* t1 = &obj->q1;
	Stack* t2 = &obj->q2;
	if (StackEmpty(&obj->q1))
	{
		while (StackEmpty(t2))
		{
			StackPush(t1, StackTop(t2));
			StackPop(t2);
		}
	}
	int top = StackTop(t1);
	StackPop(t1);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->q1) && !StackEmpty(&obj->q2))
	{
		return StackTop(&obj->q1);
	}
	else
	{
		while (StackSize(&obj->q2) > 1)
		{
			StackPush(&obj->q1, StackTop(&obj->q2));
			StackPop(&obj->q2);
		}
	}
	return StackTop(&obj->q1);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->q1) && StackEmpty(&obj->q2);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->q1);
	StackDestory(&obj->q2);

	free(obj);
}



int main()
{
	int a = 0;
	MyQueue obj = myQueueCreate();
	myQueuePush(&obj,0);
	myQueuePush(&obj, 1);
	myQueuePush(&obj, 2);
	myQueuePush(&obj, 0);
	myQueuePush(&obj, 0);
	myQueuePush(&obj, 0);
	a=myQueuePop(&obj);
	printf("%d ", a);
	a=myQueuePop(&obj);
	printf("%d ", a);
	a=myQueuePop(&obj);
	printf("%d ", a);
	a=myQueuePop(&obj);
	printf("%d ", a);
	myQueueEmpty(&obj);
}