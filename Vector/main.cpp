#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;
//        vv.resize(numRows, vector<int>());
//        // 初始化
//        for(int i = 0; i < vv.size(); ++i) {
//            vv[i].resize(i + 1, 0);
//            vv[i][0] = 1;
//            vv[i][vv[i].size() - 1] = 1;
//        }
//
//        for(int i = 0; i < vv.size(); ++i) {
//            for(int j = 0; j < vv[i].size(); ++j) {
//                if(vv[i][j] == 0) {
//                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//                }
//            }
//        }
//        return vv;
//    }
//};

class Solution {
    string str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void Combinations(const string& digits, size_t di, string strCombi, vector<string>& ret) {
        if(di == digits.size()) {
            ret.push_back(strCombi);
            return;
        }
        int i = digits[di] - '0';
        string s = str[i];

        for(auto ch : s) {
            Combinations(digits, di + 1, strCombi + ch, ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        Combinations(digits, 0, "", ret);
        return ret;
    }
};

int main() {
    //Solution s;
    //vector<vector<int>> vv = s.generate(5);

    // 00000000 00000000 00000000 00000110
    // 10000000 00000000 00000000 00000110
    // 11111111 11111111 11111111 11111001
    // 11111111 11111111 11111111 11111010
    // 00000000 00000000 00000000 00000010

    string s = "23";
    Solution ss;
    ss.letterCombinations(s);


    return 0;
}
