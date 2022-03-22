#include "TreeNode.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

// 队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

// 队头出
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	// 1、一个
	// 2、多个
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}


QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}



void PrevOrder(STNode* root)
{
	if (root->data == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(STNode* root)
{
	if (root->data == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(STNode* root)
{
	if (root->data == NULL)
	{
		printf("NULL");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

int TreeSize(STNode* root)
{
	return NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeleaSize(STNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return TreeleaSize(root->left) + TreeleaSize(root->right);
}
void LevelOrder(STNode* root)
{
	// 核心思路：上一层出的时候带下一层节点进
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		STNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestory(&q);
}