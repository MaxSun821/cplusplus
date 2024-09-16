#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace hash_backet
{
	template<class K, class V>
	struct node
	{
		node(const std::pair<K, V>& data)
			: _next(nullptr), _data(data)
		{
		}
		node* _next; // 指向下一个节点
		std::pair<K, V> _data;
	};

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
		typedef struct node<K, V> node;
	 public:
		HashTable()
			: _n(0)
		{
			_table.resize(10);
		}
		~HashTable()
		{
			// 析构函数
			for (int i = 0; i < _table.size(); ++i)
			{
				node* cur = _table[i];
				while (cur)
				{
					node* curNext = cur->_next;
					delete cur;
					cur = curNext;
				}
				_table[i] = nullptr;
			}
		}
		bool insert(const std::pair<K, V>& data)
		{
			if (find(data.first))
			{
				return false;
			}
			Hash hash;
			if (_n == _table.size())
			{
				// 负载因子为1
				size_t newCapacity = _table.size() * 2;
				std::vector<node*> newTable;
				newTable.resize(newCapacity, nullptr);

				for (int i = 0; i < _table.size(); i++)
				{
					node* cur = _table[i];
					while (cur)
					{
						node* curNext = cur->_next;

						size_t hashi = hash(cur->_data.first) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = curNext;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}
			size_t hashi = hash(data.first) % _table.size();
			// 创建新节点
			node* newNode = new node(data);
			// 采用头插法
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;

			++_n;
			return true;

		}

		node* find(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _table.size();
			node* cur = _table[hashi];

			while (cur)
			{
				if (cur->_data.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _table.size();
			node* prev = nullptr;
			node* cur = _table[hashi];

			while (cur)
			{
				node* curNext = cur->next;
				if (cur->_data.first == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				prev = cur;
				cur = curNext;
			}
			return false;
		}

	 private:
		std::vector<node*> _table;
		size_t _n;
	};

	void test1()
	{
		int arr[] = { 5, 16, 6, 8, 33, 25, 10 };
		HashTable<int, int> hashTable;
		for (int i : arr)
		{
			hashTable.insert(std::make_pair(i, i));
		}
	}

	void test2()
	{
		std::string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		HashTable<std::string, int> ht;
		for (auto& e : arr)
		{
			//auto ret = ht.Find(e);
			node<std::string, int>* ret = ht.find(e);
			if (ret)
			{
				ret->_data.second++;
			}
			else
			{
				ht.insert(make_pair(e, 1));
			}
		}
		std::cout << std::endl;
	}
}
