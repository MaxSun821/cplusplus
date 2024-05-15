#pragma once

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
}Stack;

void STInit(Stack* st);

void STPush(Stack* st, STDataType x);
void STPop(Stack* st);
STDataType STTop(Stack* st);

bool STEmpty(Stack* st);
int STSize(Stack* st);

void STDestroy(Stack* st);
