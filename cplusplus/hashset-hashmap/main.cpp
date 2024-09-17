
#include "my_unordered_map.h"
#include "my_unordered_set.h"

#include "bitset.h"

int main()
{
	/*max::test_set();
	max::test_map();*/

	max::bitset<100> bs;
	bs.set(5);
	bs.set(7);
	bs.set(15);
	bs.set(66);
	bs.set(13);

	for (size_t i = 0; i < 100; i++)
	{
		std::cout << bs.test(i) << " ";
	}

	std::cout << std::endl;

	return 0;
}
