#include <iostream>
#include <utility>

class Array {
private:
    int* ptr;
    int size;

public:
    Array(int s) : size(s), ptr(new int[s]) {}

    ~Array() {
        delete[] ptr;
    }

    int& operator[](int j) {
        return *(ptr + j);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] ptr;
            size = other.size;
            ptr = new int[size];
            for (int i = 0; i < size; ++i) {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    Array(const Array& other) : size(other.size), ptr(new int[size]) {
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    }

    // Move constructor
    Array(Array&& other) noexcept : size(0), ptr(nullptr) {
        swap(*this, other);
    }

    // Move assignment operator
    Array& operator=(Array&& other) noexcept {
        swap(*this, other);
        return *this;
    }

    friend void swap(Array& first, Array& second) noexcept {
        using std::swap;
        swap(first.size, second.size);
        swap(first.ptr, second.ptr);
    }
};