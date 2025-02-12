#include "Stack.h"

void STInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		// À©ÈÝ
		int new_capacity = pst->capacity == 0 ? 5 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)realloc(pst->a, new_capacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("Push::realloc");
			return;
		}
		pst->a = tmp;
		pst->capacity = new_capacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(Stack* pst)
{
	assert(pst);
	assert(!STisEmpty(pst));

	pst->top--;
}

STDataType STTop(Stack* pst)
{
	assert(pst);
	assert(!STisEmpty(pst));

	return pst->a[pst->top - 1];
}

bool STisEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int STSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}

void STDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}