class Currency {
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRateToUSD;
    
    public:
        Currency(double amt, string code, string symbol, double rate)
            : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRateToUSD(rate) {}
    
        virtual double convertToBase() {
            return amount * exchangeRateToUSD;
        }
    
        virtual double convertTo(Currency& target) {
            double baseAmount = convertToBase();
            return baseAmount / target.exchangeRateToUSD;
        }
    
        virtual void displayCurrency() {
            cout << currencySymbol << amount << " (" << currencyCode << ")";
        }
    };
    
    class Dollar : public Currency {
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    
        void displayCurrency() override {
            cout << currencySymbol << amount;
        }
    };
    
    class Euro : public Currency {
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 0.92) {}
    
        void displayCurrency() override {
            cout << amount << currencySymbol;
        }
    };
    
    class Rupee : public Currency {
    public:
        Rupee(double amt) : Currency(amt, "INR", "₹", 82.0) {}
    
        void displayCurrency() override {
            cout << currencySymbol << amount;
        }
    };