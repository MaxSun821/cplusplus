#include "RBTree.h"

int main() {
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.insert(make_pair(e, e));
	}
	t.inorder();

	cout << t.isBalanced() << endl;

	return 0;
}