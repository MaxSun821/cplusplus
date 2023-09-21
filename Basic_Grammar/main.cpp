//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout << "hello world" << endl;
//    return 0;
//}

#include <iostream>
// #define ADD(x,y) ((x)+(y))

inline int Add(int x, int y)
{
    int z = x + y;
    z = x + y;
    z = x + y;
    z = x + y;
    z = x - y;
    z -= x + y;
    z += x + y;
    z = x * y;
    z = x + y;
    z += x + y;
    z = x / y;
    z = x + y;
    z = x - y;
    z = x + y;


    return z;
}


int main()
{
    int c = Add(3, 4);

    std::cout << c << std::endl;

    return 0;
}


