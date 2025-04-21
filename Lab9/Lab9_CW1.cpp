#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet() {
        balance = 0;
        dailyDepositLimit = 10000;
        dailyWithdrawLimit = 5000;
        depositedToday = 0;
        withdrawnToday = 0;
    }

    bool deposit(double amount) {
        if (amount > 0 && (depositedToday + amount) <= dailyDepositLimit) {
            balance += amount;
            depositedToday += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance && (withdrawnToday + amount) <= dailyWithdrawLimit) {
            balance -= amount;
            withdrawnToday += amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) {
        userID = id;
        name = n;
    }

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void checkBalance() {
        cout << "User: " << name << ", Balance: " << wallet.getBalance() << endl;
    }
};

int main() {
    User user1("U001", "Ali");
    User user2("U002", "Sara");

    user1.deposit(3000);
    user1.withdraw(1500);
    user1.checkBalance();

    user2.deposit(12000);
    user2.deposit(8000);
    user2.withdraw(6000);
    user2.withdraw(4000);
    user2.checkBalance();

    return 0;
}
