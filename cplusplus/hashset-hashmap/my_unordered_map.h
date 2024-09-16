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
		bool insert(const std::pair<K, V>& kv)
		{
			return _table.insert(kv);
		}
	 private:
		hash_backet::HashTable<K, std::pair<K, V>, MapOfKV, Hash> _table;
	};
}
