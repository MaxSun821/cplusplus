#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace max
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};
	template<class K, class V>
	struct HashData
	{
		std::pair<K, V> _data;
		Status _s;
	};

	// 为解决string类型不能计算哈希值，创造仿函数
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct HashFunc<std::string>
	{
		size_t operator()(const std::string& key)
		{
			size_t hashi = 0;
			for (auto e : key)
			{
				hashi *= 31;
				hashi += e;
			}
			return hashi;
		}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	 public:
		HashTable()
			: _n(0)
		{
			_v.resize(10);
		}
		bool insert(const std::pair<K, V> data)
		{
			if (find(data.first))
			{
				return false;
			}
			// 扩容，设置负载因子为0.75
			if ((double)_n / _v.size() >= 0.75)
			{
				size_t newCapacity = _v.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._v.resize(newCapacity);

				for (int i = 0; i < _v.size(); i++)
				{
					if (_v[i]._s == EXIST)
					{
						newHT.insert(_v[i]._data);
					}
				}
				_v.swap(newHT._v);
			}

			Hash hashFunc;

			// 计算哈希值
			size_t hashi = hashFunc(data.first) % _v.size();
			while (_v[hashi]._s == EXIST)
			{
				// 计算出的哈希值位置存在元素
				// 顺序取值
				++hashi;

				hashi %= _v.size();
			}
			_v[hashi]._data = data;
			_v[hashi]._s = EXIST;
			++_n;
			return true;
		}

		HashData<K, V>* find(const K& key)
		{
			Hash hashFunc;
			// 计算哈希值
			size_t hashi = hashFunc(key) % _v.size();
			while (_v[hashi]._s != EMPTY)
			{
				if (_v[hashi]._data.first == key && _v[hashi]._s == EXIST)
				{
					return &_v[hashi];
				}
				++hashi;

				hashi %= _v.size();
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData<K, V>* ret = find(key);
			ret->_s = DELETE;
			--_n;
		}

		void print()
		{
			for (int i = 0; i < _v.size(); ++i)
			{
				if (_v[i]._s == EXIST)
				{
					std::cout << i << "->" << _v[i]._data.first << ":" << _v[i]._data.second << std::endl;
				}
				else if (_v[i]._s == EMPTY)
				{
					std::cout << i << "-> EMPTY" << std::endl;
				}
				else
				{
					std::cout << i << "-> DELETE" << std::endl;
				}
			}
		}
	 private:
		std::vector<HashData<K, V>> _v;
		size_t _n; // 记录哈希表中有几个元素
	};
	void test1()
	{
		std::string arr[] = { "苹果", "桃子", "橙子", "苹果", "栗子" };
		HashTable<std::string, int> hashTable;
		for (int i = 0; i < 5; ++i)
		{
			HashData<std::string, int>* ret = hashTable.find(arr[i]);
			if (ret)
			{
				ret->_data.second++;
			}
			else
			{
				hashTable.insert(std::make_pair(arr[i], 1));
			}
		}
		hashTable.print();
	}

	void test2()
	{
		int arr[] = {5, 6, 3, 10, 7, 2, 1, 4};

		HashTable<int, int> hashTable;

		for(int i : arr)
		{
			hashTable.insert(std::make_pair(i, i));
		}

		hashTable.print();

	}
}
