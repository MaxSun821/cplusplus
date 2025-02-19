#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* a, int size)
{
	int i = 0;
	for (i = 1; i < size; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
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
		int i = 0;
		for (i = 0; i + gap < size; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int size)
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		bool flag = true;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (a[j + 1] < a[j])
			{
				Swap(&a[j + 1], &a[j]);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

void SelectSort(int* a, int size)
{
	int begin = 0, end = size - 1;
	
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		int i = 0;
		for (i = begin; i <= end; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
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
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int size)
{
	int i = 0;
	for (i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, size);
	}
	
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		end--;
	}
	
}

// 解决快排顺序三数取中
int GetMid(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[midi] > a[right])
		{
			return midi;
		}
		else if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}

// Hoare法
int PartSort1(int* a, int left, int right)
{
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;

	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 左边找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int keyi = left;

	while (left < right)
	{
		// 右边找小
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
int PartSort3(int* a, int left, int right)
{
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int prev = keyi, cur = keyi + 1;

	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNoR(int* a, int begin, int end)
{
	Stack st;
	STInit(&st);

	STPush(&st, end);
	STPush(&st, begin);

	while (!STisEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);
		int right = STTop(&st);
		STPop(&st);

		int keyi = PartSort1(a, left, right);
		if (left + 1 < keyi)
		{
			STPush(&st, keyi);
			STPush(&st, left);
		}
		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}
	}

	STDestroy(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
		return;

	int mid = (begin + end) / 2;

	// 左区间
	_MergeSort(a, begin, mid, tmp);
	// 右区间
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 拷贝回原数组
	memcpy(a + begin, tmp, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));

	_MergeSort(a, 0, size - 1, tmp);
	free(tmp);
}

void MergeSortNoR(int* a, int size)
{
	int* tmp = (int*)malloc(size * sizeof(int));

	int gap = 1;
	while (gap < size)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < size; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 修正
			if (end1 >= size)
			{
				// 无第二区间
				end1 = size - 1;
			}
			if (end2 >= size)
			{
				end2 = size - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int size)
{
	// 找最大值最小值
	int max = a[0], min = a[0];

	int i = 0;
	for (i = 1; i < size; i++)
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

	int* tmp = (int*)malloc(sizeof(int) * range);
	memset(tmp, 0, sizeof(int) * range);
	for (i = 0; i < size; i++)
	{
		tmp[a[i] - min]++;
	}
	int k = 0;
	for (i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[k++] = i + min;
		}
	}
	free(tmp);
}