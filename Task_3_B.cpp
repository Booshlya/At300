#include "Task_3.h"
using namespace std;
int main() {
    const int NUM_PUBLICATIONS = 3;

    // Create an array of pointers to Publication
    Publication* pubarr[NUM_PUBLICATIONS];

    // Loop to assign pointers and get data from the user
    for (int i = 0; i < NUM_PUBLICATIONS; ++i) {
        char type;
        cout << "Enter the type of publication (B for Book, T for Tape): ";
        cin >> type;

        if (type == 'B') {
            pubarr[i] = new Book;
        } else if (type == 'T') {
            pubarr[i] = new Tape;
        } else {
            cerr << "Invalid publication type. Exiting." << endl;
            return 1;
        }

        pubarr[i]->getData();
        cout << endl;
    }

    // Display data for all books and tapes
    for (int j = 0; j < NUM_PUBLICATIONS; ++j) {
        pubarr[j]->putData();
        cout << endl;
    }

    // Cleanup: delete dynamically allocated objects
    for (int k = 0; k < NUM_PUBLICATIONS; ++k) {
        delete pubarr[k];
    }

    return 0;
}