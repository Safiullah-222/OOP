#include <iostream>
using namespace std;

class Invoice {
private:
    string partNumber, partDescription;
    int quantity;
    double price;
public:
    Invoice(string pNum, string pDesc, int q, double p) : partNumber(pNum), partDescription(pDesc), quantity(q > 0 ? q : 0), price(p > 0 ? p : 0.0) {}
    double getInvoiceAmount() { return quantity * price; }
};
