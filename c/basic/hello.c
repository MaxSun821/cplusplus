

//#include <stdio.h>

//int main(void)
//{
//    printf("hello world\n");
//    return 0;
//}

//int main(void)
//{
//    printf("%i\n", sizeof(char));
//    printf("%i\n", sizeof(short));
//    printf("%i\n", sizeof(int));
//    printf("%i\n", sizeof(long));
//    printf("%i\n", sizeof(long long));
//    printf("%i\n", sizeof(float));
//    printf("%i\n", sizeof(double));
//
//    return 0;
//}

//int b = 20; // 全局变量
//
//int main(void)
//{
//    int a = 10; // 局部变量
//    return 0;
//}

//int main(void)
//{
//    const int a = 10;
//    int arr[a];
//    return 0;
//}

//enum COLOR
//{
//    RED,
//    YELLOW,
//    GREEN
//};
//int main(void)
//{
//    printf("%i\n", RED);
//    printf("%i\n", YELLOW);
//    printf("%i\n", GREEN);
//
//    return 0;
//}

//#define MAX 100
//int main(void)
//{
//    printf("%i\n", MAX);
//    return 0;
//}

//#include <string.h>
//
//int main(void)
//{
//    char str[] = "abcd";
//    char str2[] = {'a', 'b', 'c'};
//    printf("%i\n", strlen(str));
//    printf("%i\n", strlen(str2));
//
//    return 0;
//}

int g_val = 4;

static int Add(int x, int y)
{
    return x + y;
}
