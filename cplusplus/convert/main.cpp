#include <iostream>

using namespace std;

//int main()
//{
//	// 不能用于两个不相关类型转换
//	double d = 11.1;
//	int a = static_cast<int>(d);
//
//	cout << a << endl;
//
//	// reinterpret_cast用于将一种类型转换为另一种不同的类型
//	int* p = reinterpret_cast<int*>(a);
//
//	return 0;
//}

class A
{
public:
	virtual void func()
	{
		_a += 1;
	}

	int _a = 0;
};

class B : public A
{
public:
	void func()
	{
		_b += 1;
	}
	int _b = 0;
};


void test(A* pa)
{
	/*B* pb = (B*)pa;
	pb->_a = 3;
	pb->_b = 10;*/

	// dynamic_cast判断多态情况，向下转换。
	B* pb = dynamic_cast<B*>(pa);

	if (pb)
	{
		pb->func();
	}
	else
	{
		cout << "转换失败" << endl;
	}
}

int main()
{
	volatile const int a = 2;

	int* p = const_cast<int*>(&a);
	
	*p += 1;

	cout << a << endl;
	cout << *p << endl;

	cout << &a << endl;
	cout << p << endl;

	A aa;
	B bb;

	test(&aa);
	test(&bb);



	return 0;
}