#include "Task_2.h"
using namespace std;

int main() {
    const int ARRAY_SIZE = 10;

    // fill array arr1 with squares
    Array arr1(ARRAY_SIZE);
    for (int index = 0; index < ARRAY_SIZE; index++)
        arr1[index] = index * index;

    // Display contents of arr1
    cout << "arr1: ";
    for (int index = 0; index < ARRAY_SIZE; index++)
        cout << arr1[index] << ' ';
    cout << endl;

    // Create arr2 using copy constructor
    Array arr2(arr1);

    // Display contents of arr2
    cout << "arr2: ";
    for (int index = 0; index < ARRAY_SIZE; index++)
        cout << arr2[index] << ' ';
    cout << endl;

    // Create arr3 using assignment operator
    Array arr3(ARRAY_SIZE);
    arr3 = arr1;

    // Display contents of arr3
    cout << "arr3: ";
    for (int index = 0; index < ARRAY_SIZE; index++)
        cout << arr3[index] << ' ';
    cout << endl;

    cout << "Moving arr1 to arr2..." << endl;
    arr2 = std::move(arr1);

    // Display contents of arr2 after move
    cout << "arr2 after move: ";
    for (int index = 0; index < ARRAY_SIZE; index++)
        cout << arr2[index] << ' ';
    cout << endl;

    return 0;
}
