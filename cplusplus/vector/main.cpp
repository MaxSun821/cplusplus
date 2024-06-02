#include "vector.h"

void test_vector1() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

}


int main() {
//    test_vector1();
//    max::test_vector1();
//    max::test_vector2();
    max::test_vector3();
    return 0;
}
