#pragma once

#include <iostream>
#include <vector>
#include <string>


namespace hash_backet
{
	template<class T>
	struct node
	{
		node(const T& data)
			: _next(nullptr), _data(data)
		{
		}
		node* _next; // 指向下一个节点
		T _data;
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

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct __ht_iterator
	{
		typedef node<T> node;
		typedef __ht_iterator<K, T, Ref, Ptr, KeyOfT, Hash> self;
		node* _node;
		const HashTable<K, T, KeyOfT, Hash>* _ht;
		size_t _hashi;

		__ht_iterator(node* node, HashTable<K, T, KeyOfT, Hash>* ht, size_t hashi)
			: _node(node), _ht(ht), _hashi(hashi)
		{
		}

		__ht_iterator(node* node, const HashTable<K, T, KeyOfT, Hash>* ht, size_t hashi)
			: _node(node), _ht(ht), _hashi(hashi)
		{
		}

		self& operator++()
		{
			if (_node->_next)
			{
				// 当前哈希桶中还有结点
				_node = _node->_next;
			}
			else
			{
				// 当前哈希桶中没有结点，需要走到下一个有数据的哈希桶
				++_hashi;
				while (_hashi < _ht->_table.size())
				{
					if (_ht->_table[_hashi])
					{
						_node = _ht->_table[_hashi];
						break;
					}
					++_hashi;
				}
				if (_hashi == _ht->_table.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef node<T> node;

		template<class k, class v, class Ref, class Ptr, class kt, class hs>
		friend struct __ht_iterator;

	 public:
		typedef __ht_iterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef __ht_iterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;

		iterator begin()
		{
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i])
				{
					return iterator(_table[i], this, i);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}

		const_iterator begin() const
		{
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i])
				{
					return const_iterator(_table[i], this, i);
				}
			}
			return end();
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this, -1);
		}

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
		std::pair<iterator, bool> insert(const T& data)
		{
			KeyOfT keyOfT;
			iterator it = find(keyOfT(data));
			if (it != end())
			{
				return std::make_pair(it, false);
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

						size_t hashi = hash(keyOfT(cur->_data)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = curNext;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}
			size_t hashi = hash(keyOfT(data)) % _table.size();
			// 创建新节点
			node* newNode = new node(data);
			// 采用头插法
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;

			++_n;
			return std::make_pair(iterator(newNode, this, hashi), true);

		}

		iterator find(const K& key)
		{
			KeyOfT keyOfT;
			Hash hash;
			size_t hashi = hash(key) % _table.size();
			node* cur = _table[hashi];

			while (cur)
			{
				if (keyOfT(cur->_data) == key)
				{
					return iterator(cur, this, hashi);
				}
				cur = cur->_next;
			}
			return end();
		}

		bool erase(const K& key)
		{
			KeyOfT keyOfT;
			Hash hash;
			size_t hashi = hash(key) % _table.size();
			node* prev = nullptr;
			node* cur = _table[hashi];

			while (cur)
			{
				node* curNext = cur->next;
				if (keyOfT(cur->_data) == key)
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
}

