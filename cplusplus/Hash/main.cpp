#include "HashTable.h"

int main() {
    string arr[] = {"苹果", "香蕉", "橘子", "葡萄", "苹果", "葡萄", "苹果"};
    hash_backet::HashTable<string, int> ht;
    for (string s: arr) {
        hash_backet::HashNode<string, int> *ret = ht.find(s);
        if (ret == nullptr) {
            ht.insert(make_pair(s, 1));
        } else {
            ret->kv_.second++;
        }
    }
    cout << "complete" << endl;
    return 0;
}
