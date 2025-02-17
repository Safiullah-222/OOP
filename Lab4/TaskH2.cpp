#include <iostream>
using namespace std;

class Account {
private:
    double balance;
public:
    Account(double b) : balance(b) {}
    void credit(double amount) { balance += amount; }
    void debit(double amount) { if (amount <= balance) balance -= amount; }
    double getBalance() { return balance; }
};
