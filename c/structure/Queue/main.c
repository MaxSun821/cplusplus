#include "Queue.h"

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
    QPush(&q, 7);


//    QPop(&q);
//    QPop(&q);

	int size = QSize(&q);
	printf("当前队列长度为：%i\n", size);

	QPop(&q);
	size = QSize(&q);
	printf("当前队列长度为：%i\n", size);

	QDataType ret = QFront(&q);
	printf("队列头元素为：%i\n", ret);
    ret = QBack(&q);
    printf("队列尾元素为：%i\n", ret);

	QDestroy(&q);
}

int main(void)
{

	QueueTest1();
	return 0;
}