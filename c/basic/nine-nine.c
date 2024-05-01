/*
 * 9*9乘法表
 */

#include <stdio.h>

int main(void)
{

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%i * %i = %i\t", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}