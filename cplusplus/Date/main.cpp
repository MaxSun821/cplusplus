#include "Date.h"

int main(void) {
    Date d(2024, 5, 26);
    Date d2;
    Date d3 = d++;
    cout << d << endl;
    cout << d2 << endl;
    cout << d3 << endl;


    Date d4 = --d2;
    cout << d4 << endl;
    cout << d2 << endl;

    const Date d5(2023, 7, 26);
    cout << d5 << endl;

    Date d6;
    cin >> d6;
    cout << d6 << endl;
    return 0;
}