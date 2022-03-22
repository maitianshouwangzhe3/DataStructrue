#include"SeqList.h"

void menu()
{
	printf("***********************************************************\n");
	printf("******* 1.尾插         ************ 2.头插         ********\n");
	printf("******* 3.尾删         ************ 4.头删         ********\n");
	printf("******* 5.打印         ************ 6.指定位置插入 ********\n");
	printf("******* 7.指定位置删除 ************ 8.查找数据     ********\n");
	printf("***********************************************************\n");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
	int option = 0;
	int x = 0;
	int x1 = 0;
	int x2 = 0;
	while (option != -1)
	{
		menu();
		printf("请选择:> ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			printf("请输入你要插入的数据，以-1结束：> ");
			do
			{
				scanf_s("%d", &x);
				if (x != -1)
				{
					SeqListPushBack(&s, x);
				}
			} while (x != -1);
			break;
		case 2:
			printf("请输入你要插入的数据，以-1结束：> ");
			do
			{
				scanf_s("%d", &x);
				if (x != -1)
				{
					SeqListPushFront(&s, x);
				}
			} while (x != -1);
			break;
		case 3:
			SeqListPopBack(&s);
			break;
		case 4:
			SeqListPopFront(&s);
			break;
		case 5:
			SeqListPrint(&s);
			break;
		case 6:
			printf("请输入你要在哪个位置插入数据和你要插入的数据:> ");
			scanf_s("%d %d", &x,&x1);
			SeqListInsert(&s,x,x1);
			break;
		case 7:
			printf("请输入你要删除哪个位置的数据:> ");
			scanf_s("%d", &x);
			SeqListErase(&s, x);
			break;
		case 8:
			printf("请输入你要查找的数据:> ");
			scanf_s("%d", &x);
			x2=SeqListFind(&s, x);
			if (x2 != 0)
			{
				printf("找到了，下标为%d\n", x2);
			}
			else
			{
				printf("没找到\n");
			}
			break;
		default :
			break;
		}
	}
	SeqListDestory(&s);
	return 0;
}



