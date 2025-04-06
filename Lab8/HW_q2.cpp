#include <iostream>
using namespace std;

class Shape {
    float area;
public:
    Shape(float a = 0) : area(a) {}

    float Area() const { return area; }

    Shape operator+(const Shape& s) const {
        return Shape(area + s.area);
    }

    void show() const { cout << "Area: " << area << endl; }
};

int main() {
    Shape s1(10.5), s2(20.3); 

    cout << "Shape 1: ";
    s1.show(); 

    cout << "Shape 2: ";
    s2.show(); 

    Shape s3 = s1 + s2; 

    cout << "Shape 3 (s1 + s2): ";
    s3.show(); 

    return 0;
}