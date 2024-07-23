#include "RBTree.h"
#include <vector>

//int main()
//{
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	RBTree<int, int> tree;
//	for (int e : a) {
//		tree.insert(std::make_pair(e, e));
//	}
//	tree.inorder();
//
//	std::cout << tree.isBalance() << std::endl;
//	return 0;
//}

int main()
{
	const int N = 1000000;
	std::vector<int> v;
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
		t.insert(std::make_pair(e, e));
		//std::cout << "Insert:" << e << "->" << t.isBalance() << std::endl;
	}
	size_t end2 = clock();

	std::cout << "Insert:" << end2 - begin2 << std::endl;


	//std::cout << t.isBalance() << std::endl;
	std::cout << t.getHeight() << std::endl;
	std::cout << t.size() << std::endl;

	size_t begin1 = clock();
	for (auto e : v)
	{
		t.find(e);
	}


	for (size_t i = 0; i < N; i++)
	{
		t.find((rand() + i));
	}

	size_t end1 = clock();

	std::cout << "Find:" << end1 - begin1 << std::endl;

	return 0;
}