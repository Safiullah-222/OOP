class Person {
    protected:
        string name;
        string id;
        string email;
    
    public:
        Person(string n, string i, string e) : name(n), id(i), email(e) {}
    
        virtual void displayInfo() {
            cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << endl;
        }
    };
    
    class Student : public Person {
        vector<string> coursesEnrolled;
        double gpa;
        int enrollmentYear;
    
    public:
        Student(string n, string i, string e, double g, int year)
            : Person(n, i, e), gpa(g), enrollmentYear(year) {}
    
        void displayInfo() override {
            Person::displayInfo();
            cout << "GPA: " << gpa << "\nEnrolled since: " << enrollmentYear << endl;
            cout << "Courses: ";
            for (auto& course : coursesEnrolled) {
                cout << course << ", ";
            }
            cout << endl;
        }
    };
    
    class Professor : public Person {
        string department;
        double salary;
    
    public:
        Professor(string n, string i, string e, string dept, double sal)
            : Person(n, i, e), department(dept), salary(sal) {}
    
        void displayInfo() override {
            Person::displayInfo();
            cout << "Department: " << department << "\nSalary: $" << salary << endl;
        }
    };
    
    class Course {
        string courseId;
        string courseName;
        Professor* instructor;
    
    public:
        Course(string id, string name, Professor* prof)
            : courseId(id), courseName(name), instructor(prof) {}
    
        void displayInfo() {
            cout << courseId << ": " << courseName << endl;
            cout << "Instructor: ";
            instructor->displayInfo();
        }
    };