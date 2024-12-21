#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("\a");
	printf("\130\n");
	_Bool flag = true;
	printf("%d\n", flag);
	return 0;
}

//int main()
//{
//	const int n = 10;
//	int arr[n] = { 0 };
//	return 0;
//}

//int main()
//{
//	// sum two number
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1, &num2);
//	int sum = num1 + num2;
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int main()
//{
//	int age = 23;
//	float weight = 60.3f;
//	printf("age = %d, weight = %f\n", age, weight);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	return 0;
//}

//int main()
//{
//	printf("Hello, World!\n");
//	return 0;
//}