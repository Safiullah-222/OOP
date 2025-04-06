#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
    vector<int> digits;
    bool negative = false;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }

public:

    BigInteger(string s = "0") {
        if (s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        reverse(s.begin(), s.end());
        for (char c : s)
            digits.push_back(c - '0');
        removeLeadingZeros();
    }

    friend ostream& operator<<(ostream& os, const BigInteger& b) {
        if (b.negative) os << '-';
        for (auto it = b.digits.rbegin(); it != b.digits.rend(); ++it)
            os << *it;
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& b) {
        string s;
        is >> s;
        b = BigInteger(s);
        return is;
    }

    friend BigInteger operator+(const BigInteger& a, const BigInteger& b) {
        if (a.negative || b.negative)
            throw runtime_error("Only positive addition is supported.");

        BigInteger res;
        res.digits.clear();
        int carry = 0, sum;
        int n = max(a.digits.size(), b.digits.size());
        for (int i = 0; i < n || carry; ++i) {
            sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            res.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return res;
    }
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b) {
        if (a.negative || b.negative)
            throw runtime_error("Only positive subtraction is supported.");

        if (a < b)
            throw runtime_error("Negative result not supported.");

        BigInteger res;
        res.digits.clear();
        int borrow = 0;
        for (int i = 0; i < a.digits.size(); ++i) {
            int sub = a.digits[i] - borrow;
            if (i < b.digits.size()) sub -= b.digits[i];
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.digits.push_back(sub);
        }
        res.removeLeadingZeros();
        return res;
    }

    
    friend bool operator<(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false; 
    }
    friend bool operator==(const BigInteger& a, const BigInteger& b) {
        return a.digits == b.digits && a.negative == b.negative;
    }
};


    int main() {
        BigInteger num1("123456789012345678901234567890");
        BigInteger num2("987654321098765432109876543210");
    
        cout << "Num1: " << num1 << endl;
        cout << "Num2: " << num2 << endl;
    
        BigInteger sum = num1 + num2;
        cout << "Sum: " << sum << endl;
    
        BigInteger diff = num2 - num1;
        cout << "Difference: " << diff << endl;
    
        cout << "Num1 < Num2? " << (num1 < num2 ? "Yes" : "No") << endl;
        cout << "Num1 == Num2? " << (num1 == num2 ? "Yes" : "No") << endl;
    
        return 0;
    }
    
