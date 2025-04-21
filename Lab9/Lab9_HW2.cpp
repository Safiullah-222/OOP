#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    virtual void setPrice(float p) = 0;
    virtual float getPrice() = 0;
};

class Color : public Car {
public:
    void setPrice(float p) {
        price = p + 500;
    }

    float getPrice() {
        return price;
    }
};

class Company : public Car {
public:
    void setPrice(float p) {
        price = p + 1000;
    }

    float getPrice() {
        return price;
    }
};

int main() {
    Color c;
    c.setModel("Civic");
    c.setPrice(30000);
    cout << "Model: " << c.getModel() << ", Price with color: " << c.getPrice() << endl;

    Company comp;
    comp.setModel("Corolla");
    comp.setPrice(32000);
    cout << "Model: " << comp.getModel() << ", Price with company: " << comp.getPrice() << endl;

    return 0;
}
