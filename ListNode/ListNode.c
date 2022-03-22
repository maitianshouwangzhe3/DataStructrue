#include "ListNode.h"

//创建一个节点
ListNode* BuyListNode(LTDateType x)
{
	ListNode* newnode =(ListNode*) malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

// 创建返回链表的头结点
ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

}
// 双向链表销毁
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(phead);
	phead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* phead)
{
	ListNode* head = phead->next;
	while (head != phead)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* phead, LTDateType x)
{
	assert(phead);
	/*ListNode* newnode = BuyListNode(x);
	ListNode* cur = phead->prev;
	cur->next = newnode;
	newnode->next = phead;
	newnode->prev = cur;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}
// 双向链表尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	/*ListNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;*/
	ListErase(phead->prev);
}
// 双向链表头插
void ListPushFront(ListNode* phead, LTDateType x)
{
	assert(phead);
	/*ListNode* tail = phead->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = tail;
	newnode->prev = phead;
	tail->prev = newnode;
	phead->next = newnode;*/
	ListInsert(phead->next, x);
}
// 双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	/*ListNode* tail = phead->next;
	tail->next->prev = phead;
	phead->next = tail->next;
	free(tail);
	tail = NULL;*/
	ListErase(phead->next);
}
// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* tail = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	newnode->prev = tail;
	pos->prev = newnode;
	tail->next = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* tail = pos;
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	free(tail);
	tail = NULL;
}