#include "Heap.h"

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2; // 父亲节点下标
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			// 交换数据
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
void AdjustDown(HPDataType* a, int parent, int size)
{
	int child = parent * 2 + 1;
	
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child += 1;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}

}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		// 扩容
		int newCapacity = hp->capacity == 0 ? 5 : 2 * hp->capacity;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	// 为了保证其为小根堆，进行向上调整
	// hp->size - 1为孩子节点
	AdjustUp(hp->a, hp->size - 1);
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	// 删除头结点，交换头尾数据
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	// 向下调整成小根堆
	AdjustDown(hp->a, 0, hp->size);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}

bool HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	return hp->size;
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}