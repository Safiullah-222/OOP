#include <iostream>
using namespace std;

class Person {
protected:
    int id;
public:
    virtual void getData() {
        cout << "Enter ID: "; cin >> id;
    }
    virtual void displayData() const {
        cout << "ID: " << id << endl;
    }
};

class Admin : public Person {
    string name;
    float income;
public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Income: "; cin >> income;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << "\nIncome: " << income
             << "\nBonus: " << 0.05 * income << endl;
    }
};

class Accounts : public Person {
    string name;
    float income;
public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Income: "; cin >> income;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << "\nIncome: " << income << endl;
        cout  << "Bonus: " << 0.05 * income << endl;
    }
};

int main() {
    Person* p;
    
    Admin admin;
    p = &admin;
    cout << "--- Enter Admin Data ---" << endl;
    p->getData();
    cout << "--- Admin Details ---" << endl;
    p->displayData();

    cout << endl;

    Accounts account;
    p = &account;
    cout << "--- Enter Accounts Data ---" << endl;
    p->getData();
    cout << "--- Accounts Details ---" << endl;
    p->displayData();

    return 0;
}
