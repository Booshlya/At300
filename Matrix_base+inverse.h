#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, vector<T>(cols)) {}

    // Getter functions
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match for addition.");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions do not match for subtraction.");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Scalar multiplication
    Matrix operator*(const T& scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication.");
        }

        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Print matrix
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix inversion
    Matrix inverse() const {
        if (rows != cols) {
            throw invalid_argument("Matrix must be square for inversion.");
        }

        // Augment the matrix with the identity matrix
        Matrix augmented(rows, cols * 2);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                augmented(i, j) = data[i][j];
                augmented(i, j + cols) = (i == j) ? 1 : 0;
            }
        }

        // Gauss-Jordan elimination
        for (size_t i = 0; i < rows; ++i) {
            // Make the diagonal element 1
            T pivot = augmented(i, i);
            if (pivot == 0) {
                throw runtime_error("Matrix is singular, cannot be inverted.");
            }
            for (size_t j = 0; j < cols * 2; ++j) {
                augmented(i, j) /= pivot;
            }

            // Eliminate other rows
            for (size_t k = 0; k < rows; ++k) {
                if (k != i) {
                    T factor = augmented(k, i);
                    for (size_t j = 0; j < cols * 2; ++j) {
                        augmented(k, j) -= factor * augmented(i, j);
                    }
                }
            }
        }

        // Extract the inverted matrix from the augmented matrix
        Matrix inverted(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                inverted(i, j) = augmented(i, j + cols);
            }
        }

        return inverted;
    }

    // Function to access and modify elements
    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data[i][j];
    }
};