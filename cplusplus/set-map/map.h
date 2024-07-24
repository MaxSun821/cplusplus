#pragma once

#include "RBTree.h"

namespace max {
	template<class K, class V>
	class map {
		typedef std::pair<const K, V> value_type;
	public:
		struct KVOfType {
			const K& operator()(const value_type& data) {
				return data.first;
			}
		};

		typedef typename RBTree<K, value_type, KVOfType>::iterator iterator;
		typedef typename RBTree<K, value_type, KVOfType>::const_iterator const_iterator;


		iterator begin() {
			return _t.begin();
		}

		iterator end() {
			return _t.end();
		}

		const_iterator begin() const {
			return _t.begin();
		}

		const_iterator end() const {
			return _t.end();
		}

		V& operator[](const K& key) {
			std::pair<iterator, bool> ret = _t.insert(std::make_pair(key, V()));
			return ret.first->second;
		}

		std::pair<iterator, bool> insert(const value_type& data) {
			return _t.insert(data);
		}

		
	private:
		RBTree<K, value_type, KVOfType> _t;
	};
}