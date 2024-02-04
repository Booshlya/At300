#include "Task1.h"

int main() {
//  Can change 12 to 10 to change radix. I decided not to create a separate one, because this way is much faster
    const RadixArithmetic<12> radix12_1(1, 0, 2);
    const RadixArithmetic<12> radix12_2(3, 5, 8);

    // Create an uninitialized radix-based object
    RadixArithmetic<12> sumRadix12;

    // Display the first radix-based number
    cout << "Radix 12 - Number 1: ";
    radix12_1.display();
    cout << " (Decimal: ";
    radix12_1.display_decimal();
    cout << ")" << endl;

    // Display the second radix-based number
    cout << "Radix 12 - Number 2: ";
    radix12_2.display();
    cout << " (Decimal: ";
    radix12_2.display_decimal();
    cout << ")" << endl;

    // Add the two initialized radix-based numbers using the + operator
    sumRadix12 = radix12_1 + radix12_2;

    // Display the sum of the two radix-based numbers
    cout << "Sum Radix 12: ";
    sumRadix12.display();
    cout << " (Decimal: ";
    sumRadix12.display_decimal();
    cout << ")" << endl;

    return 0;
}
