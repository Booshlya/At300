#include <iostream>
#include <string>

using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Ignore any newline left in the buffer
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() override {
        Publication::getData(); // Call base class's getData

        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putData() const override {
        Publication::putData(); // Call base class's putData
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void getData() override {
        Publication::getData(); // Call base class's getData

        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putData() const override {
        Publication::putData(); // Call base class's putData
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};