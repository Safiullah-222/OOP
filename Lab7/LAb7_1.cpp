class Account {
    protected:
        string accountNumber;
        string accountHolderName;
        double balance;
        string accountType;
    
    public:
        Account(string num, string name, double bal, string type) 
            : accountNumber(num), accountHolderName(name), balance(bal), accountType(type) {}
    
        virtual void deposit(double amount) {
            balance += amount;
        }
    
        virtual bool withdraw(double amount) {
            if (amount > balance) {
                return false;
            }
            balance -= amount;
            return true;
        }
    
        virtual double calculateInterest() {
            return 0.0; // Base account has no interest
        }
    
        virtual void printStatement() {
            cout << "Account Statement for " << accountNumber << endl;
            cout << "Holder: " << accountHolderName << endl;
            cout << "Balance: $" << balance << endl;
        }
    };
    
    class SavingsAccount : public Account {
        double interestRate;
        double minimumBalance;
    
    public:
        SavingsAccount(string num, string name, double bal, double rate, double minBal)
            : Account(num, name, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}
    
        bool withdraw(double amount) override {
            if (balance - amount < minimumBalance) {
                return false;
            }
            return Account::withdraw(amount);
        }
    
        double calculateInterest() override {
            return balance * interestRate / 100;
        }
    };
    
    class FixedDepositAccount : public Account {
        string maturityDate;
        double fixedInterestRate;
    
    public:
        FixedDepositAccount(string num, string name, double bal, string date, double rate)
            : Account(num, name, bal, "Fixed Deposit"), maturityDate(date), fixedInterestRate(rate) {}
    
        bool withdraw(double amount) override {
            // Assuming today's date checking would be implemented
            cout << "Cannot withdraw before " << maturityDate << endl;
            return false;
        }
    
        double calculateInterest() override {
            return balance * fixedInterestRate / 100;
        }
    };