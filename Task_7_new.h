#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class GrayscaleImage {
private:
    size_t width;
    size_t height;
    vector<vector<T>> pixels;

public:
    GrayscaleImage(size_t w, size_t h) : width(w), height(h), pixels(h, vector<T>(w)) {}

    // Function to compute the complement of the image
    void computeComplement() {
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                pixels[i][j] = numeric_limits<T>::max() - pixels[i][j];
            }
        }
    }

    // Overload stream operations for reading and writing
    friend istream& operator>>(istream& is, GrayscaleImage& image) {
        string magic;
        is >> magic;
        if (magic != "P2") {
            throw invalid_argument("Invalid magic number. Expected P2.");
        }

        is >> image.width >> image.height;
        image.pixels.resize(image.height, vector<T>(image.width));

        int maxPixelValue;
        is >> maxPixelValue;
        if (maxPixelValue != 255) {
            throw invalid_argument("Invalid max pixel value. Expected 255.");
        }

        for (size_t i = 0; i < image.height; ++i) {
            for (size_t j = 0; j < image.width; ++j) {
                int pixelValue;
                is >> pixelValue;
                if (pixelValue < 0 || pixelValue > 255) {
                    throw out_of_range("Pixel value out of range (0-255).");
                }
                image.pixels[i][j] = static_cast<T>(pixelValue);
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const GrayscaleImage& image) {
        os << "P2\n" << image.width << " " << image.height << "\n255\n";
        for (size_t i = 0; i < image.height; ++i) {
            for (size_t j = 0; j < image.width; ++j) {
                os << static_cast<int>(image.pixels[i][j]) << " ";
            }
            os << "\n";
        }
        return os;
    }

    // Function to display information about the image
    void displayInfo() const {
        cout << "P2\n" << width << " " << height << "\n255\n";
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                cout << static_cast<int>(pixels[i][j]) << " ";
            }
            cout << "\n";
        }
    }
};