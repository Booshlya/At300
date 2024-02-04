#include <iostream>
#include <string>
#include "Matrix_base+inverse+output+input.h"
using namespace std;



int main() {
    // size of the first matrix
    // I had to do this because program wasn't able to read directly from my machine, also I wanted to test different
    // matrices, so I think this is also a correct way to do it
    size_t rows1, cols1;
    cout << "Enter the size of the first matrix : ";
    cin >> rows1 >> cols1;

    // input the values of the first matrix
    Matrix<double> matrix1(rows1, cols1);
    cout << "Enter the values of the first matrix:" << endl;
    cin >> matrix1;

    // size of the second matrix
    size_t rows2, cols2;
    cout << "Enter the size of the second matrix : ";
    cin >> rows2 >> cols2;

    // input the values of the second matrix
    Matrix<double> matrix2(rows2, cols2);
    cout << "Enter the values of the second matrix:" << endl;
    cin >> matrix2;

    // Inverse of the first matrix
    Matrix<double> invertedMatrix1;
    try {
        invertedMatrix1 = matrix1.inverse();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    // Inverse of the second matrix
    Matrix<double> invertedMatrix2;
    try {
        invertedMatrix2 = matrix2.inverse();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    Matrix<double> identityMatrix1 = matrix1 * invertedMatrix1;
    Matrix<double> identityMatrix2 = matrix2 * invertedMatrix2;


    // Set a threshold for considering a value close to zero
    double threshold = 1e-15;

    // Iterate through the elements of the identity matrices and replace small values with zero
    //I had to do this because of the double format, so sometimes after multiplication the element was displayed
    // as a really close to zero, but not 0 exactly, even though in basic fractions multiplication the element = 0
    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols1; ++j) {
            if (fabs(identityMatrix1(i, j)) < threshold) {
                identityMatrix1(i, j) = 0.0;
            }
        }
    }

    for (size_t i = 0; i < rows2; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            if (fabs(identityMatrix2(i, j)) < threshold) {
                identityMatrix2(i, j) = 0.0;
            }
        }
    }





    cout << "First Original:" << endl << matrix1 << endl;
    cout << "First invertedMatrix1:" << endl << invertedMatrix1 << endl;

    cout << "Identity Matrix (First Original * First Inverted):" << endl << identityMatrix1 << endl;

    cout << "Second Original:" << endl << matrix2 << endl;
    cout << "Second invertedMatrix1:" << endl << invertedMatrix2 << endl;
    cout << "Identity Matrix (Second Original * Second Inverted):" << endl << identityMatrix2 << endl;

    return 0;
}