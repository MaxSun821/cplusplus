#pragma once

#include "hash_backet.h"

namespace max
{
	template<class K, class V, class Hash = hash_backet::HashFunc<K>>

	class unordered_map
	{
		struct MapOfKV
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	 public:
		typedef typename hash_backet::HashTable<K, std::pair<K, V>, MapOfKV, Hash>::iterator iterator;

		iterator begin()
		{
			return _table.begin();
		}
		iterator end()
		{
			return _table.end();
		}

		std::pair<iterator, bool> insert(const std::pair<K, V>& kv)
		{
			return _table.insert(kv);
		}

		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = _table.insert(std::make_pair(key, V()));
			return ret.first->second;
		}

		const V& operator[](const K& key) const
		{
			std::pair<iterator, bool> ret = _table.insert(std::make_pair(key, V()));
			return ret.first->second;
		}

		iterator find(const K& key)
		{
			return _table.find(key);
		}

		bool erase(const K& key)
		{
			return _table.erase(key);
		}

	 private:
		hash_backet::HashTable<K, std::pair<K, V>, MapOfKV, Hash> _table;
	};

	void test_map()
	{
		unordered_map<std::string, std::string> dict;
		dict.insert(std::make_pair("panda", "熊猫"));
		dict.insert(std::make_pair("cat", "猫"));
		dict.insert(std::make_pair("dog", "狗"));

		unordered_map<std::string, std::string>::iterator it = dict.begin();
		while(it != dict.end())
		{
			std::cout << it->first << "->" << it->second << std::endl;
			++it;
		}

		std::string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		unordered_map<std::string, int> count_map;
		for (auto& e : arr)
		{
			count_map[e]++;
		}

		for (auto& kv : count_map)
		{
			std::cout << kv.first << ":" << kv.second << std::endl;
		}
		std::cout << std::endl;
	}
}
