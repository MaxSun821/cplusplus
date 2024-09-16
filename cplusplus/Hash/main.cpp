//#include <iostream>
//#include <unordered_set>
//#include <unordered_map>
//
//int main()
//{
//	std::unordered_set<int> set;
//	set.insert(5);
//	set.insert(7);
//	set.insert(10);
//	set.insert(2);
//	set.insert(9);
//
//	std::unordered_set<int>::iterator it = set.begin();
//	while (it != set.end())
//	{
//		std::cout << *it << " ";
//		++it;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

//#include "hash_table.h"
#include "hash_backet.h"
#include <unordered_set>
#include <set>

int main()
{
//	max::HashTable<int, int> hashTable;
//	int arr[] = { 7, 5, 14, 4, 9, 11, 6, 36, 89, 35 };
//
//	for(int i = 0; i < 10; i++)
//	{
//		hashTable.insert(std::pair<int, int>(arr[i], arr[i]));
//	}
//
//	hashTable.print();
//	std::cout << std::endl;
//
//	hashTable.erase(6);
//	hashTable.print();
//	std::cout << std::endl;
//
//	hashTable.insert(std::make_pair(6, 6));
//	hashTable.insert(std::make_pair(26, 26));
//	hashTable.print();
//	std::cout << std::endl;


//	max::test1();
	hash_backet::test2();
//	hash_backet::test1();

//	const size_t N = 100000;
//
//	std::unordered_set<int> us;
//	std::set<int> s;
//	hash_backet::HashTable<int, int> hashTable;
//
//	std::vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		//v.push_back(rand()); // N比较大时，重复值比较多
//		v.push_back(rand()+i); // 重复值相对少
//		//v.push_back(i); // 没有重复，有序
//	}
//
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	std::cout << "set insert:" << end1 - begin1 << std::endl;
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	std::cout << "unordered_set insert:" << end2 - begin2 << std::endl;
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		hashTable.insert(std::make_pair(e, e));
//	}
//	size_t end3 = clock();
//	std::cout << "HashTable insert:" << end3 - begin3 << std::endl;





	return 0;
}