#include <iostream>
using namespace std;

class Employee {
public:
    string firstName, lastName;
    double salary;

    Employee(string fName, string lName, double sal) {
        firstName = fName;
        lastName = lName;
        salary = (sal > 0) ? sal : 0;
    }

    void showYearlySalary() {
        cout << firstName << " " << lastName << "'s yearly salary: $" << salary * 12 << endl;
    }

    void applyRaise() {
        salary *= 1.1; 
    }
};

int main() {
    string fName1, lName1, fName2, lName2;
    double salary1, salary2;

    cout << "Enter Employee 1 (First Last Salary): ";
    cin >> fName1 >> lName1 >> salary1;

    cout << "Enter Employee 2 (First Last Salary): ";
    cin >> fName2 >> lName2 >> salary2;

    Employee emp1(fName1, lName1, salary1);
    Employee emp2(fName2, lName2, salary2);

    cout << "\nBefore Raise:" << endl;
    emp1.showYearlySalary();
    emp2.showYearlySalary();

    emp1.applyRaise();
    emp2.applyRaise();

    cout << "\nAfter 10% Raise:" << endl;
    emp1.showYearlySalary();
    emp2.showYearlySalary();

    return 0;
}
