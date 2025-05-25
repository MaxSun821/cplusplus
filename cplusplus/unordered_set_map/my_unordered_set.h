#ifndef MY_UNORDERED_SET_H
#define MY_UNORDERED_SET_H

#include "HashTable.h"

namespace max {
	template<typename K, typename Hash = HashFunc<K>>
	class unordered_set {
		struct SetOfKey {
			const K& operator()(const K& key) const {
				return key;
			}
		};
		
	public:
		typedef typename hash_backet::HashTable<K, K, SetOfKey, Hash>::const_iterator iterator;
		typedef typename hash_backet::HashTable<K, K, SetOfKey, Hash>::const_iterator const_iterator;

		pair<iterator, bool> insert(const K& key) {
			auto ret = table_.insert(key);
			return pair<iterator, bool>(iterator(ret.first.node_, ret.first.ht_, ret.first.hashi_), ret.second);
		}
		iterator begin() const {
			return table_.begin();
		}
		iterator end() const {
			return table_.end();
		}
	private:
		hash_backet::HashTable<K, K, SetOfKey, Hash> table_;
	};
}

#endif
