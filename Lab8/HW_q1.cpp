#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v) : value(v) {}

    Number operator--() { 
        value *= 4;
        return *this;
    }

    Number operator--(int) { 
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const { cout << value << endl; }
};

int main() {
    Number n1(10);

    cout << "Initial value of n1: ";
    n1.display(); 

    
    --n1;
    cout << "After prefix decrement (--n1): ";
    n1.display(); 

    
    n1--;
    cout << "After postfix decrement (n1--): ";
    n1.display(); 

    return 0;
}
