/*
 * 打印1-100之间所有3的倍数
 */

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            printf("%i ", i);
        }
    }
    return 0;
}
