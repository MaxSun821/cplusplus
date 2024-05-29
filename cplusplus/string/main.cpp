#include "string.h"


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

void test_string3() {
    std::string s1 = "https://cplusplus.com/reference/string/string/?kw=string";
    size_t i1 = s1.find(':');
    std::string sub1, sub2, sub3;
    sub1 = s1.substr(0, i1);
    size_t i2 = s1.find('/', i1 + 3);
    sub2 = s1.substr(i1 + 3, i2);
    sub3 = s1.substr(i2 + 1);
    std::cout << sub1 << std::endl;
    std::cout << sub2 << std::endl;
    std::cout << sub3 << std::endl;
}

int main() {
	//test_string1();
//	test_string2();
//    test_string3();
    max::test_string1();
	return 0;
}