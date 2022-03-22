#include"queue.h"

void QueueInit(Queue* ps)
{
	assert(ps);
	ps->front = ps->rear = NULL;
}

void QueueDestory(Queue* ps)
{
	assert(ps);
	QNode* cur = ps->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->front = ps->rear = NULL;
}

void QueuePush(Queue* ps, QDataType x)
{
	QNode* new = (QNode*)malloc(sizeof(QNode));
	if (new == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	new->Data = x;
	new->next = NULL;

	if (ps->rear == NULL)
	{
		ps->front = ps->rear = new;
	}
	else
	{
		ps->rear->next = new;
		ps->rear = new;
	}
}

void QueuePop(Queue* ps)
{
	assert(ps);
	assert(ps->front);
	if (ps->front->next == NULL)
	{
		free(ps->front);
		ps->front = ps->rear = NULL;
	}
	else
	{
		QNode* tmp = ps->front;
		ps->front = ps->front->next;
		free(tmp);
		tmp = NULL;
	}
}

QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(ps->front);
	return ps->front->Data;
}

QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(ps->front);
	return ps->rear->Data;
}

int QueueSize(Queue* ps)
{
	if (ps->rear == NULL)
	{
		return 0;
	}
	int count = 0;
	QNode* cur = ps->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* ps)
{
	return ps->front == NULL;
}