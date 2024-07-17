
#include "BinarySearchTree.h"
using namespace std;
int main() {
//    key_value::BSTree<string, string> dict;
//    dict.insert("insert", "插入");
//    dict.insert("erase", "删除");
//    dict.insert("left", "左边");
//    dict.insert("string", "字符串");
//
//    string str;
//    while (cin>>str)
//    {
//        auto ret = dict.find(str);
//        if (ret)
//        {
//            cout << str << ":" << ret->_value << endl;
//        }
//        else
//        {
//            cout << "单词拼写错误" << endl;
//        }
//    }

    string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
    // 统计水果出现的次
    key_value::BSTree<string, int> countTree;
    for (auto str : strs)
    {
        auto ret = countTree.find(str);
        if (ret == nullptr)
        {
            countTree.insert(str, 1);
        }
        else
        {
            ret->_value++;
        }
    }
    countTree.inorder();

    return 0;
}
