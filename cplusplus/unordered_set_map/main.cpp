#include "my_unordered_set.h"
#include "my_unordered_map.h"

int main() {
	max::unordered_set<int> my_set;
	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);
	my_set.insert(4);

	max::unordered_set<int>::iterator it = my_set.begin();
	while (it != my_set.end()) {
		std::cout << *it << " ";
		++it;
	}
	cout << endl;

	max::unordered_map<string, string> dict;
	dict.insert(make_pair("hello", "world"));
	dict.insert(make_pair("foo", "bar"));

	max::unordered_map<string, string>::iterator map_it = dict.begin();
	while(map_it != dict.end()) {
		cout << map_it->first << ": " << map_it->second << endl;
		++map_it;
	}
	
	string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	max::unordered_map<string, int> count_map;
	for (auto& e : arr)
	{
		count_map[e]++;
	}

	for (auto& kv : count_map)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	return 0;
}