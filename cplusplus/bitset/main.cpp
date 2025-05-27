#include "my_bitset.h"

int main() {
	max::bitset<64> b1; // Create a bitset of size 64
	b1.set(3); // Set the 4th bit (index 3)
	b1.set(5); // Set the 6th bit (index 5)
	b1.set(10); // Set the 11th bit (index 10)
	b1.set(63); // Set the 64th bit (index 63)

	cout << b1.test(3) << endl; // Should print 1 (true)
	cout << b1.test(4) << endl; // Should print 0 (false)
	cout << b1.test(5) << endl; // Should print 1 (true)
	cout << b1.test(10) << endl; // Should print 1 (true)
	cout << b1.test(63) << endl; // Should print 1 (true)
	return 0;
}