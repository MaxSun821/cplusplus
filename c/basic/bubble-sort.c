/*
 * 冒泡排序
 */

#include <stdio.h>
void swap(int* x, int* y);
int main(void)
{
    int arr[] = {4,2,76,1,3,48,2,3,53,67,19};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    return 0;
}
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
