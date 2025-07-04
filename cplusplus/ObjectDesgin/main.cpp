#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

// 不能被拷贝的类
class NonCopyable {
public:
	NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete; // 禁止拷贝构造函数
	NonCopyable& operator=(const NonCopyable&) = delete; // 禁止拷贝赋值运算符
	NonCopyable(NonCopyable&&) = default; // 允许移动构造函数
	NonCopyable& operator=(NonCopyable&&) = default; // 允许移动赋值运算符
};

// 只能在堆上创建的类
class NonCopyableOnlyOnHeap {
public:
	NonCopyableOnlyOnHeap(const NonCopyableOnlyOnHeap&) = delete; // 禁止拷贝构造函数
	NonCopyableOnlyOnHeap& operator=(const NonCopyableOnlyOnHeap&) = delete; // 禁止拷贝赋值运算符
	NonCopyableOnlyOnHeap(NonCopyableOnlyOnHeap&&) = default; // 允许移动构造函数
	NonCopyableOnlyOnHeap& operator=(NonCopyableOnlyOnHeap&&) = default; // 允许移动赋值运算符

	static NonCopyableOnlyOnHeap* create() {
		return new NonCopyableOnlyOnHeap(); // 在堆上创建实例
	}

	void destroy() {
		delete this; // 销毁实例
	}
private:
	NonCopyableOnlyOnHeap() = default; // 私有默认构造函数，禁止在栈上创建
	~NonCopyableOnlyOnHeap() {
		std::cout << "NonCopyableOnlyOnHeap destroyed" << std::endl;
	} // 私有析构函数，禁止在栈上创建
};

// 只能在栈上创建的类
class NonCopyableOnlyOnStack {
public:
	static NonCopyableOnlyOnStack create() {
		// 在栈上创建实例
		NonCopyableOnlyOnStack obj;
		std::cout << "NonCopyableOnlyOnStack created" << std::endl;
		return obj;
	}
	void* operator new(size_t i) {
		return malloc(i);
	}
private:
	NonCopyableOnlyOnStack() = default; // 私有默认构造函数，禁止在堆上创建

};

// 单例模式
// 饿汉模式
//class Singleton {
//public:
//	static Singleton* getInstance() {
//		return &instance_; // 返回单例实例的地址
//	}
//	Singleton(const Singleton&) = delete; // 禁止拷贝构造函数
//	Singleton& operator=(const Singleton&) = delete; // 禁止拷贝赋值运算符
//private:
//	Singleton() = default; // 私有构造函数，禁止外部创建实例
//	map<string, string> dict_; // 示例成员变量
//
//	static Singleton instance_; // 静态实例
//};
//
//// 池化技术
//Singleton Singleton::instance_; // 静态实例初始化

// 懒汉模式
class Singleton {
public:
	static Singleton* getInstance() {
		if (!instance_) { // 如果实例不存在
			instance_ = new Singleton(); // 创建实例
		}
		return instance_; // 返回单例实例的地址
	}
	Singleton(const Singleton&) = delete; // 禁止拷贝构造函数
	Singleton& operator=(const Singleton&) = delete; // 禁止拷贝赋值运算符

	static void destroy() {
		if (instance_) {
			delete instance_; // 销毁单例实例
			instance_ = nullptr; // 将指针置为 nullptr
			std::cout << "Singleton destroyed" << std::endl;
		}
	}
private:
	Singleton() = default; // 私有构造函数，禁止外部创建实例
	map<string, string> dict_; // 示例成员变量

	static Singleton* instance_; // 静态实例指针

	class gc {
	public:
		~gc() {
			destroy(); // 在程序结束时销毁单例实例
		}
	};

	static gc garbageCollector; // 静态垃圾收集器，确保在程序结束时销毁单例实例
};

Singleton* Singleton::instance_ = nullptr; // 静态实例指针初始化为 nullptr
Singleton::gc Singleton::garbageCollector; // 静态垃圾收集器实例

int main() {

	//NonCopyable obj1; // 创建一个 NonCopyable 对象
	// 
	// NonCopyable obj2 = obj1; // 错误：不能拷贝

	//NonCopyableOnlyOnHeap* obj3 = NonCopyableOnlyOnHeap::create(); // 在堆上创建 NonCopyableOnlyOnHeap 对象
	//obj3->destroy(); // 销毁对象

	//NonCopyableOnlyOnStack obj4 = NonCopyableOnlyOnStack::create(); // 在栈上创建 NonCopyableOnlyOnStack 对象

	Singleton* singletonInstance = Singleton::getInstance(); // 获取单例实例


	return 0;
}