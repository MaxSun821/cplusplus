/*
 * 求两个数的较大值
 */

#include <stdio.h>

int greater(int, int);

int main(void)
{
    int a;
    int b;
    printf("请输入两个数字：");
    scanf("%d %d", &a, &b);

    int max = greater(a, b);
    printf("%d\n", max);
    return 0;
}

int greater(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
