

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int chs[26] = {0}; // 创建一个计数数组
//        for(auto ch : s) {
//            chs[ch - 'a']++;
//        }
//        for(int i = 0; i < s.size(); i++) {
//            if(chs[s[i] - 'a'] == 1) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

//class Solution {
//public:
//    bool isLetter(const char& ch) {
//        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//            return true;
//        }
//        return false;
//    }
//    bool isPalindrome(string s) {
//        if(s == " ") {
//            return true;
//        }
//        int left = 0, right = s.size() - 1;
//        while(left <= right) {
//            while(left <= right && !isLetter(s[left])) {
//                ++left;
//            }
//            while(left <= right && !isLetter(s[right])) {
//                --right;
//            }
//            if(tolower(s[left]) != tolower(s[right])) {
//                return false;
//            }
//            ++left;
//            --right;
//        }
//        return true;
//    }
//};


//

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        int ret1 = 0, ret2 = 0, next = 0;
//        string s;
//        while(end1 >= 0 || end2 >= 0) {
//            if(end1 >= 0) {
//                ret1 = num1[end1--] - '0';
//            } else {
//                ret1 = 0;
//            }
//            if(end2 >= 0) {
//                ret2 = num2[end2--] - '0';
//            } else {
//                ret2 = 0;
//            }
//            int rets = ret1 + ret2 + next;
//            if(rets > 9) {
//                next = 1;
//                rets -= 10;
//            } else {
//                next = 0;
//            }
//            s.insert(s.begin(), rets + '0');
//        }
//        if(next == 1) {
//            s.insert(s.begin(), '1');
//        }
//        return s;
//    }
//};

//class Solution {
//public:
//    string reverseWords(string s) {
//        int begin = 0;
//
//        for(int i = 0; i < s.size(); i++) {
//            if(s[i] == ' ') {
//                int end = i - 1;
//                while(begin < end) {
//                    swap(s[begin], s[end]);
//                    begin++;
//                    end--;
//                }
//                begin = i + 1;
//            }
//        }
//        int end = s.size() - 1;
//        while(begin < end) {
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//        return s;
//    }
//};

//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        int m = 0, n = 0;
//        for(auto ch : num1) {
//            m = m * 10 + (ch - '0');
//        }
//        for(auto ch : num2) {
//            n = n * 10 + (ch - '0');
//        }
//        int ret = m * n;
//        string s;
//
//        if(ret == 0) {
//            s.push_back('0');
//            return s;
//        }
//        while(ret) {
//            s.push_back(ret % 10 + '0');
//            ret /= 10;
//        }
//
//        int begin = 0;
//        int end = s.size() - 1;
//        while(begin < end) {
//            swap(s[begin], s[end]);
//            ++begin;
//            --end;
//        }
//        return s;
//
//    }
//};

//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int n = s.size();
//        for(int i = 0; i < n; i += 2 * k) {
//            reverse(s.begin() + i, s.begin() + min(i + k, n));
//        }
//        return s;
//
//    }
//};

//int main() {
//    string s1 = "abcdefg";
//    string s2 = "456";
//    Solution s;
//    string i = s.reverseStr(s1, 2);
//
//    cout << i << endl;
//
//    return 0;
//}

//int main(int argc, char* argv[])
//
//{
//
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	return 0;
//
//}

//int main()
//
//{
//
//    string str("Hello Bit.");
//
//    str.reserve(111);
//
//    str.resize(5);
//
//    str.reserve(50);
//
//    cout << str.size() << ":" << str.capacity() << endl;
//
//    return 0;
//
//}

//﻿int main()
//{
//
//}

//int main()
//{
//	//string strText = "How are you?";
//
//	//string strSeparator = " ";
//
//	//string strResult;
//
//	//int size_pos = 0;
//
//	//int size_prev_pos = 0;
//
//	//while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//	//{
//
//	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//	//	cout << strResult << " ";
//
//	//	size_prev_pos = ++size_pos;
//
//	//}
//
//	//if (size_prev_pos != strText.size())
//
//	//{
//
//	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//	//	cout << strResult << " ";
//
//	//}
//
//	//cout << endl;
//
//	//return 0;
//
//	string str = "Hello Bit.";
//
//	string::iterator it = str.begin();
//
//	while (it != str.end())
//
//	{
//
//		if (*it != ' ')
//
//			cout << *it;
//
//		else
//
//			str.erase(it);
//
//		it++;
//
//	}
//
//	return 0;
//}

#include "string.h"
int main() {
    
    // mystl::testString2();

    mystl::testString10();
//    string s1 = "hello world";
//    cout << s1 << endl;
//    cout << s1.size() << endl;
//    cout << s1.capacity() << endl;
//
//    s1.resize(5);
//    cout << s1 << endl;
//    cout << s1.size() << endl;
//    cout << s1.capacity() << endl;

    return 0;
}

