#include <iostream>
#include <vector>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
    vector<int> coeffs;

    friend class PolynomialUtils;

public:
    Polynomial() = default;
    Polynomial(const vector<int>& c) : coeffs(c) {}

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    friend ostream& operator<<(ostream& os, const Polynomial& p);
};

Polynomial Polynomial::operator+(const Polynomial& other) const {
    vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
    for (int i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
    for (int i = 0; i < other.coeffs.size(); ++i) result[i] += other.coeffs[i];
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
    for (int i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
    for (int i = 0; i < other.coeffs.size(); ++i) result[i] -= other.coeffs[i];
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
    for (int i = 0; i < coeffs.size(); ++i)
        for (int j = 0; j < other.coeffs.size(); ++j)
            result[i + j] += coeffs[i] * other.coeffs[j];
    return Polynomial(result);
}

ostream& operator<<(ostream& os, const Polynomial& p) {
    bool printed = false;
    for (int i = p.coeffs.size() - 1; i >= 0; --i) {
        if (p.coeffs[i] != 0) {
            if (printed && p.coeffs[i] > 0) os << " + ";
            if (p.coeffs[i] < 0) os << " - ";
            if (abs(p.coeffs[i]) != 1 || i == 0)
                os << abs(p.coeffs[i]);
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i;
            }
            printed = true;
        }
    }
    if (!printed) os << "0";
    return os;
}

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0, power = 1;
    for (int coeff : p.coeffs) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    vector<int> result;
    for (int i = 1; i < p.coeffs.size(); ++i)
        result.push_back(p.coeffs[i] * i);
    return Polynomial(result);
}
int main() {
    Polynomial p1({3, 2, 1});
    Polynomial p2({1, 4});

    
    cout << "P1(x) = " << p1 << endl;
    cout << "P2(x) = " << p2 << endl;

    
    Polynomial sum = p1 + p2;
    cout << "P1 + P2 = " << sum << endl;

    
    Polynomial diff = p1 - p2;
    cout << "P1 - P2 = " << diff << endl;

    
    Polynomial prod = p1 * p2;
    cout << "P1 * P2 = " << prod << endl;

    
    int valueAt2 = PolynomialUtils::evaluate(p1, 2);
    cout << "P1(2) = " << valueAt2 << endl;

    
    Polynomial deriv = PolynomialUtils::derivative(p1);
    cout << "P1'(x) = " << deriv << endl;

    return 0;
}