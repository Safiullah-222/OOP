#include <iostream>
#include <cmath>
#include <utility>

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() : degree(0) { coefficients = new double[1]{0}; }
    Polynomial(int deg, const double coeffs[]) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) coefficients[i] = coeffs[i];
    }
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) coefficients[i] = other.coefficients[i];
    }
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr; other.degree = 0;
    }
    ~Polynomial() { delete[] coefficients; }

    int getDegree() const { return degree; }
    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; i++) result += coefficients[i] * pow(x, i);
        return result;
    }
    Polynomial add(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{};
        for (int i = 0; i <= degree; i++) newCoeffs[i] += coefficients[i];
        for (int i = 0; i <= other.degree; i++) newCoeffs[i] += other.coefficients[i];
        return Polynomial(maxDegree, newCoeffs);
    }
    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{};
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= other.degree; j++)
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
        return Polynomial(newDegree, newCoeffs);
    }
    void print() const {
        for (int i = degree; i >= 0; i--) {
            std::cout << coefficients[i] << "x^" << i;
            if (i > 0) std::cout << " + ";
        }
        std::cout << std::endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3};
    double coeffs2[] = {4, 5};
    Polynomial p1(2, coeffs1), p2(1, coeffs2);
    p1.print();
    p2.print();
    p1.add(p2).print();
    p1.multiply(p2).print();
    std::cout << p1.evaluate(2) << std::endl;
    return 0;
}

