#include <iostream>
#include <vector>
using namespace std;


class BankAccount {
protected:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) balance -= amount;
        else cout << "Insufficient funds!" << endl;
    }
    virtual void display() {
        cout << "Account: " << accountNumber << " | Balance: " << balance << endl;
    }
    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
    void applyInterest() {
        balance *= 1.02; 
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(int accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) balance -= amount;
        else cout << "Overdraft limit exceeded!" << endl;
    }
};

class BusinessAccount : public BankAccount {
public:
    BusinessAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
    void deposit(double amount) override {
        double tax = amount * 0.05; 
        balance += (amount - tax);
    }
};

class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) {}
    virtual void performTask() = 0;
};

class Teller : public Employee {
public:
    Teller(string n) : Employee(n) {}
    void performTask() override {
        cout << name << " can deposit, withdraw, or freeze accounts." << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n) : Employee(n) {}
    void performTask() override {
        cout << name << " can manage all banking operations." << endl;
    }
};

int main() {
    vector<BankAccount*> accounts;
    accounts.push_back(new SavingsAccount(101, 5000));
    accounts.push_back(new CheckingAccount(102, 3000, 1000));
    accounts.push_back(new BusinessAccount(103, 10000));

    for (auto acc : accounts) {
        acc->display();
    }
    
    vector<Employee*> employees;
    employees.push_back(new Teller("Alice"));
    employees.push_back(new Manager("Bob"));

    for (auto emp : employees) {
        emp->performTask();
    }

  
    for (auto acc : accounts) delete acc;
    for (auto emp : employees) delete emp;
    
    return 0;
}