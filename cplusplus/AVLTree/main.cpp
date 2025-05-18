#include "AVLTree.h"

int main() {
    const int N = 30;
    vector<int> v;
    v.reserve(N);
    srand(time(0));

    for (size_t i = 0; i < N; i++)
    {
        v.push_back(rand());
        cout << v.back() << endl;
    }
    AVLTree<int, int> t;
    for (auto e : v) {
        t.insert(make_pair(e, e));
    }
    cout << t.isBalanced() << endl;
    return 0;
}
