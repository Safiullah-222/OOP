#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle r(5, 4);
    Triangle t(6, 3);

    cout << "Area of Rectangle: " << r.getArea() << endl;
    cout << "Area of Triangle: " << t.getArea() << endl;

    return 0;
}
