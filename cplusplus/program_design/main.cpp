#include <iostream>


// 设计一个类，只能在堆上创建对象

//class HeapOnly
//{
//	// 方案一的释放资源
//public:
//	void destroy()
//	{
//		delete this;
//	}
//	// 方案一：析构函数私有化
//private:
//	~HeapOnly()
//	{
//		std::cout << "~HeapOnly()" << std::endl;
//	}
//};

class HeapOnly
{
public:
	static HeapOnly* create_obj()
	{
		return new HeapOnly;
	}

	HeapOnly(const HeapOnly& hp) = delete;
	// 方案二：构造函数私有化
private:
	HeapOnly()
	{
		std::cout << "HeapOnly()" << std::endl;
	}
};

// 创建一个类，只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly create_obj()
	{
		StackOnly obj;
		return obj;
	}

	// 为防止new StackOnly(obj)
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	StackOnly()
	{
		std::cout << "StackOnly()" << std::endl;
	}
};

int main()
{
	//HeapOnly hp1;
	/*HeapOnly* hp2 = new HeapOnly;
	hp2->destroy();*/

	//HeapOnly* hp3 = HeapOnly::create_obj();

	//StackOnly* st = new StackOnly;
	StackOnly st = StackOnly::create_obj();
	//StackOnly* st2 = new StackOnly(st);

	return 0;
}