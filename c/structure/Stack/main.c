#include "Stack.h"

void StackTest1()
{
	Stack* st = (Stack*)malloc(sizeof(Stack));
	STInit(st);

	STPush(st, 1);
	STPush(st, 2);
	STPush(st, 3);
	STPush(st, 4);
	STPush(st, 5);
	STPush(st, 6);
	STPush(st, 7);

	STDataType ret = STTop(st);
	printf("Õ»¶¥ÔªËØÎª£º%i\n", ret);


}

int main(void)
{
	StackTest1();
	return 0;
}