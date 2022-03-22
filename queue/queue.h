#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType Data;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* ps);
// 队尾入队列 
void QueuePush(Queue* ps, QDataType data);
// 队头出队列 
void QueuePop(Queue* ps);
// 获取队列头部元素 
QDataType QueueFront(Queue* ps);
// 获取队列队尾元素
QDataType QueueBack(Queue* ps);
// 获取队列中有效元素个数 
int QueueSize(Queue* ps);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* ps);
// 销毁队列
void QueueDestroy(Queue* ps);