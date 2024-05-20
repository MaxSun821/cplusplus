#include "Date.h"

int main(void)
{
    Date d(2024, 1, 18);
    Date ret = d - 42;

    int ret2 = ret - d;
    d.print();
    cout << ret2 << endl;
    return 0;
}