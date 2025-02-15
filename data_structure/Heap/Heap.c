#include "Heap.h"

void HeapInit(Heap* ph)
{
	assert(ph);
	ph->a = NULL;
	ph->size = ph->capacity = 0;
}
void Destroy(Heap* ph)
{
	assert(ph);
	free(ph->a);
	ph->a = 0;
	ph->size = ph->capacity = 0;
}
void Swap(HDataType* pa, HDataType* pb)
{
	HDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void AdjustUp(HDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}
void HeapPush(Heap* ph, HDataType x)
{
	if (ph->size == ph->capacity)
	{
		int new_capacity = ph->capacity == 0 ? 5 : 2 * ph->capacity;
		HDataType* tmp = (HDataType*)realloc(ph->a, sizeof(HDataType) * new_capacity);
		if (tmp == NULL)
		{
			perror("HeapPush::realloc");
			return;
		}
		ph->capacity = new_capacity;
		ph->a = tmp;
	}
	ph->a[ph->size++] = x;
	// 进行调整，形成小堆
	AdjustUp(ph->a, ph->size - 1);
}
void AdjustDown(HDataType* a, int parent, int size)
{
	int child = 2 * parent + 1;
	
	while (child < size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
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
void HeapPop(Heap* ph)
{
	assert(ph);
	assert(!HeapisEmpty(ph));
	// 交换收尾元素
	Swap(&(ph->a[0]), &(ph->a[ph->size - 1]));
	ph->size--;
	// 进行调整
	AdjustDown(ph->a, 0, ph->size);
}
HDataType HeapTop(Heap* ph)
{
	assert(ph);
	assert(!HeapisEmpty(ph));

	return ph->a[0];
}
int HeapSize(Heap* ph)
{
	assert(ph);
	return ph->size;
}
bool HeapisEmpty(Heap* ph)
{
	assert(ph);
	return ph->size == 0;
}