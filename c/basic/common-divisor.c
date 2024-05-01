/*
 * 两个数的最大公约数
 */

#include <stdio.h>

int GetCommonDiv(int, int);

int main(void)
{
    int num1, num2;
    printf("请输入两个整数:> ");
    scanf("%i %i", &num1, &num2);
    int ret = GetCommonDiv(num1, num2);
    printf("%i %i的最大公约数是: %i\n", num1, num2, ret);
    return 0;
}

int GetCommonDiv(int x, int y)
{
    int z = y % x;
    while(z != 0)
    {
        y = x;
        x = z;
        z = y % x;
    }
    return x;
}
