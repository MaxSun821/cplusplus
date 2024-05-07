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
void STPop(Stack* st);
STDataType STTop(Stack* st);

bool STEmpty(Stack* st);
int STSize(Stack* st);