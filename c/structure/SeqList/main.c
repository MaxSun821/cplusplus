#include "SeqList.h"

int main(void)
{
    SL s;
    init(&s);

    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    SLPushBack(&s, 4);
    SLPushBack(&s, 5);
    SLPushFront(&s, 6);
    SLPrint(&s);

    SLInsert(&s, 0, 7);
    SLInsert(&s, 7, 8);
    SLInsert(&s, 3, 9);
    SLPrint(&s);


    SLErase(&s, 0);
    SLErase(&s, 8);
    SLErase(&s, 3);
    SLPrint(&s);

    destroy(&s);
    return 0;
}
