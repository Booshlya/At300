// Task 1 A
#include "Task1.h"

int main() {

    const Duodecimal duodecimal1(1, 0, 2);
    const Duodecimal duodecimal2(3, 5, 8);
    Duodecimal duodecimal3;

    cout << "Duodecimal 1: ";
    duodecimal1.display();
    cout << " (Decimal: ";
    duodecimal1.display_decimal();
    cout << ")" << endl;

    cout << "Duodecimal 2: ";
    duodecimal2.display();
    cout << " (Decimal: ";
    duodecimal2.display_decimal();
    cout << ")" << endl;

    duodecimal3 = duodecimal1.add_duodecimal(duodecimal2);

    cout << "Sum: ";
    duodecimal3.display();
    cout << " (Decimal: ";
    duodecimal3.display_decimal();
    cout << ")" << endl;

    return 0;
}
