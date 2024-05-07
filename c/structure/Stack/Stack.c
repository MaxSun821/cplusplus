#include "Stack.h"

void STInit(Stack* st)
{
	assert(st);

	st->a = NULL;
	st->top = st->capacity = 0;
}

void STPush(Stack* st, STDataType x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		int newCapacity = st->capacity == 0 ? 5 : 2 * st->capacity;
		STDataType* tmp = (STDataType*)realloc(st->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		st->a = tmp;
	}
	st->a[st->top++] = x;
}
void STPop(Stack* st)
{
	assert(!STEmpty(st));

	st->top--;
}
STDataType STTop(Stack* st)
{
	assert(!STEmpty(st));

	return st->a[st->top - 1];
}

bool STEmpty(Stack* st)
{
	return st->top == 0;
}
int STSize(Stack* st)
{
	return st->top;
}

void STDestroy(Stack* st)
{
    free(st->a);
    st->a = NULL;
    st->top = st->capacity = 0;
}