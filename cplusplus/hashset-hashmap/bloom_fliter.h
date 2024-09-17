#pragma once

#include <bitset>
#include <string>


struct BKDRHash
{
	size_t operator()(const std::string& key)
	{
		// BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const std::string& key)
	{
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			char ch = key[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const std::string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};
template<size_t N, class K = std::string, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
class bloom_fliter
{
public:
	void set(const K& key)
	{
		size_t hash1 = Hash1()(key);
		size_t hash2 = Hash2()(key);
		size_t hash3 = Hash3()(key);

		_bits.set(hash1);
		_bits.set(hash2);
		_bits.set(hash3);
	}

	bool test(const K& key)
	{
		size_t hash1 = Hash1()(key);
		size_t hash2 = Hash2()(key);
		size_t hash3 = Hash3()(key);

		if (_bits.test(hash1) == false)
			return false;
		if (_bits.test(hash2) == false)
			return false;
		if (_bits.test(hash3) == false)
			return false;
	}
private:
	std::bitset<N> _bits;
};