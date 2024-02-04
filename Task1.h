#ifndef UNTITLED_TASK1_H
#define UNTITLED_TASK1_H

#include <iostream>
using namespace std;
class Duodecimal {
private:
    int digit1;
    int digit2;
    int digit3;

public:
    // Constructors
    Duodecimal() : digit1(0), digit2(0), digit3(0) {}

    Duodecimal(int d1, int d2, int d3) : digit1(d1), digit2(d2), digit3(d3) {}

    // Display the duodecimal number
    void display() const {
        cout << digit1 << 'X' << digit2 << digit3;
    }

    // Basic addition
    Duodecimal add_duodecimal(const Duodecimal& other) const {
        Duodecimal result;
        result.digit3 = (digit3 + other.digit3) % 12;
        int carry = (digit3 + other.digit3) / 12;
        result.digit2 = (digit2 + other.digit2 + carry) % 12;
        carry = (digit2 + other.digit2 + carry) / 12;
        result.digit1 = digit1 + other.digit1 + carry;
        return result;
    }
    // Overloaded + operator
    Duodecimal operator+(const Duodecimal& other) const {
        Duodecimal result;
        result.digit3 = (digit3 + other.digit3) % 12;
        int carry = (digit3 + other.digit3) / 12;
        result.digit2 = (digit2 + other.digit2 + carry) % 12;
        carry = (digit2 + other.digit2 + carry) / 12;
        result.digit1 = digit1 + other.digit1 + carry;
        return result;
    }

    // Convert duodecimal to decimal
    int to_decimal() const {
        return digit1 * 144 + digit2 * 12 + digit3;
    }

    // Display decimal representation
    void display_decimal() const {
        cout << to_decimal();
    }



};
// Template class for radix-based arithmetic
template <int Radix>
class RadixArithmetic {
private:
    int digit1;
    int digit2;
    int digit3;

public:
    // Constructors
    RadixArithmetic() : digit1(0), digit2(0), digit3(0) {}

    RadixArithmetic(int d1, int d2, int d3) : digit1(d1), digit2(d2), digit3(d3) {}

    // Display the number
    void display() const {
        cout << digit1 << 'X' << digit2 << digit3;
    }

    // Convert to decimal
    int to_decimal() const {
        return digit1 * Radix * Radix + digit2 * Radix + digit3;
    }

    // Display decimal representation
    void display_decimal() const {
        cout << to_decimal();
    }

    // Add two radix-based numbers
    RadixArithmetic<Radix> add(const RadixArithmetic<Radix>& other) const {
        RadixArithmetic<Radix> result;
        result.digit3 = (digit3 + other.digit3) % Radix;
        int carry = (digit3 + other.digit3) / Radix;
        result.digit2 = (digit2 + other.digit2 + carry) % Radix;
        carry = (digit2 + other.digit2 + carry) / Radix;
        result.digit1 = digit1 + other.digit1 + carry;
        return result;
    }

    // Overloaded + operator
    RadixArithmetic<Radix> operator+(const RadixArithmetic<Radix>& other) const {
        return add(other);
    }
};

#endif //UNTITLED_TASK1_H
