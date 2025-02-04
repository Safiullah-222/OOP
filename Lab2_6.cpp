#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    int studentCount;
    cout << "Enter total number of students: ";
    cin >> studentCount;

    vector<Student> students(studentCount);

    for (int i = 0; i < studentCount; ++i) {
        cout << "Enter student ID for student " << i + 1 << ": ";
        cin >> students[i].id;

        int subjectCount;
        cout << "Enter number of subjects for student " << i + 1 << ": ";
        cin >> subjectCount;

        for (int j = 0; j < subjectCount; ++j) {
            Subject subject;
            cout << "Enter name of subject " << j + 1 << ": ";
            cin >> subject.name;
            students[i].subjects.push_back(subject);
        }
    }

    cout << "\nStudent Details:\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << endl;
    }

    return 0;
}
