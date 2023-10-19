//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout << "hello world" << endl;
//    return 0;
//}

//#include <iostream>
//
//int main()
//{
//    std::cout << "输入两个整数：";
//    int num1, num2 = 0;
//
//    std::cin >> num1 >> num2;
//
//    std::cout << num1 << "+" << num2 << "=" << num1 + num2 << std::endl;
//
//    return 0;
//}

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World" << std::endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cout << "Hello World" << endl;
//    return 0;
//}


//#include <iostream>
//using namespace std;
//void PrintNum(int n = 4)
//{
//    cout << n << endl;
//}
//
//int main()
//{
//    PrintNum();
//    cout << endl;
//    PrintNum(12);
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int Add(int x, int y)
//{
//    return x + y;
//}
//
//double Add(double x, double y)
//{
//    return x + y;
//}
//
//int Add(int x, int y, int z)
//{
//    return x + y + z;
//}
//
//double Add(int x, double y)
//{
//    return x + y;
//}
//double Add(double y, int x)
//{
//    return x + y;
//}
//
//int main()
//{
//    Add(1, 2);
//    Add(1.0, 2.0);
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Swap(int& ra, int& rb)
//{
//    int tmp = ra;
//    ra = rb;
//    rb = tmp;
//}
//int main()
//{
//    int a = 10;
//    int b = 5;
//
//    cout << "before: a=" << a << ",b=" << b << endl;
//
//    Swap(a, b);
//
//    cout << "after: a=" << a << ",b=" << b << endl;
//
//    return 0;
//}

//#include <iostream>
//#define ADD(x, y) ((x) + (y))
//
//int main(){
//    int a = 1;
//    int b = 2;
//    int c = ADD(a, b);
//    std::cout << c << std::endl;
//    return 0;
//}

#include <iostream>

inline int Add(int a, int b) {
    int c = a + b;
    return c;
}
int main() {
    int c = Add(1, 2);
    std::cout << c << std::endl;

    return 0;
}

