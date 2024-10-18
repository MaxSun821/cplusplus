#include <iostream>
#include <map>
#include <string>


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

//class HeapOnly
//{
//public:
//	static HeapOnly* create_obj()
//	{
//		return new HeapOnly;
//	}
//
//	HeapOnly(const HeapOnly& hp) = delete;
//	// 方案二：构造函数私有化
//private:
//	HeapOnly()
//	{
//		std::cout << "HeapOnly()" << std::endl;
//	}
//};
//
//// 创建一个类，只能在栈上创建对象
//class StackOnly
//{
//public:
//	static StackOnly create_obj()
//	{
//		StackOnly obj;
//		return obj;
//	}
//
//	// 为防止new StackOnly(obj)
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly()
//	{
//		std::cout << "StackOnly()" << std::endl;
//	}
//};

// 单例模式
// 饿汉模式
class A
{
 public:
	static A* get_instance()
	{
		return &_init;
	}
	void push(const std::string& s1, const std::string& s2)
	{
		_dict[s1] = s2;
	}
	void print()
	{
		for (auto& kv: _dict)
		{
			std::cout << kv.first << ":" << kv.second << std::endl;
		}
	}
 private:
	A() {}
	A(const A& copy) = delete;
	A& operator=(const A& copy) = delete;
	std::map<std::string, std::string> _dict;
	static A _init;
};

// 懒汉模式
class B
{
 public:
	static B* get_instance()
	{
		if(_init == nullptr)
		{
			_init = new B;
		}
		return _init;
	}
	void push(const std::string& s1, const std::string& s2)
	{
		_dict[s1] = s2;
	}
	void print()
	{
		for (auto& kv: _dict)
		{
			std::cout << kv.first << ":" << kv.second << std::endl;
		}
	}
	static void del_instance()
	{
		if(_init)
		{
			delete _init;
			_init = nullptr;
		}
	}
 private:
	B() {}
	B(const B& copy) = delete;
	B& operator=(const B& copy) = delete;
	~B()
	{
		del_instance();
	}
	std::map<std::string, std::string> _dict;
	static B* _init;
	class gc
	{
	 public:
		// 回收内部类
		~gc()
		{
			del_instance();
		}
	};
	static gc _gc;

};

A A::_init;
B* B::_init = nullptr;
B::gc B::_gc;


int main()
{
	//HeapOnly hp1;
	/*HeapOnly* hp2 = new HeapOnly;
	hp2->destroy();*/

	//HeapOnly* hp3 = HeapOnly::create_obj();

	//StackOnly* st = new StackOnly;
	//StackOnly st = StackOnly::create_obj();
	//StackOnly* st2 = new StackOnly(st);

	A::get_instance()->push("cat", "猫");
	A::get_instance()->push("dog", "狗");
	A::get_instance()->push("bird", "鸟");

	A::get_instance()->print();

	B::get_instance()->push("cat", "猫");
	B::get_instance()->push("dog", "狗");
	B::get_instance()->push("bird", "鸟");

	B::get_instance()->print();

	std::ostream out(nullptr);


	return 0;
}