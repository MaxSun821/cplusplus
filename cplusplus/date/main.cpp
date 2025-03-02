#include "Date.h"

int main() {
    Date d1(2023, 12, 31);
    Date d2(2023, 12, 1);
    cout << (d1 - d2) << endl;
    return 0;
}