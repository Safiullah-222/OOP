#include <iostream>
#include <string>
using namespace std;


class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    virtual void showDetails() {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};


class IOrderTaker {
public:
    virtual void takeOrder() = 0;
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
};

class IBiller {
public:
    virtual void generateBill() = 0;
};


class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder() override {
        cout << name << " (Waiter) is taking the order." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
    void prepareOrder() override {
        cout << name << " (Chef) is preparing the order." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
    void generateBill() override {
        cout << name << " (Cashier) is generating the bill." << endl;
    }
};


class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder() override {
        cout << name << " (Manager) is taking the order." << endl;
    }
    void generateBill() override {
        cout << name << " (Manager) is generating the bill." << endl;
    }
};


class Menu {
protected:
    string name;
    double price;
public:
    Menu(string itemName, double itemPrice) : name(itemName), price(itemPrice) {}
    virtual double calculateCost() = 0;
    virtual void displayItem() {
        cout << name << " - $" << price << endl;
    }
};

class FoodMenu : public Menu {
public:
    FoodMenu(string itemName, double itemPrice) : Menu(itemName, itemPrice) {}
    double calculateCost() override {
        return price; 
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string itemName, double itemPrice) : Menu(itemName, itemPrice) {}
    double calculateCost() override {
        return price * 1.1; 
    }
};

int main() {
    
    Waiter w1(101, "Ali");
    Chef c1(102, "Ahmed");
    Cashier cs1(103, "Sara");
    Manager m1(104, "Aisha");

    
    w1.takeOrder();
    c1.prepareOrder();
    cs1.generateBill();
    m1.takeOrder();
    m1.generateBill();

    
    FoodMenu burger("Burger", 5.0);
    BeverageMenu coke("Coke", 2.0);

    
    burger.displayItem();
    cout << "Total Cost: $" << burger.calculateCost() << endl;

    coke.displayItem();
    cout << "Total Cost with tax: $" << coke.calculateCost() << endl;

    return 0;
}
