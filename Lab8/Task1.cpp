#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    int numerator, denominator;

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        reduce();
    }

    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }

    friend bool operator==(const Fraction& a, const Fraction& b) {
        return a.numerator == b.numerator && a.denominator == b.denominator;
    }

    friend bool operator!=(const Fraction& a, const Fraction& b) { return !(a == b); }
    friend bool operator<(const Fraction& a, const Fraction& b) {
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }
    friend bool operator>(const Fraction& a, const Fraction& b) { return b < a; }
    friend bool operator<=(const Fraction& a, const Fraction& b) { return !(a > b); }
    friend bool operator>=(const Fraction& a, const Fraction& b) { return !(a < b); }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.numerator >> f.denominator;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl;  
    return 0;
}