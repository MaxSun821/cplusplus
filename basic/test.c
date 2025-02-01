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

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = {0};
//	printf("%d\n", sizeof(arr));
//
//	
//	printf("&arr[0]: %p\n", &arr[0]);
//	printf("&arr[0]+1: %p\n", &arr[0] + 1);
//	printf("&arr: %p\n", &arr);
//	printf("&arr+1: %p\n", &arr + 1);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void fun(char* str, int len)
//{
//	printf("%c\n", *str);
//	printf("%c\n", *(str + len - 1));
//
//	*str = *(str + len - 1);
//	printf("%s\n", str);
//}
//
//int main()
//{
//	char* str = "abcdefg";
//	str[0] = 'c';
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	printf("奇数位: ");
//	for (i = 0; i < 32; i+=2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//
//	printf("偶数位: ");
//	for (i = 1; i < 32; i += 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前: a = %d, b = %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后: a = %d, b = %d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//	return 0;
//}
//
//#include <stdio.h>
//
//int main()
//{
//	char str[10001] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		char ch = getchar();
//		if (ch == '\n')
//		{
//			str[i] = '\0';
//			break;
//		}
//		str[i] = ch;
//	}
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//	for (i = 0; i < 5; i++)
//	{
//		tmp = n * pow(10, i) + tmp;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//int get_count(int n);
//bool narcissistic_number(int n, int count);
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100000; i++)
//	{
//		int count = get_count(i);
//		if (narcissistic_number(i, count))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//
//int get_count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n /= 10;
//	}
//	return count;
//}
//
//bool narcissistic_number(int n, int count)
//{
//	int sum = 0;
//	int tmp = n;
//	while (n)
//	{
//		sum += pow(n % 10, count);
//		n /= 10;
//	}
//	return sum == tmp;
//}

//#include <stdio.h>
//
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	// 上半部分
//	for (i = 0; i < line / 2 + 1; i++)
//	{
//		// 打印空格
//		int j = 0;
//		for (j = 0; j < line / 2 - i; j++)
//		{
//			printf(" ");
//		}
//		// 打印*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	// 下半部分
//	for (i = 0; i < line / 2; i++)
//	{
//		// 打印空格
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		// 打印*
//		for (j = 0; j < line - 2 * i - 2; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int money = 0;
//	printf("请输入你有多少钱：");
//	scanf("%d", &money);
//
//
//	int total = money;
//	int empty = money;
//	while (empty > 1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//
//	printf("你一共可以喝到：%d瓶水。\n", total);
//
//	return 0;
//}

//#include <stdio.h>
//
//extern int g_val;
//
//int main()
//{
//	
//	printf("%d\n", g_val);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	size_t count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = "hello world";
//	printf("strlen: %d\n", my_strlen(str));
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src);
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "****************";
//
//	printf("%s\n", my_strcpy(str2, str1));
//	return 0;
//}
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	char* ret = dest;
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}

//#include <stdio.h>
//#include <assert.h>
//
//void exchange_arrays(int* arr, int size);
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	exchange_arrays(arr, 10);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//void exchange_arrays(int* arr, int size)
//{
//	assert(arr != NULL);
//	int left = 0;
//	int right = size - 1;
//
//	while (left < right)
//	{
//		while (left < right && arr[left] % 2 != 0)
//		{
//			++left;
//		}
//		while (left < right && arr[right] % 2 == 0)
//		{
//			--right;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			++left;
//			--right;
//		}
//	}
//}


//#include <stdio.h>
//
//int main()
//{
//	int trangle[10][10] = { 0 };
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || j == i)
//			{
//				trangle[i][j] = 1;
//			}
//			else
//			{
//				trangle[i][j] = trangle[i - 1][j - 1] + trangle[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", trangle[i][j]);
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer: %c\n", killer);
//			break;
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (a * b * c * d * e == 120)
//						{
//							if ((b == 2) + (a == 3) == 1 &&
//								(b == 2) + (e == 4) == 1 &&
//								(c == 1) + (d == 2) == 1 &&
//								(c == 5) + (d == 3) == 1 &&
//								(e == 4) + (a == 1) == 1)
//							{
//								printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	float f = 5.5f;
//	printf("%f\n", f);
//	return 0;
//}

//#include <stdio.h>
//
//void test(char* ptr, int arr[])
//{
//
//}
//
//int main()
//{
//	void (*pf)(char*, int*) = test;
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdbool.h>
//
//bool find_num(int arr[5][5], int row, int col, int num);
//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},
//		{6,7,8,9,10},
//		{11,12,13,14,15},
//		{16,17,18,19,20},
//		{21,22,23,24,25} };
//	int num = 0;
//	scanf("%d", &num);
//	int row = sizeof(arr) / sizeof(arr[0]);
//	int col = sizeof(arr[0]) / sizeof(arr[0][0]);
//	bool ret = find_num(arr, row, col, num);
//
//	if (ret)
//	{
//		printf("Find it!\n");
//	}
//	else
//	{
//		printf("Can't find it!\n");
//	}
//
//	return 0;
//}
//
//bool find_num(int arr[5][5], int row, int col, int num)
//{
//	int i = 0;
//	int j = col - 1;
//	while (i < row && j >= 0)
//	{
//		if (arr[i][j] == num)
//		{
//			return true;
//		}
//		else if (arr[i][j] > num)
//		{
//			j--;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return false;
//}


//#include <stdio.h>
//#include <string.h>
//
//char* turn_left(char* str, int length, int step);
//void swap(char* str, int index1, int index2);
//int main()
//{
//	char str[] = "ABCD";
//	int length = strlen(str);
//	int step = 0;
//	scanf("%d", &step);
//
//	printf("%s\n", turn_left(str, length, step));
//	return 0;
//}
//
//char* turn_left(char* str, int length, int step)
//{
//	step %= length;
//
//	int begin = 0;
//	int end = length - 1;
//	int left_end = step - 1;
//	int right_begin = step;
//
//	while (begin < left_end)
//	{
//		swap(str, begin, left_end);
//		++begin;
//		--left_end;
//	}
//
//	while (right_begin < end)
//	{
//		swap(str, right_begin, end);
//		++right_begin;
//		--end;
//	}
//
//	begin = 0;
//	end = length - 1;
//
//	while (begin < end)
//	{
//		swap(str, begin, end);
//		++begin;
//		--end;
//	}
//	return str;
//}
//
//void swap(char* str, int index1, int index2)
//{
//	char tmp = str[index1];
//	str[index1] = str[index2];
//	str[index2] = tmp;
//}

//#include <stdio.h>
//#include <string.h>
//
//void bubble_sort(void* base, size_t num, size_t size, int (*compare_int)(const void*, const void*));
//void swap(char* base1, char* base2, size_t size);
//int compare_int(const void* p1, const void* p2);
//int struct_compare_by_name(const void* p1, const void* p2);
//
//struct student
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	int arr[] = { 1,7,9,4,6,5,3,2,10,8 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, num, sizeof(arr[0]), compare_int);
//	struct student s[] = { {"zhangsan", 20},{"lisi", 23},{"wangwu", 34} };
//	int num2 = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, num2, sizeof(s[0]), struct_compare_by_name);
//	return 0;
//}
//
//int compare_int(const void* p1, const void* p2)
//{
//	// 比较函数，升序
//	return *((int*)p2) - *((int*)p1); // 将void*强制类型转换成int*
//}
//
//int struct_compare_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct student*)p1)->name, ((struct student*)p2)->name);
//}
//
//void bubble_sort(void* base, size_t num, size_t size, int (*compare_int)(const void*, const void*))
//{
//
//	size_t i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (compare_int((((char*)base) + j * size), ((char*)base) + (j + 1) * size) > 0)
//			{
//				swap((((char*)base) + j * size), ((char*)base) + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//void swap(char* base1, char* base2, size_t size)
//{
//	size_t i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char tmp = base1[i];
//		base1[i] = base2[i];
//		base2[i] = tmp;
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare_int(const void* p1, const void* p2);
//int compare_by_age(const void* p1, const void* p2);
//
//struct student
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	int int_array[] = { 7,3,4,1,0,8,9,6,5,2 };
//	int size1 = sizeof(int_array) / sizeof(int_array[0]);
//	qsort(int_array, size1, sizeof(int_array[0]), compare_int);
//	struct student s[] = { {"zhangsan", 29},{"lisi", 17},{"wangwu", 34} };
//	int size2 = sizeof(s) / sizeof(s[0]);
//	qsort(s, size2, sizeof(s[0]), compare_by_age);
//	return 0;
//}
//
//int compare_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//int compare_by_age(const void* p1, const void* p2)
//{
//	return ((struct student*)p1)->age - ((struct student*)p2)->age;
//}

#include <stdio.h>
#include <string.h>

int check_turn(char* str1, char* str2);
int main()
{
	char str1[] = "AABCD";
	char str2[] = "ABCDA";
	if (check_turn(str1, str2))
	{
		printf("是旋转得到的\n");
	}
	else
	{
		printf("不是旋转得到的\n");
	}
	return 0;
}

int check_turn(char* str1, char* str2)
{
	char tmp[50] = { 0 };
	strcat(tmp, str1);
	strcat(tmp, str2);
	return strstr(tmp, str2) != NULL;
}