#include "ListNode.h"




void test()
{
	ListNode* S = ListCreate();
	ListPushBack(S, 1);
	ListPushBack(S, 2);
	ListPushBack(S, 3); 
	ListPushBack(S, 4);
	ListPrint(S);
	ListPopBack(S);
	ListPrint(S);
	ListPushFront(S, 5);
	ListPrint(S);
	ListPopFront(S);
	ListPrint(S);
	ListNode* tmp = ListFind(S, 3);
	if (tmp != NULL)
	{
		tmp->data *= 10;
		printf("找到了并且乘以10\n");
	}
	else
	{
		printf("没找到\n");
	}
	ListInsert(tmp, 6);
	ListPrint(S);
	ListErase(tmp);
	ListPrint(S);
	ListDestory(S);

}

int main()
{
	test();
	return 0;
}