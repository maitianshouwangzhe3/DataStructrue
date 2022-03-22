#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// 带头+双向+循环链表增删查改实现
//带哨兵卫双向循环链表
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


// 创建返回链表的头结点
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* phead);
// 双向链表打印
void ListPrint(ListNode* phead);
// 双向链表尾插
void ListPushBack(ListNode* phead, LTDateType x);
// 双向链表尾删
void ListPopBack(ListNode* phead);
// 双向链表头插
void ListPushFront(ListNode* phead, LTDateType x);
// 双向链表头删
void ListPopFront(ListNode* phead);
// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDateType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDateType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);