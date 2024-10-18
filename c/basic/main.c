

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//extern int Add(int, int);
//int main(void)
//{
//    int ret = Add(1, 2);
//    printf("%i\n", ret);
//    return 0;
//}

//int main(void)
//{
//    char strs1[] = "are you ok???";
//    char strs2[] = "#############";
//
//    int left = 0;
//    int right = strlen(strs1) - 1;
//
//    while(left <= right)
//    {
//        strs2[left] = strs1[left];
//        strs2[right] = strs1[right];
//        left++;
//        right--;
//        sleep(1);
//        printf("%s\n", strs2);
//        system("Clear All");
//    }
//    return 0;
//}

int* sockCollocation(int* sockets, int socketsSize) {
    int ret = 0;
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i < socketsSize; i++)
    {
        ret ^= sockets[i];
    }
    // 找出ret哪一位是1
    int pos = 0;
    for(pos = 0; pos < 32; pos++)
    {
        if((ret & (1 << pos)) == 1)
        {
            break;
        }
    }
    for(int i = 0; i < socketsSize; i++)
    {
        if(sockets[i] & (1 << pos) == 1)
        {
            num1 ^= sockets[i];
        }
        else
        {
            num2 ^= sockets[i];
        }
    }

    int* returnSize = (int*)malloc(2 * sizeof(int));
    returnSize[0] = num1;
    returnSize[1] = num2;

    return returnSize;
}

int main(void)
{
    int sockets[] = {4, 5, 2, 4, 6, 6};
    int socketsSize = 6;

    int* returnSize = sockCollocation(sockets, socketsSize);
    free(returnSize);

    return 0;
}


