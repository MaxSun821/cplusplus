#include <iostream>
#include <string>


void test_string1() {
	std::string s1;
	std::string s2 = "hello world";
	std::string s3("abcdefg");

	std::cin >> s1;
	std::cout << s1 << std::endl;

	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
}

void test_string2() {
	std::string s1 = "hello world";
	for (size_t i = 0; i < s1.size(); i++) {
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;

	std::string s2 = "welcome to my zone";
	std::string::iterator it = s2.begin();
	while (it != s2.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::string s3 = "Are you Ok??";
	for (auto ch : s3) {
		std::cout << ch << " ";
	}
	std::cout << std::endl;

}

int main() {
	//test_string1();
	test_string2();
	return 0;
}