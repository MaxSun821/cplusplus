#include "Date.h"

int main(void)
{
    Date d(2024, 5, 26);
    Date d2;
    Date d3 = d++;
    d.print();
    d2.print();
    d3.print();

    Date d4 = --d2;
    d4.print();
    d2.print();

    const Date d5(2023, 7, 26);
    d5.print();
    return 0;
}