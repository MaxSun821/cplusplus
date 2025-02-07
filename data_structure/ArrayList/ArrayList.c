#include "ArrayList.h"

void Init(ArrayList* pal)
{
	assert(pal);
	pal->a = (DataType*)malloc(4 * sizeof(DataType));
	if (pal->a == NULL)
	{
		perror("Init::malloc");
	}
	pal->size = 0;
	pal->capacity = 4;
}

void Destroy(ArrayList* pal)
{
	free(pal->a);
	pal->a = NULL;
	pal->size = 0;
	pal->capacity = 0;
}

void CheckCapacity(ArrayList* pal)
{
	if (pal->size == pal->capacity)
	{
		int new_capacity = 2 * pal->capacity;
		DataType* new_ptr = (DataType*)realloc(pal->a, sizeof(DataType) * new_capacity);
		if (new_ptr == NULL)
		{
			perror("Reserve::realloc");
			return;
		}
		pal->a = new_ptr;
		pal->capacity = new_capacity;
	}
	
}

void PushBack(ArrayList* pal, DataType x)
{
	/*CheckCapacity(pal);
	pal->a[pal->size++] = x;*/

	Insert(pal, pal->size, x);
}
void PopBack(ArrayList* pal)
{
	/*assert(pal->size > 0);
	pal->size--;*/

	Erase(pal, pal->size - 1);
}

void PushFront(ArrayList* pal, DataType x)
{
	/*CheckCapacity(pal);
	int i = 0;
	for (i = pal->size; i > 0; i--)
	{
		pal->a[i] = pal->a[i - 1];
	}
	pal->a[0] = x;
	pal->size++;*/

	Insert(pal, 0, x);
}
void PopFront(ArrayList* pal)
{
	/*assert(pal->size > 0);
	int i = 0;
	for (i = 0; i < pal->size - 1; i++)
	{
		pal->a[i] = pal->a[i + 1];
	}
	pal->size--;*/

	// ´úÂë¸´ÓÃ
	Erase(pal, 0);
}

void Insert(ArrayList* pal, int pos, DataType x)
{
	assert(pal);
	assert(pos >= 0 && pos <= pal->size);
	CheckCapacity(pal);
	int i = 0;
	for (i = pal->size; i > pos; i--)
	{
		pal->a[i] = pal->a[i - 1];
	}
	pal->a[pos] = x;
	pal->size++;
}

void Erase(ArrayList* pal, int pos)
{
	assert(pal);
	assert(pos >= 0 && pos < pal->size);

	int i = 0;
	for (i = pos; i < pal->size - 1; i++)
	{
		pal->a[i] = pal->a[i + 1];
	}
	pal->size--;
}

int Find(ArrayList* pal, DataType x)
{
	assert(pal);
	int i = 0;
	for (i = 0; i < pal->size; i++)
	{
		if (pal->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void Modify(ArrayList* pal, int pos, DataType x)
{
	assert(pal);
	assert(pos >= 0 && pos < pal->size);
	pal->a[pos] = x;
}

void Print(ArrayList* pal)
{
	assert(pal);
	int i = 0;
	for (i = 0; i < pal->size; i++)
	{
		printf("%d ", pal->a[i]);
	}
	printf("\n");
}