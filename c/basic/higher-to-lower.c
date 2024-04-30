/*
 * 三个整数从大到小输出
 */

#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    printf("请输入三个整数:>");
    scanf("%i %i %i", &num1, &num2, &num3);
    if(num1 > num2 && num1 > num3)
    {
        if(num2 > num3)
        {
            printf("%i %i %i\n", num1, num2, num3);
        }
        else
        {
            printf("%i %i %i\n", num1, num3, num2);
        }
    }
    else if(num2 > num1 && num2 > num3)
    {
        if(num1 > num3)
        {
            printf("%i %i %i\n", num2, num1, num3);
        }
        else
        {
            printf("%i %i %i\n", num2, num3, num1);
        }
    }
    else
    {
        if(num1 > num2)
        {
            printf("%i %i %i\n", num3, num1, num2);
        }
        else
        {
            printf("%i %i %i\n", num3, num2, num1);
        }
    }

    return 0;
}
