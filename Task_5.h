#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Package {
private:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZIP;

    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZIP;

    double weight;
    double costPerOunce;

public:
    Package(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZIP,
            const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZIP,
            double w, double cost)
            : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP),
              recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP),
              weight(max(0.0, w)), costPerOunce(max(0.0, cost)) {}

    virtual void printMailingLabel() const {
        cout << "Sender Address:\n" << senderName << "\n" << senderAddress << "\n"
                  << senderCity << ", " << senderState << " " << senderZIP << "\n\n"
                  << "Recipient Address:\n" << recipientName << "\n" << recipientAddress << "\n"
                  << recipientCity << ", " << recipientState << " " << recipientZIP << "\n\n";
    }

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
};

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZIP,
                  const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZIP,
                  double w, double cost, double fee)
            : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost), flatFee(max(0.0, fee)) {}

    void printMailingLabel() const override {
        Package::printMailingLabel();
        cout << "Shipping Type: Two Day Delivery\n";
    }

    double calculateCost() const override {
        // Calculate cost
        return Package::calculateCost() + flatFee;
    }
};

class OvernightPackage : public Package {
private:
    double overnightFee;

public:
    OvernightPackage(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZIP,
                     const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZIP,
                     double w, double cost, double fee)
            : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost), overnightFee(max(0.0, fee)) {}

    void printMailingLabel() const override {
        Package::printMailingLabel();
        cout << "Shipping Type: Overnight Delivery\n";
    }

    double calculateCost() const override {
        // Calculate cost
        return Package::calculateCost() + overnightFee;
    }
};