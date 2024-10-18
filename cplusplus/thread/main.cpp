#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//void print(size_t n, const std::string& s);

//int main()
//{
//	std::thread t1(print, 10, "show");
//	t1.join();
//	return 0;
//}

//int main()
//{
//	size_t n1 = 0;
//	size_t n2 = 0;
//
//	std::cin >> n1 >> n2;
//
//	std::thread t1([n1]() {
//		for (size_t i = 0; i < n1; i++)
//		{
//			std::cout << std::this_thread::get_id() << ": " << i << std::endl;
//		}
//	});
//
//	std::thread t2([n2]() {
//		for (size_t i = 0; i < n2; i++)
//		{
//			std::cout << std::this_thread::get_id() << ": " << i << std::endl;
//		}
//	});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

// 交替打印奇数偶数
int main()
{
	std::mutex m;
	int x = 1;
	std::condition_variable cv;
	bool flag = false;
	
	std::thread t1([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			std::unique_lock<std::mutex> lock(m);
			while (flag)
			{
				cv.wait(lock);
			}
			std::cout << std::this_thread::get_id() << ": " << x << std::endl;
			++x;
			flag = true;
			cv.notify_one();
		}
	});

	std::thread t2([&]() {
		for (size_t i = 0; i < 10; i++)
		{
			std::unique_lock<std::mutex> lock(m);
			while (!flag)
			{
				cv.wait(lock);
			}
			std::cout << std::this_thread::get_id() << ": " << x << std::endl;
			++x;
			flag = false;
			cv.notify_one();
		}
	});

	t1.join();
	t2.join();

	return 0;
}


//void print(size_t n, const std::string& s)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		std::cout << s << ": " << i << std::endl;
//	}
//}