/*
 * 交换两个变量
 */

#include <stdio.h>
void swap(int* num1, int* num2);

int main(void)
{
    int num1, num2;
    printf("请输入两个整数:> ");
    scanf("%i %i", &num1, &num2);

    swap(&num1, &num2);
    printf("交换后，num1=%i, num2=%i\n", num1, num2);
    return 0;
}

void swap(int* num1, int* num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
