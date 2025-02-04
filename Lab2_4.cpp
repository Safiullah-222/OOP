#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    float salary;
};

struct Organisation {
    string organisation_name;
    string organisation_number;
    Employee emp;
};