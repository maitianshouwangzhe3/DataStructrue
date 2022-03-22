#include"SeqList.h"

//判断容量是否满了，如果满了则增容
void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->Capacity)
	{
		//满了要扩容
		int newCapacity = ps->Capacity == 0 ? 4 : ps->Capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps->a, newCapacity*sizeof(SeqList));
		if (tmp == NULL)
		{
			printf("增容失败");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->Capacity = newCapacity;
		}
	}
}
//顺序表初始化
void SeqListInit(SeqList* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->Capacity = 0;
}
//注销动态内存开辟的空间
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->Capacity = 0;
}
//打印顺序表
void SeqListPrint(SeqList* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//尾插数据
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	/*SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
//头插数据
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	/*int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;*/
	SeqListInsert(ps, 0, x);
}
//尾删数据
void SeqListPopBack(SeqList* ps)
{
	/*assert(ps);
	ps->a[ps->size - 1] = 0;
	ps->size--;
	printf("删除成功\n");*/
	SeqListErase(ps, ps->size - 1);
}
//头删数据
void SeqListPopFront(SeqList* ps)
{
	/*assert(ps);
	int end = 0;
	while (end < ps->size)
	{
		ps->a[end] = ps->a[end + 1];
		++end;
	}
	ps->size--;
	printf("删除成功\n");*/
	SeqListErase(ps, 0);
}
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return NULL;
}
//顺序表在pos位置插入数据x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps->size >= pos);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end]; 
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除在顺序表pos位置的数据
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps->size > pos);
	int end = pos;
	while (end < ps->size)
	{
		ps->a[end] = ps->a[end + 1];
		++end;
	}
	ps->size--;
	printf("删除成功\n");
}