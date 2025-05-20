#include "RBTree.h"

int main() {
	const int N = 100;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	RBTree<int, int> t;
	for (auto e : v)
	{
		t.insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.isBalanced() << endl;
	}
	size_t end2 = clock();

	cout << "Insert:" << end2 - begin2 << endl;

	cout << t.isBalanced() << endl;

	return 0;
}