#include "SListNode.h"




void test()
{
	SListNode* Plist = NULL;
	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPrint(Plist);
	SListPushFront(&Plist, 5);
	SListPrint(Plist);
	SListPopBack(&Plist);
	SListPrint(Plist);
	SListPopFront(&Plist);
	SListPrint(Plist);
	SListInsert(&Plist, SListFind(Plist,1), 6);
	SListPrint(Plist);
	SListErase(&Plist, SListFind(Plist, 1));
	SListPrint(Plist);
}



int main()
{
	test();
	return 0;
}