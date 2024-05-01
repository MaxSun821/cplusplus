/*
 * 二分查找
 */

#include <stdio.h>

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 13;
    int left = 0;
    int right = size - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] < key)
        {
            left = mid + 1;
        }
        else if(arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            printf("找到了，下标是：%i\n", mid);
            break;
        }
    }
    if(left > right)
    {
        printf("没找到\n");
    }
    return 0;
}
