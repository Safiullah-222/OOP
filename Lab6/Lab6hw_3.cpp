#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string studentName, int roll) : name(studentName), rollNo(roll) {}
    virtual void displayDetails() {
        cout << "Student Name: " << name << ", Roll No: " << rollNo << endl;
    }
};


class Marks : public Student {
protected:
    int subject1, subject2, subject3;
public:
    Marks(string studentName, int roll, int sub1, int sub2, int sub3) 
        : Student(studentName, roll), subject1(sub1), subject2(sub2), subject3(sub3) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Marks - Subject 1: " << subject1 << ", Subject 2: " << subject2 
             << ", Subject 3: " << subject3 << endl;
    }
};


class Result : public Marks {
private:
    int totalMarks;
    double average;
public:
    Result(string studentName, int roll, int sub1, int sub2, int sub3) 
        : Marks(studentName, roll, sub1, sub2, sub3) {
        totalMarks = subject1 + subject2 + subject3;
        average = totalMarks / 3.0;
    }
    void displayDetails() override {
        Marks::displayDetails();
        cout << "Total Marks: " << totalMarks << ", Average: " << average << endl;
    }
};

int main() {
    
    Result student1("Ali", 101, 85, 90, 78);

    
    student1.displayDetails();

    return 0;
}
