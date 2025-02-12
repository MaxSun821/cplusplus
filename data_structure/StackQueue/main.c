#include "Stack.h"
#include "Queue.h"

void StackTest1();
void QueueTest1();
int main()
{
	StackTest1();
	//QueueTest1();
	return 0;
}

void StackTest1()
{
	Stack stack;
	STInit(&stack);
	STPush(&stack, 1);
	STPush(&stack, 2);
	STPush(&stack, 3);
	STPush(&stack, 4);
	STPush(&stack, 5);

	while (!STisEmpty(&stack))
	{
		printf("%d ", STTop(&stack));
		STPop(&stack);
	}
	printf("\n");

	STDestroy(&stack);
}

void QueueTest1()
{
	Queue queue;
	QInit(&queue);

	QPush(&queue, 1);
	QPush(&queue, 2);
	QPush(&queue, 3);
	QPush(&queue, 4);
	QPush(&queue, 5);

	while (!QisEmpty(&queue))
	{
		printf("%d ", QFront(&queue));
		QPop(&queue);
	}
	printf("\n");

}