
#include "SeqList.h"


void init(SL* psl)
{
    // 顺序表初始化
    psl->a = (SLDataType*)malloc(sizeof(SLDataType) * 5);
    if(psl->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    psl->size = 0;
    psl->capacity = 5;
}


void SLPushBack(SL* psl, SLDataType x)
{
    SLCheckCapacity(psl);

    psl->a[psl->size++] = x;
}
void SLPushFront(SL* psl, SLDataType x)
{
    SLCheckCapacity(psl);

    // 移动数据
    for (int i = psl->size; i > 0; --i)
    {
        psl->a[i] = psl->a[i - 1];
    }
    psl->a[0] = x;
    psl->size++;
}
void SLPopBack(SL* psl)
{
    assert(psl); // 判断psl不为空指针
    assert(psl->size > 0);
    psl->size--;
}
void SLPopFront(SL* psl)
{
    assert(psl); // 判断psl不为空指针
    assert(psl->size > 0);
    for (int i = 1; i < psl->size; ++i)
    {
        psl->a[i - 1] = psl->a[i];
    }
    psl->size--;
}

void SLInsert(SL* psl, int index, SLDataType x)
{
    SLCheckCapacity(psl);

    assert(index >= 0 && index <= psl->size);
    if(index == psl->size)
    {
        SLPushBack(psl, x);
    }
    else if(index == 0)
    {
        SLPushFront(psl, x);
    }
    else
    {
        for (int i = psl->size; i > index; --i)
        {
            psl->a[i] = psl->a[i - 1];
        }
        psl->a[index] = x;
        psl->size++;
    }

}
void SLErase(SL* psl, int index)
{
    assert(psl);
    assert(index >= 0 && index < psl->size);
    if(index > psl->size || index < 0)
    {
        printf("下标不合法\n");
        return;
    }

    if(index == 0)
    {
        SLPopFront(psl);
    }
    else if(index == psl->size - 1)
    {
        SLPopBack(psl);
    }
    else
    {
        for (int i = index; i < psl->size - 1; ++i)
        {
            psl->a[i] = psl->a[i + 1];
        }
        psl->size--;
    }
}

int SLFind(SL* psl, SLDataType key)
{
    // 查找元素
    for (int i = 0; i < psl->size; ++i)
    {
        if(psl->a[i] == key)
        {
            return i;
        }
    }
    return -1;
}



void SLCheckCapacity(SL* psl)
{
    assert(psl);
    if(psl->size == psl->capacity)
    {
        // 扩容
        SLDataType* tmp = (SLDataType*) realloc(psl->a, sizeof(SLDataType) * psl->capacity * 2);
        if(tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        psl->a = tmp;
        psl->capacity *= 2;
    }
}




void SLPrint(SL* psl)
{
    assert(psl);
    for (int i = 0; i < psl->size; ++i) {
        printf("%i ", psl->a[i]);
    }
    printf("\n");
}



void destroy(SL* psl)
{
    // 销毁
    free(psl->a);
    psl->a = NULL;
    psl->size = 0;
    psl->capacity = 0;
}
