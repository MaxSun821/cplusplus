/*
 * 打印100-200之间的素数
 */

#include <stdio.h>
#include <math.h>


int GetPrimeNum(int);

int main(void)
{
    for(int i = 100; i <= 200; i++)
    {
        if(GetPrimeNum(i) == 1)
        {
            printf("%i ", i);
        }
    }
    return 0;
}

int GetPrimeNum(int n)
{
    int flag = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            return flag;
        }
    }
    return flag;
}
