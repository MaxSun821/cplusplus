/*
 * 求10个整数总的最大值
 */

#include <stdio.h>

int main(void)
{
    int arr[10] = {0};
    for(int i = 0; i < 10; i++)
    {
        scanf("%i", arr + i);
    }
    int max = arr[0];
    for(int i = 1; i < 10; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("最大值为：%i\n", max);
    return 0;
}
