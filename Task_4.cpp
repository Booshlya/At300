#include "Task_4.h"

int main() {
    // Test the Package class
    Package package("SenderName", "SenderAddress", "SenderCity", "SenderState", "SenderZIP",
                    "RecipientName", "RecipientAddress", "RecipientCity", "RecipientState", "RecipientZIP",
                    10.5, 2.0);

    cout << "Package Cost: $" << package.calculateCost() << endl;

    // Test the TwoDayPackage class
    TwoDayPackage twoDayPackage("SenderName", "SenderAddress", "SenderCity", "SenderState", "SenderZIP",
                                "RecipientName", "RecipientAddress", "RecipientCity", "RecipientState", "RecipientZIP",
                                30.7, 2.1, 5.05);

    cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << std::endl;

    // Test the OvernightPackage class
    OvernightPackage overnightPackage("SenderName", "SenderAddress", "SenderCity", "SenderState", "SenderZIP",
                                      "RecipientName", "RecipientAddress", "RecipientCity", "RecipientState", "RecipientZIP",
                                      40.5, 2.9, 60);

    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}