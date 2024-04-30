/*
 * 打印1000-2000的闰年
 */

#include <stdio.h>

int GetLeapYear(int);

int main(void)
{
    for(int i = 1000; i <= 2000; i++)
    {
        if(GetLeapYear(i) == 1)
        {
            printf("%i ", i);
        }
    }
    return 0;
}

int GetLeapYear(int year)
{
    if((year % 4 == 0 && year% 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    return 0;
}
