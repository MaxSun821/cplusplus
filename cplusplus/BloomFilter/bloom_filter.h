#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using std::bitset;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct BKDRHash {
    size_t operator()(const string &str) {
        size_t hash = 0;
        for (auto ch : str) {
            hash = hash * 131 + ch;
        }
        return hash;
    }
};

struct APHash {
    size_t operator()(const string &str) {
        size_t hash = 0;
        size_t ch;
        for (size_t i = 0; i < str.size(); i++) {
            ch = str[i];
            if ((i & 1) == 0) {
                hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
            } else {
                hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
            }
        }
        return hash;
    }
};

struct DJBHash {
    size_t operator()(const string &str) {
        if (str.empty())
            return 0;
        size_t hash = 5381;
        for (auto ch : str) {
            hash += (hash << 5) + ch;
        }
        return hash;
    }
};


template<size_t N, typename K = string, typename Hash1 = BKDRHash, typename Hash2 = APHash, typename Hash3 = DJBHash>
class BloomFilter {
public:
    void set(const K &key) {
        size_t hash1 = Hash1()(key) % N;
        size_t hash2 = Hash2()(key) % N;
        size_t hash3 = Hash3()(key) % N;

        bits_.set(hash1);
        bits_.set(hash2);
        bits_.set(hash3);
    }

    bool test(const K &key) {
        size_t hash1 = Hash1()(key) % N;
        size_t hash2 = Hash2()(key) % N;
        size_t hash3 = Hash3()(key) % N;

        return bits_.test(hash1) && bits_.test(hash2) && bits_.test(hash3);
    }

private:
    bitset<N> bits_;
};

#endif //BLOOM_FILTER_H
