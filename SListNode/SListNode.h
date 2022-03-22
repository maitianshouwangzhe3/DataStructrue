#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
}SListNode;

//动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
//单链表打印
void SListPrint(SListNode* Plist);
//单链表尾插
void SListPushBack(SListNode** Pplist, SLTDateType x);
//单链表的头插
void SListPushFront(SListNode** Pplist, SLTDateType x);
//单链表的尾删
void SListPopBack(SListNode** Pplist);
//单链表的头删
void SListPopFront(SListNode** Pplist);
//单链表查找
SListNode* SListFind(SListNode* Plist, SLTDateType x);
//在单链表pos位置插入x
void SListInsert(SListNode** Pplist, SListNode* pos, SLTDateType x);
//删除单链表pos位置数据
void SlistErase(SListNode** Pplist, SListNode* pos);