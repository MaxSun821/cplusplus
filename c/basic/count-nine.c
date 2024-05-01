/*
 * 1到 100 的所有整数中出现多少个数字9
 */

#include <stdio.h>

int main(void)
{
    int count = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(i % 10 == 9)
        {
            // 个位是9
            count++;
        }
        if(i / 10 == 9)
        {
            // 十位是9
            count++;
        }
    }
    printf("1到 100 的所有整数中出现 %i 个数字9", count);
    return 0;
}
