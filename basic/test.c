#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	printf("Hello, World!\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//
//int main()
//{
//	printf("char size: %d\n", sizeof(char));
//	printf("short size: %d\n", sizeof(short));
//	printf("int size: %d\n", sizeof(int));
//	printf("long size: %d\n", sizeof(long));
//	printf("long long size: %d\n", sizeof(long long));
//	printf("float size: %d\n", sizeof(float));
//	printf("double size: %d\n", sizeof(double));
//	printf("bool size: %d\n", sizeof(bool));
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//
//	int sum = num1 + num2;
//	printf("sum: %d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int get_max(int num1, int num2);
//
//int main()
//{
//	int max = get_max(10, 5);
//	printf("max: %d\n", max);
//	return 0;
//}
//
//int get_max(int num1, int num2)
//{
//	return num1 > num2 ? num1 : num2;
//}

//#include <stdio.h>
//
//extern int g_val;
//int main()
//{
//	printf("g_val: %d\n", g_val);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int num3 = 0;
//	scanf("%d %d %d", &num1, &num2, &num3);
//
//	if (num1 > num2 && num1 > num3)
//	{
//		if (num2 > num3)
//		{
//			printf("%d %d %d\n", num1, num2, num3);
//		}
//		else
//		{
//			printf("%d %d %d\n", num1, num3, num2);
//		}
//	}
//	else if (num2 > num1 && num2 > num3)
//	{
//		if (num1 > num3)
//		{
//			printf("%d %d %d\n", num2, num1, num3);
//		}
//		else
//		{
//			printf("%d %d %d\n", num2, num3, num1);
//		}
//	}
//	else
//	{
//		if (num1 > num2)
//		{
//			printf("%d %d %d\n", num3, num1, num2);
//		}
//		else
//		{
//			printf("%d %d %d\n", num3, num2, num1);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("max: %d\n", max);
//	return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//int main()
//{
//	int i = 100;
//	
//	for (i = 100; i <= 200; i++)
//	{
//		bool is_prime = true;
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				is_prime = false;
//				break;
//			}
//		}
//		if (is_prime)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 1000;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	double ret = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			ret -= 1.0 / i;
//		}
//		else
//		{
//			ret += 1.0 / i;
//		}
//	}
//	printf("ret: %lf\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	long long sum = 0L;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 1;
//		long ret = 1L;
//		for (j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("sum: %lld\n", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	long long sum = 0L;
//	long ret = 1L;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("sum: %lld\n", sum);
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
	char str1[] = "welcom to c world!!!";
	char str2[] = "********************";
	int left = 0;
	int right = strlen(str1) - 1;
	while (left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		printf("%s\n", str2);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}

	printf("%s\n", str2);
	return 0;
}