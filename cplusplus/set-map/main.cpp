#include "set.h"
#include "map.h"


void test_set1() {
	max::set<int> set;
	set.insert(1);
	set.insert(10);
	set.insert(7);
	set.insert(4);
	set.insert(6);

	max::set<int>::iterator it = set.begin();
	while (it != set.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

}

void test_map1() {
	max::map<std::string, std::string> dict;
	dict.insert(std::make_pair("go", "前进"));
	dict.insert(std::make_pair("not", "不"));
	dict.insert(std::make_pair("yes", "是"));
	dict.insert(std::make_pair("back", "后退"));

	max::map<std::string, std::string>::iterator it = dict.begin();
	while (it != dict.end()) {
		std::cout << it->first << ":" << it->second << std::endl;
		++it;
	}

	std::string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	max::map<std::string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		std::cout << kv.first << ":" << kv.second << std::endl;
	}
}

int main() {
	test_set1();
	test_map1();
	return 0;
}