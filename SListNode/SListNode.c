#include "SListNode.h"

//申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}
//打印单链表
void SListPrint(SListNode* Plist)
{
	SListNode* cur = Plist;
	while (cur)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
//单链表尾插
void SListPushBack(SListNode** Pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*Pplist == NULL)
	{
		*Pplist = newnode;
	}
	else
	{
		SListNode* cur = *Pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
//单链表的头插
void SListPushFront(SListNode** Pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *Pplist;
	*Pplist = newnode;
}
//单链表的尾删
void SListPopBack(SListNode** Pplist)
{
	if (*Pplist == NULL)
	{
		return;
	}
	else if ((*Pplist)->next == NULL)
	{
		free(*Pplist);
		*Pplist = NULL;
	}
	else
	{
		SListNode* cur = *Pplist;
		SListNode* pvr = NULL;
		while (cur->next)
		{
			pvr = cur;
			cur = cur->next;
		}
		pvr->next = NULL;
		free(cur);
		cur = NULL;
	}
}
//单链表的头删
void SListPopFront(SListNode** Pplist)
{
		SListNode* cur = *Pplist;
		*Pplist = cur->next;
		free(cur);
		cur = NULL;
}
//单链表查找
SListNode* SListFind(SListNode* Plist, SLTDateType x)
{
	SListNode* cur = Plist;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//在单链表pos位置插入x
void SListInsert(SListNode** Pplist, SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		return;
	}
	else
	{
		if (pos == *Pplist)
		{
			SListPushFront(Pplist, x);
		}
		else
		{
			SListNode* cur = *Pplist;
			while (cur->next != pos)
			{
				cur = cur->next;
			}
			SListNode* newnode = BuySListNode(x);
			cur->next = newnode;
			newnode->next = pos;
		}
	}
}
//删除单链表pos位置数据
void SListErase(SListNode** Pplist, SListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = *Pplist;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
