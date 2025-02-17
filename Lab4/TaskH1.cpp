#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() { return 3.14159 * radius * radius; }
    double getPerimeter() { return 2 * 3.14159 * radius; }
};
