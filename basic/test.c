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

//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char str1[] = "welcom to c world!!!";
//	char str2[] = "********************";
//	int left = 0;
//	int right = strlen(str1) - 1;
//	while (left <= right)
//	{
//		str2[left] = str1[left];
//		str2[right] = str1[right];
//		printf("%s\n", str2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//
//	printf("%s\n", str2);
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
//	while (num1 % num2 != 0)
//	{
//		int tmp = num1 % num2;
//		num1 = num2;
//		num2 = tmp;
//	}
//	printf("ret: %d\n", num2);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("count: %d\n", count);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int input = 0;
//	printf("Which do you want to find:> ");
//	scanf("%d", &input);
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (input > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (input < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("Find it! It is %d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("Can't find it!\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//bool is_prime(int);
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}
//
//bool is_prime(int num)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(num); i++)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}

//#include <stdio.h>
//#include <stdbool.h>
//
//bool is_leap_year(int);
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (is_leap_year(year))
//	{
//		printf("%d is a leap year\n", year);
//	}
//	else
//	{
//		printf("%d is not a leap year\n", year);
//	}
//	return 0;
//}
//
//bool is_leap_year(int year)
//{
//	return ((year % 4 == 0 && year % 100 != 0) 
//		|| year % 400 == 0);
//}

//#include <stdio.h>
//
//void swap(int*, int*);
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	swap(&a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
//
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//#include <stdio.h>
//
//void mul_exp(int);
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	mul_exp(line);
//	return 0;
//}
//
//void mul_exp(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}

//#include <stdio.h>
//
//void print(int);
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}
//
//void print(int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);
//	}
//	printf("%d ", num % 10);
//}

//#include <stdio.h>
//
//int factorial(int);
//int factorial_recursion(int);
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("factorial: %d\n", factorial(num));
//	printf("factorial_recursion: %d\n", factorial_recursion(num));
//	return 0;
//}
//
//int factorial(int n)
//{
//	int ret = 1;
//	int i = 0;
//	for (i = 2; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int factorial_recursion(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	return n * factorial_recursion(n - 1);
//}

//#include <stdio.h>
//
//int my_strlen(char*);
//int my_strlen_recursion(char*);
//
//int main()
//{
//	char str[] = "hello world";
//	printf("strlen: %d\n", my_strlen(str));
//	printf("strlen_recursion: %d\n", my_strlen_recursion(str));
//	return 0;
//}
//
//int my_strlen(char *str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str += 1;
//	}
//	return count;
//}
//
//int my_strlen_recursion(char *str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return 1 + my_strlen_recursion(str + 1);
//}

//#include <stdio.h>
//#include <string.h>
//
//void reverse_string(char*);
//int my_strlen(char*);
//
//int main()
//{
//	char str[] = "abcdef";
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}
//
//void reverse_string(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) > 1)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
//
//int my_strlen(char *str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str += 1;
//	}
//	return count;
//}

//#include <stdio.h>
//
//int digit_sum(int);
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret = digit_sum(num);
//	printf("ret: %d\n", ret);
//	return 0;
//}
//
//int digit_sum(int num)
//{
//	if (num < 10)
//	{
//		return num;
//	}
//	return num % 10 + digit_sum(num / 10);
//}

//#include <stdio.h>
//
//int my_pow(int n, int k);
//
//int main()
//{
//	int n = 0, k = 0;
//	scanf("%d %d", &n, &k);
//	int ret = my_pow(n, k);
//	printf("ret: %d\n", ret);
//	return 0;
//}
//
//int my_pow(int n, int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	return n * my_pow(n, k - 1);
//}

//#include <stdio.h>
//
//int fib(int);	
//int fib_recursion(int);
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("fib: %d\n", fib(n));
//	printf("fib_recursion: %d\n", fib_recursion(n));
//	return 0;
//}
//
//int fib(int n)
//{
//	int a = 1, b = 1, c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int fib_recursion(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return fib_recursion(n - 1) + fib_recursion(n - 2);
//}

//#include <stdio.h>
//#include <stdbool.h>
//
//void swap(int*, int*);
//void bubble_sort(int*, int);
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, size);
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//
//void bubble_sort(int* arr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size - 1; i++)
//	{
//		bool flag = true;
//		int j = 0;
//		for (j = 0; j < size - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//				flag = false;
//			}
//		}
//		if (flag)
//		{
//			break;
//		}
//	}
//}
//
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//#include <stdio.h>
//
//void init(int* arr, int size);
//void print(int* arr, int size);
//void reverse(int* arr, int size);
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	//init(arr, size);
//	reverse(arr, size);
//	print(arr, size);
//	return 0;
//}
//
//void init(int* arr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int* arr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int* arr, int size)
//{
//	int left = 0;
//	int right = size - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}

//#include <stdio.h>
//
//void exchange_arrays(int* arr1, int* arr2, int size);
//void print(int* arr, int size);
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8 };
//	int arr2[] = { 8,7,6,5,4,3,2,1 };
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//	print(arr1, size);
//	print(arr2, size);
//	printf("exchange...\n");
//	exchange_arrays(arr1, arr2, size);
//	print(arr1, size);
//	print(arr2, size);
//	return 0;
//}
//
//void exchange_arrays(int* arr1, int* arr2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//void print(int* arr, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

#include <stdio.h>

int main()
{
	int arr[10] = {0};
	printf("%d\n", sizeof(arr));

	
	printf("&arr[0]: %p\n", &arr[0]);
	printf("&arr[0]+1: %p\n", &arr[0] + 1);
	printf("&arr: %p\n", &arr);
	printf("&arr+1: %p\n", &arr + 1);
	return 0;
}