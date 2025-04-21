#include <iostream>
using namespace std;

class Person {
public:
    virtual void getdata() = 0;
    virtual void displaydata() = 0;
    virtual void bonus() = 0;
};

class Admin : virtual public Person {
protected:
    string name;
    float salary;

public:
    void getdata() {
        name = "Admin";
        salary = 5000;
    }

    void displaydata() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    void bonus() {
        cout << "Bonus: " << salary * 0.1 << endl;
    }
};

class Account : virtual public Person {
protected:
    string name;
    float salary;

public:
    void getdata() {
        name = "Account";
        salary = 6000;
    }

    void displaydata() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    void bonus() {
        cout << "Bonus: " << salary * 0.15 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() {
        Admin::getdata();
    }

    void displaydata() {
        Admin::displaydata();
    }

    void bonus() {
        Admin::bonus();
    }
};

int main() {
    Person *p;
    Master m;
    p = &m;

    p->getdata();
    p->displaydata();
    p->bonus();

    return 0;
}
