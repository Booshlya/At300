#include "Task_3.h"
using namespace std;

int main() {
    const int NUM_PUBLICATIONS = 2;

    // Create an array of Publication pointers
    Publication* publications[NUM_PUBLICATIONS];

    // Create instances of Book and Tape
    Book book;
    Tape tape;

    // Set pointers to the instances
    publications[0] = &book;
    publications[1] = &tape;

    // Get data for each publication
    for (int i = 0; i < NUM_PUBLICATIONS; ++i) {
        cout << "Enter data for publication #" << i + 1 << ":" << endl;
        publications[i]->getData();
        cout << endl;
    }

    // Display data
    for (int i = 0; i < NUM_PUBLICATIONS; ++i) {
        cout << "Details for publication #" << i + 1 << ":" << endl;
        publications[i]->putData();
        cout << endl;
    }

    return 0;
}