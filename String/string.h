#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

namespace mystl {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		// 构造函数
		string(const char* str = "")
			: _size(strlen(str))
		{
			_capacity = _size == 0 ? 4 : strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// 拷贝构造
		string(const string& str)
			: _size(str._size)
			, _capacity(str._capacity)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
		}

		// 返回字符指针
		const char* c_str() const{
			return _str;
		}
		//运算符重载
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}

		string& operator=(const string& str) {
			char* tmp = new char[str._capacity + 1]; // 重新开辟一块空间
			strcpy(tmp, str._str);

			delete[] _str; // 若new空间失败，也不影响原字符串
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;

			return *this;
		}

		bool operator<(const string& str) const {
			return strcmp(_str, str._str) < 0;
		}
		bool operator==(const string& str) const {
			return strcmp(_str, str._str) == 0;
		}
		bool operator<=(const string& str) const {
			return *this < str || *this == str;
		}
		bool operator>(const string& str) const {
			return !(*this <= str);
		}
		bool operator>=(const string& str) const {
			return !(*this < str);
		}
		bool operator!=(const string& str) const {
			return !(*this == str);
		}

		void reserve(size_t n) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);

			delete[] _str;
			_str = tmp;

			_capacity = n;
		}

		void push_back(char ch) {
			if (_size + 1 > _capacity) {
				reserve(_capacity * 2);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		// 迭代器
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator begin() const {
			return _str;
		}
		const_iterator end() const {
			return _str + _size;
		}

		size_t size() const {
			return _size;
		}

		// 析构函数
		~string() {
			delete[] _str;
			_size = _capacity = 0;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void testString() {
		string s1;
		string s2("hello world");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s2[0]++;
		cout << s2.c_str() << endl;
	}

	void testString2() {
		string s1("hello world");
		string s2(s1);

		cout << s1.c_str() << endl;
		s2[0]++;
		cout << s2.c_str() << endl;

		string s3;
		string s4 = "";
		s3 = s2;
		cout << s3.c_str() << endl;
		s4 = s3;
		cout << s4.c_str() << endl;
	}

	void testString3() {
		string s1("hello world");
		
		string::iterator it = s1.begin();
		while (it != s1.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : s1) {
			cout << ch << " ";
		}
		cout << endl;
	}

	void testString4() {
		string s1 = "hello";

		s1.append(" world");

		cout << s1.c_str() << endl;

		string s2;

		s2.push_back('n');
		s2.push_back('o');
		cout << s2.c_str() << endl;
	}
}