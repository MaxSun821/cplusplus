#include "Date.h"


void TestDate() {
    Date d1(2023, 10, 17);
    d1.Print();

    Date d2(2024, 7, 21);
    d2.Print();

    Date d3 = d1 - 100;
    d3.Print();

}

int main() {
    TestDate();
    return 0;
}