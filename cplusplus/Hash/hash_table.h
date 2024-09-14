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

	template<class K, class V>
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
            // 扩容，设置负载因子为0.75
            if((double)_n / _v.size() >= 0.75)
            {
                size_t newCapacity = _v.size() * 2;
                HashTable<K, V> newHT;
                newHT._v.resize(newCapacity);

                for(int i = 0; i < _v.size(); i++)
                {
                    if(_v[i]._s == EXIST)
                    {
                        newHT.insert(_v[i]._data);
                    }
                }
                _v.swap(newHT._v);
            }

            // 计算哈希值
            size_t hashi = data.first % _v.size();
            while(_v[hashi]._s == EXIST)
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
	private:
        std::vector<HashData<K, V>> _v;
        size_t _n; // 记录哈希表中有几个元素
	};
}
