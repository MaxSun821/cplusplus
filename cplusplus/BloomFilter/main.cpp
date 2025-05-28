#include "bloom_filter.h"

void TestBF2()
{
    srand(time(0));
    const size_t N = 100000;
    BloomFilter<N * 10> bf;

    vector<std::string> v1;
    // string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
    std::string url = "猪八戒";

    for (size_t i = 0; i < N; ++i)
    {
        v1.push_back(url + std::to_string(i));
    }

    for (auto& str : v1)
    {
        bf.set(str);
    }

    // v2跟v1是相似字符串集（前缀一样），但是不一样
    std::vector<std::string> v2;
    for (size_t i = 0; i < N; ++i)
    {
        std::string urlstr = url;
        urlstr += std::to_string(9999999 + i);
        v2.push_back(urlstr);
    }

    size_t n2 = 0;
    for (auto& str : v2)
    {
        if (bf.test(str)) // 误判
        {
            ++n2;
        }
    }
    cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

    // 不相似字符串集
    std::vector<std::string> v3;
    for (size_t i = 0; i < N; ++i)
    {
        //string url = "zhihu.com";
        string url = "孙悟空";
        url += std::to_string(i + rand());
        v3.push_back(url);
    }

    size_t n3 = 0;
    for (auto& str : v3)
    {
        if (bf.test(str))
        {
            ++n3;
        }
    }
    cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main() {
    // BloomFilter<100, string> bf;
    // bf.set("红楼梦");
    // bf.set("水浒传");
    // bf.set("三国演义");
    // bf.set("西游记");
    //
    // cout << bf.test("红楼梦") << endl;
    // cout << bf.test("<UNK>") << endl;
    // cout << bf.test("<西游记>") << endl;
    // cout << bf.test("金瓶梅") << endl;
    // cout << bf.test("三国演义") << endl;

    TestBF2();

    return 0;
}