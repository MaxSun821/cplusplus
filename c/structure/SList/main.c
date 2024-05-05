#include "SList.h"


void SListTest1()
{
    ListNode* head = NULL;
    SLPushFront(&head, 1);
    SLPushFront(&head, 2);
    SLPushFront(&head, 3);
    SLPushFront(&head, 4);

    SLPrint(head);

}

void SListTest2()
{
    ListNode* head = NULL;
    SLPushBack(&head, 1);
    SLPushBack(&head, 2);
    SLPushBack(&head, 3);
    SLPushBack(&head, 4);

    SLPrint(head);

    SLDestroy(&head);
}

void SListTest3()
{
    ListNode* head = NULL;
    SLPushBack(&head, 1);
    SLPushBack(&head, 2);
    SLPushBack(&head, 3);
    SLPushBack(&head, 4);
    SLPushBack(&head, 5);
    SLPushBack(&head, 6);
    SLPushBack(&head, 7);

    SLPrint(head);

    SLPopFront(&head);
    SLPopFront(&head);
    SLPrint(head);
}

void SListTest4()
{
    ListNode* head = NULL;
    SLPushBack(&head, 1);
    SLPushBack(&head, 2);
    SLPushBack(&head, 3);
    SLPushBack(&head, 4);
    SLPushBack(&head, 5);
    SLPushBack(&head, 6);
    SLPushBack(&head, 7);

    SLPrint(head);

    SLPopBack(&head);
    SLPopBack(&head);
    SLPrint(head);
}

void SListTest5()
{
    ListNode* head = NULL;
    SLPushBack(&head, 1);
    SLPushBack(&head, 2);
    SLPushBack(&head, 3);
    SLPushBack(&head, 4);
    SLPushBack(&head, 5);
    SLPushBack(&head, 6);
    SLPushBack(&head, 7);

    SLPrint(head);

    ListNode* pos = SLFind(head, 3);
    SLInsertAfter(&head, pos, 8);
    SLPrint(head);
}

void SListTest6()
{
    ListNode* head = NULL;
    SLPushBack(&head, 1);
    SLPushBack(&head, 2);
    SLPushBack(&head, 3);
    SLPushBack(&head, 4);
    SLPushBack(&head, 5);
    SLPushBack(&head, 6);
    SLPushBack(&head, 7);

    SLPrint(head);

    ListNode* pos = SLFind(head, 3);
    SLEraseAfter(&head, pos);
    SLPrint(head);
}

int main(void)
{
    SListTest6();

    return 0;
}
