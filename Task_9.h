#include <iostream>
#include <string>
#include <set>

using namespace std;

class person {
private:
    string lastName;
    string firstName;
    long phoneNumber;

public:
    person() : lastName("blank"), firstName("blank"), phoneNumber(0L) {}

    person(const string& lana, const string& fina, long pho)
            : lastName(lana), firstName(fina), phoneNumber(pho) {}

    friend bool operator<(const person& p1, const person& p2) {
        return tie(p1.lastName, p1.firstName) < tie(p2.lastName, p2.firstName);
    }

    void display() const {
        cout << lastName << ",\t" << firstName << "\t\tPhone: " << phoneNumber << endl;
    }

    long get_phone() const {
        return phoneNumber;
    }
};

struct comparePersons {
    bool operator()(const person* p1, const person* p2) const {
        return *p1 < *p2;
    }
};