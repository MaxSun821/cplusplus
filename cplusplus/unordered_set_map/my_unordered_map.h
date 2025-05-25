#ifndef MY_UNORDERED_MAP_H
#define MY_UNORDERED_MAP_H

#include "HashTable.h"

namespace max {
	template<typename K, typename V, typename Hash = HashFunc<K>>
	class unordered_map {
		struct MapOfKV {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename hash_backet::HashTable<K, pair<const K, V>, MapOfKV, Hash>::iterator iterator;
		typedef typename hash_backet::HashTable<K, const pair<const K, V>, MapOfKV, Hash>::const_iterator const_iterator;

		pair<iterator, bool> insert(const pair<K, V>& kv) {
			return table_.insert(kv);
		}

		V& operator[](const K& key) {
			pair<iterator, bool> result = table_.insert(make_pair(key, V()));
			return result.first->second;
		}
		iterator begin() {
			return table_.begin();
		}
		iterator end() {
			return table_.end();
		}
		const_iterator begin() const {
			return table_.begin();
		}
		const_iterator end() const {
			return table_.end();
		}
	private:
		hash_backet::HashTable<K, pair<const K, V>, MapOfKV, Hash> table_;
	};
}

#endif
