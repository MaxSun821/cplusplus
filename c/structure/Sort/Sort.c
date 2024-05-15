#include "Sort.h"


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int size)
{
	for (int i = 1; i < size; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			--end;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
		{
			int end = i - gap;
			int tmp = a[i];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
				}
				else
				{
					break;
				}
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}

	InsertSort(a, size);
	
}

void SelectSort(int* a, int size)
{
	int begin = 0;
	int end = size - 1;

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;

		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		// 交换
		swap(&a[begin], &a[mini]);
		// 防止begin和maxi重合
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

void BubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = true;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(&a[j + 1], &a[j]);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

void AdjustDown(int* a, int parent, int size)
{
	int child = 2 * parent + 1;
	
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			// 交换
			swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		parent = child;
		child = 2 * parent + 1;
	}
}

void HeapSort(int* a, int size)
{
	// 1.建大堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, i, size);
	}
	// 交换首尾元素，再建大堆
	int end = size - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		--end;
	}
}
// hoare法
int _quickSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[left]);
	return left;
}
// 挖坑法
int _quickSort2(int* a, int left, int right)
{
    int key = a[left];
    int keyi = left;
    while(left < right)
    {
        while (left < right && a[right] >= key)
        {
            --right;
        }
        a[keyi] = a[right];
        keyi = right;
        while (left < right && a[left] <= key)
        {
            ++left;
        }
        a[keyi] = a[left];
        keyi = left;
    }
    a[keyi] = key;
    return keyi;
}

// 前后指针法
int _quickSort3(int* a, int left, int right)
{
    int prev = left, cur = left + 1;
    int keyi = left;
    while(cur <= right)
    {
        if(a[cur] < a[keyi] && ++prev != cur)
        {
            swap(&a[prev], &a[cur]);
        }
        ++cur;
    }
    swap(&a[keyi], &a[prev]);
    keyi = prev;
    return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
//	int keyi = _quickSort1(a, begin, end);
//    int keyi = _quickSort2(a, begin, end);
    int keyi = _quickSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void PrintArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i ", a[i]);
	}
	printf("\n");
}