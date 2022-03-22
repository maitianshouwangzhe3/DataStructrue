#pragma once

#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

// 前置声明
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

// 队尾入
void QueuePush(Queue* pq, QDataType x);
// 队头出
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);



typedef char STDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

	STDataType data;
}STNode;


//前序 中序 后序遍历
void PrevOrder(STNode* root);

void InOrder(STNode* root);

void PostOrder(STNode* root);

//节点个数
int TreeSize(STNode* root);

//叶子节点个数
int TreeleaSize(STNode* root);

//层序遍历
void LevelOrder(STNode* root);



