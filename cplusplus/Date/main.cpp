#include "Date.h"

int main(void)
{
    Date d(2024, 1, 18);
    Date d2 = d;
    Date ret = d - 42;

    d2.print();
    d.print();

    int ret2 = ret - d;
    d.print();
    cout << ret2 << endl;
    return 0;
}