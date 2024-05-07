#include "Stack.h"

void StackTest1()
{
	Stack st;
	STInit(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	STPush(&st, 6);
	STPush(&st, 7);

	STDataType ret = STTop(&st);
	printf("栈顶元素为：%i\n", ret);

    STPop(&st);
    ret = STTop(&st);
    printf("栈顶元素为：%i\n", ret);

    STDestroy(&st);

}

int main(void)
{
	StackTest1();
	return 0;
}