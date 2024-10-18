#include "share_ptr.h"

int main()
{
	max::share_ptr<int> ptr1(new int);
	max::share_ptr<int> ptr2(ptr1);

	return 0;
}
