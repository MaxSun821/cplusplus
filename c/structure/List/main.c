#include "List.h"

void ListTest1()
{
    ListNode* pHead = init();
    ListPushBack(pHead, 1);
    ListPushBack(pHead, 2);
    ListPushBack(pHead, 3);
    ListPushBack(pHead, 4);
    ListPushBack(pHead, 5);
    ListPushBack(pHead, 6);
    ListPushBack(pHead, 7);

    ListPrint(pHead);

    ListDestroy(pHead);

}

void ListTest2()
{
    ListNode* pHead = init();
    ListPushFront(pHead, 1);
    ListPushFront(pHead, 2);
    ListPushFront(pHead, 3);
    ListPushFront(pHead, 4);
    ListPushFront(pHead, 5);
    ListPushFront(pHead, 6);
    ListPushFront(pHead, 7);

    ListPrint(pHead);

    ListDestroy(pHead);
}

void ListTest3()
{
    ListNode* pHead = init();
    ListPushFront(pHead, 1);
    ListPushFront(pHead, 2);
    ListPushFront(pHead, 3);
    ListPushFront(pHead, 4);
    ListPushFront(pHead, 5);
    ListPushFront(pHead, 6);
    ListPushFront(pHead, 7);

    ListPrint(pHead);

    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);

    ListPopFront(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);

    ListDestroy(pHead);
}

void ListTest4()
{
    ListNode* pHead = init();
    ListPushFront(pHead, 1);
    ListPushFront(pHead, 2);
    ListPushFront(pHead, 3);
    ListPushFront(pHead, 4);
    ListPushFront(pHead, 5);
    ListPushFront(pHead, 6);
    ListPushFront(pHead, 7);

    ListPrint(pHead);

    ListNode* pos = ListFind(pHead, 3);
    ListInsert(pos, 30);
    ListPrint(pHead);

    ListDestroy(pHead);
}
void ListTest5()
{
    ListNode* pHead = init();
    ListPushFront(pHead, 1);
    ListPushFront(pHead, 2);
    ListPushFront(pHead, 3);
    ListPushFront(pHead, 4);
    ListPushFront(pHead, 5);
    ListPushFront(pHead, 6);
    ListPushFront(pHead, 7);

    ListPrint(pHead);

    ListNode* pos = ListFind(pHead, 3);
    ListErase(pos);
    ListPrint(pHead);

    ListDestroy(pHead);
}


int main(void)
{
//    ListTest1();
//    ListTest2();
    ListTest3();
//    ListTest4();
//    ListTest5();
    return 0;
}
