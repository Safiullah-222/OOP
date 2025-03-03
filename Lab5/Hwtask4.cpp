#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class Student {
    const int roll_no;
public:
    Student(int roll) : roll_no(roll) {}
    void display() { cout << "Roll No: " << roll_no << endl; }
};

int main() {

    int roll;
    cout << "Enter roll number: ";
    cin >> roll;
    Student s(roll);
    s.display();
    
    return 0;
}