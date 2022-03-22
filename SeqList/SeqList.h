#pragma once
#include <stdio.h>
#include <assert.h>
//单链表
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int Capacity;
}SeqList;


//对数据的管理：增删查改
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);
//头插 尾插 头删 尾删
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
//顺序表在pos位置插入数据
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
//删除在顺序表pos位置的数据
void SeqListErase(SeqList* ps, int pos);