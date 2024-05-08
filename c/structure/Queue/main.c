#include "Stack.h"
#include "Queue.h"

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

void QueueTest1()
{
	Queue q;
	QInit(&q);

	QPush(&q, 1);
	QPush(&q, 2);
	QPush(&q, 3);
	QPush(&q, 4);
	QPush(&q, 5);
	QPush(&q, 6);

	int size = QSize(&q);
	printf("当前队列长度为：%i\n", size);

	QPop(&q);
	size = QSize(&q);
	printf("当前队列长度为：%i\n", size);

	QDataType ret = QTop(&q);
	printf("队列头元素为：%i\n", ret);

	QDestroy(&q);
}

int main(void)
{
    //StackTest1();

	QueueTest1();
	return 0;
}