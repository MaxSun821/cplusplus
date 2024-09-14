#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main()
{
	std::unordered_set<int> set;
	set.insert(5);
	set.insert(7);
	set.insert(10);
	set.insert(2);
	set.insert(9);

	std::unordered_set<int>::iterator it = set.begin();
	while (it != set.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	return 0;
}