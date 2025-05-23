#include "myset.h"
#include "mymap.h"

int main() {
    std::string arr[] = {"苹果", "香蕉", "橘子", "葡萄", "苹果", "葡萄", "苹果"};
    max::map<std::string, int> countMap;
    for (auto& e : arr) {
        countMap[e]++;
    }

    for (auto& kv : countMap) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }

    return 0;
}
