#include <iostream>
#include "Task_7_new.h"

int main() {
    string inputFilename, outputFilename;
    cout << "Enter the filename of the input image: ";
    cin >> inputFilename;

    // Read the image from disk
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file: " << inputFilename << endl;
        return 1;
    }

    GrayscaleImage<unsigned char> inputImage(0, 0);
    try {
        inputFile >> inputImage;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    inputFile.close();

    // Display information about the input image
    cout << "Information about the input image:" << endl;
    inputImage.displayInfo();

    // Compute the complement of the image
    inputImage.computeComplement();

    // Get the new filename for the output image
    cout << "Enter the filename for the output image: ";
    cin >> outputFilename;

    // Write the computed image to disk
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing: " << outputFilename << endl;
        return 1;
    }

    outputFile << inputImage;
    outputFile.close();

    cout << "Complemented image has been written to: " << outputFilename << endl;

    return 0;
}