#pragma once

#include "hash_backet.h"

namespace max
{

	template<class K, class Hash = hash_backet::HashFunc<K>>
	class unordered_set
	{
		struct SetOfKey
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	 public:
		typedef typename hash_backet::HashTable<K, K, SetOfKey, Hash>::const_iterator iterator;
		typedef typename hash_backet::HashTable<K, K, SetOfKey, Hash>::const_iterator const_iterator;

		const_iterator begin() const
		{
			return _table.begin();
		}

		const_iterator end() const
		{
			return _table.end();
		}

		std::pair<const_iterator, bool> insert(const K& key)
		{
			auto ret = _table.insert(key);
			return std::pair<const_iterator, bool>(const_iterator(ret.first._node, ret.first._ht, ret.first._hashi),
				ret.second);
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
		hash_backet::HashTable<K, K, SetOfKey, Hash> _table;
	};

	void test_set()
	{
		unordered_set<int> s;
		s.insert(5);
		s.insert(15);
		s.insert(52);
		s.insert(3);

		unordered_set<int>::iterator it = s.begin();
		while(it != s.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

	}
}

