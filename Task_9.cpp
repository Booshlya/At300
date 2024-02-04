#include "Task_9.h"

int main() {
    multiset<person*, comparePersons> personSet;

    // Define persons
    person persons[] = {
            {"Smith", "John", 123456789},
            {"Doe", "Jane", 987654321},
            {"Smith", "Alice", 1312},
            {"Doe", "John", 228},
            {"Johnson", "Bob", 1337},
            {"Smith", "Alice", 036560304}
    };


    for (const auto& p : persons) {
        personSet.insert(new person(p));
    }

    // Display
    cout << "Contents of the multiset:\n";
    for (const auto& p : personSet) {
        p->display();
    }

    // Cleanup
    for (auto* p : personSet) {
        delete p;
    }

    return 0;
}