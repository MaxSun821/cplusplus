#ifndef C_CODE_STACK_H
#define C_CODE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
} Stack;

void STInit(Stack* pst);
void STPush(Stack* pst, STDataType x);
void STPop(Stack* pst);
STDataType STTop(Stack* pst);
bool STisEmpty(Stack* pst);
int STSize(Stack* pst);
void STDestroy(Stack* pst);

#endif
