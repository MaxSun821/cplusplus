#ifndef MY_BITSET_H
#define MY_BITSET_H

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

namespace max {
	template<size_t N>
	class bitset {
	public:
		bitset() {
			bits_.resize((N >> 5) + 1, 0); // Initialize the vector with enough ints to hold N bits, each int can hold 32 bits
		}
		void set(size_t x) {
			size_t i = x / 32; // Assuming 32 bits per int
			size_t j = x % 32; // Position within the int

			bits_[i] |= (1 << j); // Set the j-th bit of the i-th int
		}
		void reset(size_t x) {
			size_t i = x / 32; // Assuming 32 bits per int
			size_t j = x % 32; // Position within the int

			bits_[i] &= ~(1 << j); // Clear the j-th bit of the i-th int
		}
		bool test(size_t x) {
			size_t i = x / 32; // Assuming 32 bits per int
			size_t j = x % 32; // Position within the int

			return bits_[i] & (1 << j); // Check if the j-th bit of the i-th int is set
		}
	private:
		vector<int> bits_;
	};
}

#endif// my_bitset.h - A simple bitset implementation
