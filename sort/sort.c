#include<stdio.h>
#include<stdlib.h>


//归并排序
void mergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) >> 1;
	mergeSort(a, left, mid, tmp);
	mergeSort(a, mid + 1, right, tmp);

	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			tmp[index++] = a[begin2++];
		}
		else
		{
			tmp[index++] = a[begin1++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

//归并排序非递归版
void mergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int gapindex = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] > a[begin2])
				{
					tmp[gapindex++] = a[begin2++];
				}
				else
				{
					tmp[gapindex++] = a[begin1++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[gapindex++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[gapindex++] = a[begin2++];
			}
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	
	free(tmp);
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int min = begin, max = begin;
		for (int i = begin; i < end; ++i)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		++begin;
		--end;
	}
}
//建堆
void AdjustDwon(int* a, int n, int i)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

//计数排序
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)* range);
	memset(count, 0, sizeof(int)* range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}



	free(count);
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int change = 0;
		for (int j = 1; j < n - i; ++j)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				change = 1;
			}
		}
		if (change == 0)
		{
			break;
		}
	}
}

//挖坑法
int partSort1(int* a, int left, int right)
{
	int begin = left, end = right;

	int pivot = left;
	int key = a[pivot];

	while (begin < end)
	{
		//右边找小
		while (begin < end && a[end] >= key)
			--end;

		//放到左边
		a[pivot] = a[end];
		pivot = end;

		//左边找大
		while (begin < end && a[begin] <= key)
			++begin;

		//放到右边
		a[pivot] = a[begin];
		pivot = begin;

	}

	//将key值放进他正确的位置
	a[pivot] = key;
	return pivot;
}

//左右指针法
int partSort2(int* a, int left, int right)
{
	int begin = left, end = right;
	int key = left;

	while (begin < end)
	{
		//找大
		while (begin < end && a[end] >= a[key])
			--end;

		//找小
		while (begin < end && a[begin] <= a[key])
			++begin;

		//交换位置
		Swap(&a[begin], &a[end]);
	}

	//将key值放进正确的位置
	Swap(&a[begin], &a[key]);
	

	return begin;
}

//前后指针法
int partSort3(int* a, int left, int right)
{
	int key = left;
	int prve = left, cur = prve + 1;

	while (cur <= right)
	{
		while (a[cur] < a[key] && ++prve != cur)
		{
			Swap(&a[prve], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prve], &a[key]);
	return prve;
}
//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyindex = partSort3(a, left, right);

	QuickSort(a, left, keyindex - 1);
	QuickSort(a, keyindex + 1, right);

}



void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	mergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 10, 6, 7, 1, 3, 9, 4, 2, 11};
	//MergeSort(a, sizeof(a) / sizeof(int));
	//mergeSortNonR(a, sizeof(a) / sizeof(int));
	//SelectSort(a, sizeof(a) / sizeof(int));
	//HeapSort(a, sizeof(a) / sizeof(int));
	//CountSort(a, sizeof(a) / sizeof(int));
	//BubbleSort(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	TestMergeSort();
	return 0;
}