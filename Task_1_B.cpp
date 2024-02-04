#include "Task1.h"

int main() {
    // initialized duodecimal objects
    const Duodecimal duodecimalB1(1, 0, 2);
    const Duodecimal duodecimalB2(3, 5, 8);

    // Create an uninitialized duodecimal object
    Duodecimal sumB;

    // Display the first duodecimal number
    cout << "Duodecimal B1: ";
    duodecimalB1.display();
    cout << " (Decimal: ";
    duodecimalB1.display_decimal();
    cout << ")" << endl;

    // Display the second duodecimal number
    cout << "Duodecimal B2: ";
    duodecimalB2.display();
    cout << " (Decimal: ";
    duodecimalB2.display_decimal();
    cout << ")" << endl;

    // Add the two initialized duodecimal numbers using the + operator
    sumB = duodecimalB1 + duodecimalB2;


    cout << "Sum B: ";
    sumB.display();
    cout << " (Decimal: ";
    sumB.display_decimal();
    cout << ")" << endl;

    return 0;
}
