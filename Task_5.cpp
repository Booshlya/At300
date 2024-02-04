#include "Task_5.h"

int main() {
    // Create a vector of Package pointers
    vector<Package*> packages;

    packages.push_back(new TwoDayPackage("Sender1", "SenderAddress1", "City1", "State1", "ZIP1",
                                         "Recipient1", "RecipientAddress1", "City1", "State1", "ZIP1",
                                         10.5, 2.0, 5.0));

    packages.push_back(new OvernightPackage("Sender2", "SenderAddress2", "City2", "State2", "ZIP2",
                                            "Recipient2", "RecipientAddress2", "City2", "State2", "ZIP2",
                                            30.7, 2.1, 5.05));

    packages.push_back(new TwoDayPackage("Sender3", "SenderAddress3", "City3", "State3", "ZIP3",
                                         "Recipient3", "RecipientAddress3", "City3", "State3", "ZIP3",
                                         40.5, 2.9, 60));


    double totalShippingCost = 0.0;

    for (const Package* package : packages) {
        package->printMailingLabel();
        double cost = package->calculateCost();
        cout << "Shipping Cost: $" << fixed << setprecision(2) << cost << "\n\n";
        totalShippingCost += cost;
    }

    cout << "Total Shipping Cost for all Packages: $" << fixed << setprecision(2) << totalShippingCost << endl;

//    cleaning memory
    for (Package* package : packages) {
        delete package;
    }

    return 0;
}